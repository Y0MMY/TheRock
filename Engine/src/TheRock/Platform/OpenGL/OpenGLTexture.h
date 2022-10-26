#pragma once

#include "TheRock/Renderer/Texture.h"
#include "TheRock/Renderer/RendererAPI.h"
#include "TheRock/Renderer/Renderer.h"

#include <Glad/glad.h>

namespace RockEngine
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(TextureFormat format, u32 width, u32 height, TextureWrap wrap);
		OpenGLTexture2D(const std::string& path, bool srgb);
		virtual ~OpenGLTexture2D() override;
		
		virtual void Bind(u32 slot = 0) const override;

		virtual TextureFormat GetFormat() const { return m_Format; }
		virtual u32 GetWidth() const { return m_Width; }
		virtual u32 GetHeight() const { return m_Height; }

		// This function currently returns the expected number of mips based on image size,
		// not present mips in data
		virtual uint32_t GetMipLevelCount() const override;

		virtual RendererID GetRendererID() const override { return m_RendererID; }

		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == ((OpenGLTexture2D&)other).m_RendererID;
		}

		virtual bool Loaded() const override { return m_Loaded; }

		virtual void Lock() override;
		virtual void Unlock() override;

		virtual void Resize(uint32_t width, uint32_t height) override;
		virtual Buffer GetWriteableBuffer() override;

		virtual const std::string& GetPath() const override { return m_FilePath; }
	private:
		RendererID m_RendererID;
		TextureFormat m_Format;
		u32 m_Width, m_Height;
		TextureWrap m_Wrap = TextureWrap::Clamp;

		bool m_IsHDR = false;

		bool m_Locked = false;
		bool m_Loaded = false;

		Buffer m_ImageData;

		std::string m_FilePath;
	};

	class OpenGLTextureCube : public TextureCube
	{
	public:
		OpenGLTextureCube(TextureFormat format, uint32_t width, uint32_t height);
		OpenGLTextureCube(const std::string& path);
		virtual ~OpenGLTextureCube();

		virtual void Bind(u32 slot = 0) const override;

		virtual TextureFormat GetFormat() const { return m_Format; }
		virtual unsigned int GetWidth() const { return m_Width; }
		virtual unsigned int GetHeight() const { return m_Height; }

		// This function currently returns the expected number of mips based on image size,
		// not present mips in data
		virtual uint32_t GetMipLevelCount() const override;

		virtual const std::string& GetPath() const override { return m_FilePath; }

		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == ((OpenGLTextureCube&)other).m_RendererID;
		}

		virtual RendererID GetRendererID() const override { return m_RendererID; }

	private:
		RendererID m_RendererID;
		TextureFormat m_Format;
		unsigned int m_Width, m_Height;

		unsigned char* m_ImageData;

		std::string m_FilePath;

	};
}