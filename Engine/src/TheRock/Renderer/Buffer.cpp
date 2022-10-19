#include "pch.h"
#include "Buffer.h"

#include "TheRock/Platform/OpenGL/OpenGLBuffer.h"
#include "TheRock/Platform/OpenGL/OpenGLBuffer.h"

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