#pragma once

#include "TheRock/Core/Base.h"
#include "TheRock/Renderer/Renderer.h"

namespace RockEngine
{
	enum class TextureFormat
	{
		None = 0,
		RGB = 1,
		RGBA = 2,
	};

	class Texture
	{
	public:
		virtual ~Texture(){}
		virtual RendererID GetRendererID() const = 0;

	};

	class Texture2D : public Texture 
	{
	public:
		static Texture2D* Create(TextureFormat format, u32 width, u32 height);
		static Texture2D* Create(const std::string& path, bool srgb = false);

		virtual void Bind(unsigned int slot = 0) const = 0;

		virtual TextureFormat GetFormat() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual const std::string& GetPath() const = 0;
	};

	class TextureCube : public Texture
	{
	public:
		static TextureCube* Create(const std::string& path);

		virtual void Bind(unsigned int slot = 0) = 0;

		virtual TextureFormat GetFormat() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual const std::string& GetPath() const = 0;
	};

}