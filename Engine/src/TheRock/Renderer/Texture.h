#pragma once

#include "TheRock/Core/Base.h"

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
	};

	class Texture2D : public Texture 
	{
	public:
		static Texture2D* Create(TextureFormat format, u32 width, u32 height);

		virtual TextureFormat GetFormat() const = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

	};
}