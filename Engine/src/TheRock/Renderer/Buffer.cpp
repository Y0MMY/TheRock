#include "pch.h"

#include "Renderer.h"

#include "TheRock/Platform/OpenGL/OpenGLBuffer.h"

namespace RockEngine
{
	
	Ref<VertexBuffer> VertexBuffer::Create(void* data, uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexBuffer>(data, size, usage);
		}
		RE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexBuffer>(size, usage);
		}
		RE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;
	}
	
	Ref<IndexBuffer> IndexBuffer::Create(void* data, uint32_t size)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:    return nullptr;
			case RendererAPIType::OpenGL:  return std::make_shared<OpenGLIndexBuffer>(data, size);
		}
		RE_CORE_ASSERT(false, "Unknown RendererAPI");
		return nullptr;

	}


}