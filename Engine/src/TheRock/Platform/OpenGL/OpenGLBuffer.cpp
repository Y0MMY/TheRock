#include "pch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace RockEngine
{
	//////////////////////////////////////////////////////////////////////////////////
	// IndexBuffer
	//////////////////////////////////////////////////////////////////////////////////


	OpenGLIndexBuffer::OpenGLIndexBuffer(u32 size)
		:m_RendererID(0),m_Size(size)
	{
		Renderer::Submit([this]()
			{
				glGenBuffers(1, &m_RendererID);
			});
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		Renderer::Submit([=]() mutable
			{
				glDeleteBuffers(1, &m_RendererID);
			});
	}

	void OpenGLIndexBuffer::SetData(void* data, u32 size, u32 offset /*= 0*/)
	{
		m_LocalData = data;
		m_Size = size;
		Renderer::Submit([=]() mutable
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
			});

	}

	void OpenGLIndexBuffer::Bind() const
	{
		Renderer::Submit([=]() mutable
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
			});
	}

	//////////////////////////////////////////////////////////////////////////////////
	// VertexBuffer
	//////////////////////////////////////////////////////////////////////////////////


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
		m_Size = size;
		m_LocalData = data;
		Renderer::Submit([=]()
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
			});
	}

	void OpenGLVertexBuffer::Bind() const
	{
		Renderer::Submit([this]()
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
				// TODO: Extremely temp, by default provide positions and texcoord attributes
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);

				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (const void*)(3 * sizeof(float)));

			});
	}
}