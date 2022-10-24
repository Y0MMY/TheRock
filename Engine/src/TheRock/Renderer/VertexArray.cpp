#include "pch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "TheRock/Platform/OpenGL/OpenGLVertexArray.h"

namespace RockEngine {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    RE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexArray>();
		}

		RE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

}
