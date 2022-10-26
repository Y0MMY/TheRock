#pragma once

#include "TheRock/Scene/Scene.h"

#include "RenderPass.h"

namespace RockEngine
{
	struct SceneRendererOptions
	{
		bool ShowGrid = true;
		bool ShowBoundingBoxes = false;
	};


	class SceneRenderer
	{
	public:
		static void Init();

		static void SetViewportSize(u32 width, u32 height);

		static void BeginScene(const Scene* scene);
		static void EndScene();

		static void SubmitEntity(Entity* entity);

		static std::pair<Ref<TextureCube>, Ref<TextureCube>> CreateEnvironmentMap(const std::string& filepath);

		static Ref<RenderPass> GetFinalRenderPass();
		static Ref<Texture2D> GetFinalColorBuffer();

		// TODO: Temp
		static uint32_t GetFinalColorBufferRendererID();

		static SceneRendererOptions& GetOptions();
	private:
		static void FlushDrawList();
		static void GeometryPass();
		static void CompositePass();
	};
}