#include "pch.h"
#include "Texture.h"

#include "TheRock/Renderer/RendererAPI.h"
#include "TheRock/Platform/OpenGL/OpenGLTexture.h"

namespace RockEngine
{

		Texture2D* Texture2D::Create(TextureFormat format, u32 width, u32 height)
		{
			switch (RendererAPI::Current())
			{
				case RendererAPIType::None:		return nullptr;
				case RendererAPIType::OpenGL:	return new OpenGLTexture2D(format, width, height);
			}
			return nullptr;
	}

}