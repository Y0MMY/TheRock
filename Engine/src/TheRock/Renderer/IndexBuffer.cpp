#include "pch.h"
#include "IndexBuffer.h"

#include "TheRock/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace RockEngine
{
	IndexBuffer* IndexBuffer::Create(u32 size /*= 0*/)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None: return nullptr;
			case RendererAPIType::OpenGL:  return new OpenGLIndexBuffer(size);
		}
		RE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}