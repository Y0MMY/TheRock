#pragma once

#include "TheRock/Renderer/ShaderUniform.h"

namespace RockEngine
{
	class OpenGLShaderResourceDeclaration : public ShaderResourceDeclaration
	{
	public:
		enum class Type
		{
			NONE, TEXTURE2D, TEXTURECUBE
		};
	private:
		friend class OpenGLShader;
	private:
		std::string m_Name;
		uint32_t m_Register = 0;
		uint32_t m_Count;
		Type m_Type;
	public:
		OpenGLShaderResourceDeclaration(Type type, const std::string& name, u32 count);

		inline const std::string& GetName() const override { return m_Name; }
		inline uint32_t GetRegister() const override { return m_Register; }
		inline uint32_t GetCount() const override { return m_Count; }

		inline Type GetType() const { return m_Type; }
	public:
		static Type StringToType(const std::string& type);
		static std::string TypeToString(Type type);
	};

	class OpenGLShaderUniformDeclaration : public ShaderUniformDeclaration
	{
	private:
		friend class OpenGLShader;
		friend class OpenGLShaderUniformBufferDeclaration;
	public:
		enum class Type
		{
			NONE, FLOAT32, VEC2, VEC3, VEC4, MAT3, MAT4, INT32, STRUCT
		};
	private:
		std::string m_Name;
		u32 m_Size;
		u32 m_Count;
		u32 m_Offset;
		ShaderDomain m_Domain;

		Type m_Type;
		ShaderStruct* m_Struct;
		mutable i32 m_Location;
	public:
		OpenGLShaderUniformDeclaration(ShaderDomain domain, Type type, const std::string& name, u32 count = 1);
		OpenGLShaderUniformDeclaration(ShaderDomain domain, ShaderStruct* uniformStruct, const std::string& name, uint32_t count = 1);

		inline const std::string& GetName() const override { return m_Name; }
		inline uint32_t GetSize() const override { return m_Size; }
		inline uint32_t GetCount() const override { return m_Count; }
		inline uint32_t GetOffset() const override { return m_Offset; }
		inline uint32_t GetAbsoluteOffset() const { return m_Struct ? m_Struct->GetOffset() + m_Offset : m_Offset; }

		inline ShaderDomain GetDomain() const { return m_Domain; }
		int32_t GetLocation() const { return m_Location; }
		inline Type GetType() const { return m_Type; }
		inline bool IsArray() const { return m_Count > 1; }
		inline const ShaderStruct& GetShaderUniformStruct() const { RE_CORE_ASSERT(m_Struct, ""); return *m_Struct; }
	protected:
		void SetOffset(uint32_t offset) override;
	public:
		static uint32_t SizeOfUniformType(Type type);
		static Type StringToType(const std::string& type);
		static std::string TypeToString(Type type);
	};

	struct GLShaderUniformField
	{
		OpenGLShaderUniformDeclaration::Type type;
		std::string name;
		u32 count;
		mutable i32 location;
		mutable u32 size;
	};

	class OpenGLShaderUniformBufferDeclaration : public ShaderUniformBufferDeclaration
	{
	private:
		friend class Shader;
	public:
		OpenGLShaderUniformBufferDeclaration(const std::string& name, ShaderDomain domain);
		void PushUniform(OpenGLShaderUniformDeclaration* uniform);

		inline const std::string& GetName() const override { return m_Name; }
		inline uint32_t GetRegister() const override { return m_Register; }
		inline uint32_t GetSize() const override { return m_Size; }
		virtual ShaderDomain GetDomain() const { return m_Domain; }
		inline const ShaderUniformList& GetUniformDeclarations() const override { return m_Uniforms; }

		ShaderUniformDeclaration* FindUniform(const std::string& name);
	private:
		std::string m_Name;
		ShaderUniformList m_Uniforms;
		u32 m_Register;
		u32 m_Size;
		ShaderDomain m_Domain;
	};
}