#include "pch.h"
#include "VertexBuffer.h"

#include "TheRock/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace RockEngine
{
	VertexBuffer* VertexBuffer::Create(u32 size /*= 0*/)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPIType::None:		return nullptr;
		case RendererAPIType::OpenGL:	return new OpenGLVertexBuffer(size);
		}
		RE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}