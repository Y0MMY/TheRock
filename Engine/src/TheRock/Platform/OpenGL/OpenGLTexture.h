#pragma once

#include "TheRock/Renderer/Texture.h"
#include "TheRock/Renderer/RendererAPI.h"
#include "TheRock/Renderer/Renderer.h"

#include <Glad/glad.h>

namespace RockEngine
{
	static GLenum OpenGLTextureFormat(TextureFormat format)
	{
		switch (format)
		{
			case TextureFormat::RGB:	return GL_RGB;
			case TextureFormat::RGBA:	return GL_RGBA;
		}
		return (int)TextureFormat::None;
	}

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(TextureFormat format, u32 width, u32 height);
		virtual ~OpenGLTexture2D() override;
		
		virtual TextureFormat GetFormat() const { return m_Format; }
		virtual unsigned int GetWidth() const { return m_Width; }
		virtual unsigned int GetHeight() const { return m_Height; }
	private:
		RendererID m_RendererID;
		TextureFormat m_Format;
		u32 m_Width, m_Height;
	};
}