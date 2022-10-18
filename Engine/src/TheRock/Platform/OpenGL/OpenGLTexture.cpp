#include "pch.h"
#include "OpenGLTexture.h"

namespace RockEngine
{

	OpenGLTexture2D::OpenGLTexture2D(TextureFormat format, u32 width, u32 height)
		: m_Format(format), m_Width(width), m_Height(height)
	{
		Renderer::Submit([=]()
			{
				glGenTextures(1, &m_RendererID);
				glBindTexture(GL_TEXTURE_2D, m_RendererID);
				glTexImage2D(GL_TEXTURE_2D, 0, OpenGLTextureFormat(m_Format), m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
				glBindTexture(GL_TEXTURE_2D, 0);
			});
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		Renderer::Submit([=]()
			{
				glDeleteTextures(1, &m_RendererID);
			});
	}

}