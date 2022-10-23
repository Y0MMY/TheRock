#pragma once

#include "TheRock/Core/Base.h"

#include "TheRock/Core/Buffer.h"

#include "TheRock/Renderer/Renderer.h"

namespace RockEngine
{
	enum class TextureFormat
	{
		None = 0,
		RGB = 1,
		RGBA = 2,
	};

	enum class TextureWrap
	{
		None = 0,
		Clamp = 1,
		Repeat = 2
	};

	class Texture
	{
	public:
		virtual ~Texture(){}

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual RendererID GetRendererID() const = 0;

		static uint32_t GetBPP(TextureFormat format);
	};

	class Texture2D : public Texture 
	{
	public:
		static Texture2D* Create(TextureFormat format, u32 width, u32 height, TextureWrap wrap = TextureWrap::Clamp);
		static Texture2D* Create(const std::string& path, bool srgb = false);

		virtual TextureFormat GetFormat() const = 0;
		virtual u32 GetWidth() const = 0;
		virtual u32 GetHeight() const = 0;

		virtual void Lock() = 0;
		virtual void Unlock() = 0;

		virtual void Resize(u32 width, u32 height) = 0;
		virtual Buffer GetWriteableBuffer() = 0;

		virtual const std::string& GetPath() const = 0;
	};

	class TextureCube : public Texture
	{
	public:
		static TextureCube* Create(const std::string& path);

		virtual TextureFormat GetFormat() const = 0;
		virtual u32 GetWidth() const = 0;
		virtual u32 GetHeight() const = 0;

		virtual const std::string& GetPath() const = 0;
	};

}