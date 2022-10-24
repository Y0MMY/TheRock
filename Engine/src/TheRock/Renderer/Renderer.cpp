#include "pch.h"
#include "Renderer.h"

#include "Shader.h"

#include <glad/glad.h>


namespace RockEngine {

	RendererAPIType RendererAPI::s_CurrentRendererAPI = RendererAPIType::OpenGL;

	struct RendererData
	{
		Ref<RenderPass> m_ActiveRenderPass;
		RenderCommandQueue m_CommandQueue;
		Ref<ShaderLibrary> m_ShaderLibrary;
	};

	static RendererData s_Data;

	void Renderer::Init()
	{
		s_Data.m_ShaderLibrary = std::make_shared<ShaderLibrary>();
		Renderer::Submit([=]() mutable
			{
				RendererAPI::Init();
			});

		Renderer::GetShaderLibrary()->Load("assets/shaders/HazelPBR_Static.glsl");
		Renderer::GetShaderLibrary()->Load("assets/shaders/HazelPBR_Anim.glsl");

	}


	const Ref<ShaderLibrary>& Renderer::GetShaderLibrary()
	{
		return s_Data.m_ShaderLibrary;
	}

	void Renderer::BeginRenderPass(const Ref<RenderPass>& renderPass)
	{
		// TODO: Convert all of this into a render command buffer
		s_Data.m_ActiveRenderPass = renderPass;

		renderPass->GetSpecification().TargetFramebuffer->Bind();
		const glm::vec4& clearColor = renderPass->GetSpecification().TargetFramebuffer->GetSpecification().ClearColor;
		Renderer::Submit([=]() {
			RendererAPI::Clear(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
			});

	}

	void Renderer::SubmitMesh(const Ref<Mesh>& mesh, const glm::mat4& transform, const Ref<MaterialInstance>& overrideMaterial)
	{
		if (overrideMaterial)
		{
			overrideMaterial->Bind();
		}
		else
		{
			// Bind mesh material here
		}

		// TODO: Sort this out
		mesh->m_VertexArray->Bind();

		// TODO: replace with render API calls
		Renderer::Submit([=]()
			{
				for (Submesh& submesh : mesh->m_Submeshes)
				{
					if (mesh->m_IsAnimated)
					{
						for (size_t i = 0; i < mesh->m_BoneTransforms.size(); i++)
						{
							std::string uniformName = std::string("u_BoneTransforms[") + std::to_string(i) + std::string("]");
							mesh->m_MeshShader->SetMat4FromRenderThread(uniformName, mesh->m_BoneTransforms[i]);
						}
					}

					glDrawElementsBaseVertex(GL_TRIANGLES, submesh.IndexCount, GL_UNSIGNED_INT, (void*)(sizeof(uint32_t) * submesh.BaseIndex), submesh.BaseVertex);
				}
			});
	}

	void Renderer::EndRenderPass()
	{
		RE_CORE_ASSERT(s_Data.m_ActiveRenderPass, "No active render pass! Have you called Renderer::EndRenderPass twice?");
		s_Data.m_ActiveRenderPass->GetSpecification().TargetFramebuffer->Unbind();
		s_Data.m_ActiveRenderPass = nullptr;

	}

	void Renderer::DrawIndexed(u32 count, bool depthTest)
	{
		Renderer::Submit([=]()
			{
				RendererAPI::DrawIndexed(count, depthTest);
			});
	}

	void Renderer::Clear()
	{
		Renderer::Submit([=]()
			{
				RendererAPI::Clear(0.0f, 0.0f, 0.0f, 1.0f);
			});
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		Renderer::Submit([=]()
			{
				RendererAPI::Clear(r, g, b, a);
			});
	}

	void Renderer::ClearMagenta()
	{
		Clear(1, 0, 1);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
		// HZ_RENDER(SetClearColor(r, g, b, a));
	}

	void Renderer::WaitAndRender()
	{
		s_Data.m_CommandQueue.Execute();
	}

	RenderCommandQueue& Renderer::GetRenderCommandQueue()
	{
		return s_Data.m_CommandQueue;
	}

}
