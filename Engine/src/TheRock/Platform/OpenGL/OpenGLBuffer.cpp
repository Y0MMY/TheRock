#include "pch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

#include "TheRock/Renderer/Renderer.h"

namespace RockEngine
{
	//////////////////////////////////////////////////////////////////////////////////
	// IndexBuffer
	//////////////////////////////////////////////////////////////////////////////////


	static GLenum OpenGLUsage(VertexBufferUsage usage)
	{
		switch (usage)
		{
			case VertexBufferUsage::Static:    return GL_STATIC_DRAW;
			case VertexBufferUsage::Dynamic:   return GL_DYNAMIC_DRAW;
		}
		RE_CORE_ASSERT(false, "Unknown vertex buffer usage");
		return 0;
	}


	//////////////////////////////////////////////////////////////////////////////////
	// VertexBuffer
	//////////////////////////////////////////////////////////////////////////////////

	OpenGLVertexBuffer::OpenGLVertexBuffer(void* data, uint32_t size, VertexBufferUsage usage)
		: m_Size(size), m_Usage(usage)
	{
		m_LocalData = Buffer::Copy(data, size);

		Renderer::Submit([this]() {
			glCreateBuffers(1, &m_RendererID);
			glNamedBufferData(m_RendererID, m_Size, m_LocalData.Data, OpenGLUsage(m_Usage));
			});
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, VertexBufferUsage usage)
		: m_Size(size), m_Usage(usage)
	{
		Renderer::Submit([this]() {
			glCreateBuffers(1, &m_RendererID);
			glNamedBufferData(m_RendererID, m_Size, nullptr, OpenGLUsage(m_Usage));
			});
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		Renderer::Submit([this]() {
			glDeleteBuffers(1, &m_RendererID);
			});
	}

	void OpenGLVertexBuffer::SetData(void* data, uint32_t size, uint32_t offset)
	{
		m_LocalData = Buffer::Copy(data, size);
		m_Size = size;
		Renderer::Submit([=]() {
			glNamedBufferSubData(m_RendererID, offset, m_Size, m_LocalData.Data);
			});
	}

	void OpenGLVertexBuffer::Bind() const
	{
		Renderer::Submit([=]() {
			glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
			});
	}

	//////////////////////////////////////////////////////////////////////////////////
	// IndexBuffer
	//////////////////////////////////////////////////////////////////////////////////

	OpenGLIndexBuffer::OpenGLIndexBuffer(void* data, uint32_t size)
		: m_RendererID(0), m_Size(size)
	{
		m_LocalData = Buffer::Copy(data, size);

		Renderer::Submit([this]() {
			glCreateBuffers(1, &m_RendererID);
			glNamedBufferData(m_RendererID, m_Size, m_LocalData.Data, GL_STATIC_DRAW);
			});
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		Renderer::Submit([this]() {
			glDeleteBuffers(1, &m_RendererID);
			});
	}

	void OpenGLIndexBuffer::SetData(void* data, uint32_t size, uint32_t offset)
	{
		m_LocalData = Buffer::Copy(data, size);
		m_Size = size;
		Renderer::Submit([this, offset]() {
			glNamedBufferSubData(m_RendererID, offset, m_Size, m_LocalData.Data);
			});
	}

	void OpenGLIndexBuffer::Bind() const
	{
		Renderer::Submit([=]() {
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
			});
	}


}