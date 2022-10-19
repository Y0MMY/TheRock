#include "pch.h"
#include "OpenGLShader.h"

#include <sstream>
#include <limits>

#include <Glad/glad.h>

namespace RockEngine
{

	OpenGLShader::OpenGLShader(const std::string filepath)
	{
		ReadShaderFromFile(filepath);
		CompileAndUploadShader();
	}

	void OpenGLShader::Bind() const
	{
		Renderer::Submit([=]()
			{
				glUseProgram(m_RendererID);
			});
	}

	void OpenGLShader::ReadShaderFromFile(const std::string& filepath)
	{
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			m_ShaderSource.resize(in.tellg());
			in.seekg(std::ios::beg);
			in.read(&m_ShaderSource[0],m_ShaderSource.size());
		}
		else
		{
			RE_CORE_ASSERT(false, "Could not open file!");
			//RE_CORE_WARN("Could not read shader file {0}", filepath);
		}
		in.close();
	}

	void OpenGLShader::CompileAndUploadShader()
	{
		std::istringstream ss(m_ShaderSource);
		std::string token;
		while (ss >> token)
		{
			if (token == "#type")
			{
				std::string type;
				ss >> type;
				RE_CORE_INFO("Type: {0}", type);
			}
			printf("%s \n", token.c_str());
		}

		std::array<size_t, 4> typePositions;
		typePositions.fill(std::string::npos);
		u32 typePositionIndex = 0;
		const char* typeToken = "#type";
		size_t pos = m_ShaderSource.find(typeToken, 0);

		while (pos != std::string::npos)
		{
			size_t eol = m_ShaderSource.find('\n', pos);
			RE_CORE_ASSERT(eol != std::string::npos, "Syntax error");
			std::string type = m_ShaderSource.substr(pos, eol);

			typePositions[typePositionIndex++] = pos;
			pos = m_ShaderSource.find(typeToken, pos + 1);

		}
	}

}