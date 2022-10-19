#pragma once

#include "TheRock/Renderer/Shader.h"

#include <Glad/glad.h>

namespace RockEngine
{

	enum class ShaderType
	{
		None = 0,
		Vertex = 1,

		// Fragment and Pixel shaders are the same
		Fragment = 2,
		Pixel = 2,
	};

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string filepath);

		virtual void Bind() const override;
	private:
		void ReadShaderFromFile(const std::string& filepath);
		void CompileAndUploadShader();

		static GLenum ShaderTypeFromString(const std::string& type);
	private:
		RendererID m_RendererID;
		std::string m_ShaderSource;
	}; 
}