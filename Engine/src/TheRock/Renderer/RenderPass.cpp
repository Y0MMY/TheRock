#include "pch.h"
#include "RenderPass.h"

#include "Renderer.h"

#include "TheRock/Platform/OpenGL/OpenGLRenderPass.h"

namespace RockEngine {

	Ref<RenderPass> RenderPass::Create(const RenderPassSpecification& spec)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    RE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::OpenGL:  return std::make_shared<OpenGLRenderPass>(spec);
		}

		RE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
