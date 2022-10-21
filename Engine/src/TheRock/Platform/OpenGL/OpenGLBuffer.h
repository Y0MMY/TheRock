#pragma once

#include "TheRock/Renderer/Buffer.h"
#include <TheRock/Core/Buffer.h>

namespace RockEngine
{
	//////////////////////////////////////////////////////////////////////////////////
	// IndexBuffer
	//////////////////////////////////////////////////////////////////////////////////


	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(u32 size);
		virtual ~OpenGLIndexBuffer() override;

		virtual void SetData(void* data, u32 size, u32 offset = 0) override;
		virtual void Bind() const;

		virtual uint32_t GetCount() const { return m_Size / sizeof(u32); }

		virtual u32 GetSize() const { return m_Size; }
		virtual RendererID GetRendererID() const override { return m_RendererID; }
	private:
		RendererID m_RendererID;
		u32 m_Size;
		//Buffer m_LocalData;
		void* m_LocalData;
	};

	//////////////////////////////////////////////////////////////////////////////////
	// VertexBuffer
	//////////////////////////////////////////////////////////////////////////////////


	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(u32 size);
		virtual ~OpenGLVertexBuffer() override;

		virtual void SetData(void* data, u32 size, u32 offset = 0) override;
		virtual void Bind() const;

		virtual u32 GetSize() const { return m_Size; }
		virtual RendererID GetRendererID() const { return m_RendererID; }
	private:
		RendererID m_RendererID;
		u32 m_Size;
		//Buffer m_LocalData;
		void* m_LocalData;
	};
}