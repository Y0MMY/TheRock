#pragma once

#include "TheRock/Renderer/VertexBuffer.h"

namespace RockEngine
{
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