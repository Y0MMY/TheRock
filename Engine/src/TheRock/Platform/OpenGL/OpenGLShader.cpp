#include "pch.h"
#include "OpenGLShader.h"

#include <sstream>
#include <limits>

namespace RockEngine
{
	GLenum OpenGLShader::ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;
		return GL_NONE;
	}


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
		std::unordered_map<GLenum, std::string> shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = m_ShaderSource.find(typeToken, 0);

		while (pos != std::string::npos)
		{
			size_t eol = m_ShaderSource.find_first_of("\r\n", pos);
			RE_CORE_ASSERT(eol != std::string::npos, "Syntax error");
			size_t begin = pos + typeTokenLength + 1;
			std::string type = m_ShaderSource.substr(begin, eol - begin);
			RE_CORE_ASSERT(type == "vertex" || type == "fragment" || type == "pixel", "Invalid shader type specified");

			size_t nextLinePos = m_ShaderSource.find_first_not_of("\r\n", eol);
			pos = m_ShaderSource.find(typeToken, nextLinePos);

			shaderSources[ShaderTypeFromString(type)] = m_ShaderSource.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? m_ShaderSource.size() - 1 : nextLinePos));
		}
		std::vector<GLuint> shaderRendererIDs;

		GLuint program = glCreateProgram();
		for (auto& kv : shaderSources)
		{
			GLenum type = kv.first;
			std::string& source = kv.second;

			GLuint shaderRendererID = glCreateShader(type);
			const GLchar* sourceCstr = source.c_str();
			glShaderSource(shaderRendererID, 1, &sourceCstr, NULL);

			glCompileShader(shaderRendererID);

			GLint isCompiled;
			glGetShaderiv(shaderRendererID, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shaderRendererID, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shaderRendererID, maxLength, &maxLength, infoLog.data());

				RE_CORE_ERROR("Shader compilation failed:\n{0}", &infoLog[0]);

				// We don't need the shader anymore.
				glDeleteShader(shaderRendererID);
				
				RE_CORE_ASSERT(false, "Failed");
			}

			shaderRendererIDs.push_back(shaderRendererID);
			glAttachShader(program, shaderRendererID);
		}

		glLinkProgram(program);
		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
			RE_CORE_ERROR("Shader compilation failed:\n{0}", &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			for (auto id : shaderRendererIDs)
				glDeleteShader(id);
		}
		
		for (auto id : shaderRendererIDs)
			glDetachShader(program,id);

		for (auto id : shaderRendererIDs)
			glDeleteShader(id);

		m_RendererID = program;
	}


}