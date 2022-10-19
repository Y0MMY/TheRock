#pragma once

#include "TheRock/Renderer/Shader.h"

namespace RockEngine
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string filepath);

		virtual void Bind() const override;
	private:
		void ReadShaderFromFile(const std::string& filepath);
		void CompileAndUploadShader();
	private:
		RendererID m_RendererID;
		std::string m_ShaderSource;
	};
}