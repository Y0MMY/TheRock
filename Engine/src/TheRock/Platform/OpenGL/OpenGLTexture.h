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
		OpenGLTexture2D(const std::string& path, bool srgb);
		virtual ~OpenGLTexture2D() override;
		
		virtual void Bind(u32 slot = 0) const override;

		virtual TextureFormat GetFormat() const { return m_Format; }
		virtual unsigned int GetWidth() const { return m_Width; }
		virtual unsigned int GetHeight() const { return m_Height; }

		virtual const std::string& GetPath() const override { return m_FilePath; }

		virtual RendererID GetRendererID() const override { return m_RendererID; }
	private:
		RendererID m_RendererID;
		TextureFormat m_Format;
		u32 m_Width, m_Height;

		byte* m_ImageData;

		std::string m_FilePath;
	};

	class OpenGLTextureCube : public TextureCube
	{
	public:
		OpenGLTextureCube(const std::string& path);
		virtual ~OpenGLTextureCube();

		virtual void Bind(unsigned int slot = 0);

		virtual TextureFormat GetFormat() const { return m_Format; }
		virtual unsigned int GetWidth() const { return m_Width; }
		virtual unsigned int GetHeight() const { return m_Height; }

		virtual const std::string& GetPath() const override { return m_FilePath; }

		virtual RendererID GetRendererID() const override { return m_RendererID; }

	private:
		RendererID m_RendererID;
		TextureFormat m_Format;
		unsigned int m_Width, m_Height;

		unsigned char* m_ImageData;

		std::string m_FilePath;

	};
}