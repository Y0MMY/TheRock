#include "pch.h"
#include "Shader.h"

#include "TheRock/Platform/OpenGL/OpenGLShader.h"

namespace RockEngine
{
	Shader* Shader::Create(const std::string& filepath)
	{
		switch (RendererAPI::Current())
		{
			case RendererAPIType::None:		return nullptr;
			case RendererAPIType::OpenGL:	return new OpenGLShader(filepath);
		}
		return nullptr;

	}
}