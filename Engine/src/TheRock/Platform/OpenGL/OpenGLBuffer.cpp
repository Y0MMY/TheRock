#include "pch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace RockEngine
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(u32 size)
		:m_RendererID(0),m_Size(size)
	{
		Renderer::Submit([this]() mutable
			{
				glGenBuffers(1, &m_RendererID);
			});
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		Renderer::Submit([this]() mutable
			{
				glDeleteBuffers(1, &m_RendererID);
			});
	}

	void OpenGLIndexBuffer::SetData(void* data, u32 size, u32 offset /*= 0*/)
	{
		
		Renderer::Submit([=]() mutable
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
			});

	}

	void OpenGLIndexBuffer::Bind() const
	{
		Renderer::Submit([this]() mutable
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
			});
	}


	OpenGLVertexBuffer::OpenGLVertexBuffer(u32 size)
		: m_Size(size), m_RendererID(0)
	{
		Renderer::Submit([this]() {
			glGenBuffers(1, &m_RendererID);
			});

	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		Renderer::Submit([this]()
			{
				glDeleteBuffers(1, &m_RendererID);
			});
	}

	void OpenGLVertexBuffer::SetData(void* data, u32 size, u32 offset /*= 0*/)
	{
		Renderer::Submit([=]()
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
			});
	}

	void OpenGLVertexBuffer::Bind() const
	{
		Renderer::Submit([this]()
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
			});
	}
}