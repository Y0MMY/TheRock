#include "pch.h"
#include "Renderer.h"
#include "Shader.h"

namespace RockEngine {

	RendererAPIType RendererAPI::s_CurrentRendererAPI = RendererAPIType::OpenGL;

	struct RendererData
	{
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
