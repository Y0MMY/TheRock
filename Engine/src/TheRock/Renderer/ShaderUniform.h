#pragma once

#include "TheRock/Core/Base.h"
#include "TheRock/Core/Log.h"

#include <string>
#include <vector>

namespace RockEngine
{
	enum class ShaderDomain
	{
		None = 0,
		Vertex = 0,
		Pixel = 1
	};

	class ShaderUniformDeclaration
	{
	public:
		virtual const std::string& GetName() const = 0;
		virtual u32 GetSize() const = 0;
		virtual u32 GetCount() const = 0;
		virtual u32 GetOffset() const = 0;
		virtual ShaderDomain GetDomain() const = 0;
	protected:
		virtual void SetOffset(uint32_t offset) = 0;
	private:
		friend class Shader;
		friend class OpenGLShader;
		friend class ShaderStruct;
	};
	typedef std::vector<ShaderUniformDeclaration*> ShaderUniformList;

	class ShaderUniformBufferDeclaration
	{
	public:
		virtual const std::string& GetName() const = 0;
		virtual u32 GetRegister() const = 0;
		virtual u32 GetSize() const = 0;
		virtual const ShaderUniformList& GetUniformDeclarations() const = 0;

		virtual ShaderUniformDeclaration* FindUniform(const std::string& name) = 0;
	};

	typedef std::vector<ShaderUniformBufferDeclaration*> ShaderUniformBufferList;

	class ShaderStruct
	{
		friend class Shader;
	public:
		ShaderStruct(const std::string& name)
			: m_Name(name), m_Size(0), m_Offset(0)
		{}

		void AddField(ShaderUniformDeclaration* field)
		{
			m_Size += field->GetSize();
			u32 offset = 0;
			if (m_Fields.size())
			{
				ShaderUniformDeclaration* prev = m_Fields.back();
				offset = prev->GetOffset() + prev->GetSize();
			}
			field->SetOffset(offset);
			m_Fields.push_back(field);
		}

		inline void SetOffset(u32 offset) { m_Offset = offset; }

		inline const std::string& GetName() const { return m_Name; }
		inline uint32_t GetSize() const { return m_Size; }
		inline uint32_t GetOffset() const { return m_Offset; }
		inline const ShaderUniformList& GetFields() const { return m_Fields; }

	private:
		std::string m_Name;
		ShaderUniformList m_Fields;
		u32 m_Size, m_Offset;
	};

	typedef std::vector<ShaderStruct*> ShaderStructList;

	class ShaderResourceDeclaration
	{
	public:
		virtual const std::string& GetName() const = 0;
		virtual u32 GetCount() const = 0;
		virtual u32 GetRegister() const = 0;
	};
	typedef std::vector<ShaderResourceDeclaration*> ShaderResourceList;
}