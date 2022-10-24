#pragma once

#include "RenderCommandQueue.h"
#include "RendererAPI.h"
#include "RenderPass.h"

#include "Mesh.h"

namespace RockEngine
{
	class ShaderLibrary;

	class Renderer
	{
	public:
		// Commands
		static void Clear();
		static void Clear(float r, float g, float b, float a = 1.0f);
		static void SetClearColor(float r, float g, float b, float a);

		static void ClearMagenta();
		static void Init();

		static const Ref<ShaderLibrary>& GetShaderLibrary();

		template<typename FuncT>
		static void Submit(FuncT&& func)
		{
			auto renderCmd = [](void* ptr)
			{
				auto pFunc = (FuncT*)ptr;
				(*pFunc)();

				// NOTE: Instead of destroying we could try and enforce all items to be trivally destructible
				// however some items like uniforms which contain std::strings still exist for now
				// static_assert(std::is_trivially_destructible_v<FuncT>, "FuncT must be trivially destructible");
				pFunc->~FuncT();
			};
			auto storageBuffer = GetRenderCommandQueue().Allocate(renderCmd, sizeof(func));
			new (storageBuffer) FuncT(std::forward<FuncT>(func));
		}

		// ~Actual~ Renderer here... TODO: remove confusion later
		static void BeginRenderPass(const Ref<RenderPass>& renderPass);
		static void EndRenderPass();
		void SubmitMesh(const Ref<Mesh>& mesh, const glm::mat4& transform, const Ref<MaterialInstance>& overrideMaterial);

		static void WaitAndRender();
		static void DrawIndexed(u32 count, bool depthTest = true);
	private:
		static RenderCommandQueue& GetRenderCommandQueue();
	};
#define RE_RENDER(x) ::RockEngine::Renderer::Submit([=](){ RendererAPI::x; })
}
