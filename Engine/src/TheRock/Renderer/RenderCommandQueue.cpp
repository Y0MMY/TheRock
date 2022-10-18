#include "pch.h"
#include "RenderCommandQueue.h"

namespace RockEngine
{
	RenderCommandQueue::RenderCommandQueue()
	{
		m_CommandBuffer = new byte[10 * 1024 * 1024]; // 10mb
		m_CommandBufferPtr = m_CommandBuffer;
		memset(m_CommandBuffer, 0, 10 * 1024 * 1024);

	}
	RenderCommandQueue::~RenderCommandQueue()
	{
		delete[] m_CommandBuffer;
	}

	void* RenderCommandQueue::Allocate(RenderCommandFn fn, u32 size)
	{
		*(RenderCommandFn*)m_CommandBufferPtr = fn;
		m_CommandBufferPtr += sizeof(RenderCommandFn);

		*(u32*)m_CommandBufferPtr = size;
		m_CommandBufferPtr += sizeof(u32);

		void* memory = m_CommandBufferPtr;
		m_CommandBufferPtr += size;

		m_CommandCount++;
		return memory;
	}


	void RenderCommandQueue::Execute()
	{
		//RE_CORE_TRACE("RenderCommandQueue::Execute -- {0} commands, {1} bytes", m_CommandCount, (m_CommandBufferPtr - m_CommandBuffer));

		byte* buffer = m_CommandBuffer;

		for (u32 i = 0; i < m_CommandCount; i++)
		{
			RenderCommandFn function = *(RenderCommandFn*)buffer;
			buffer += sizeof(RenderCommandFn);

			u32 size = *(u32*)buffer;
			buffer += sizeof(u32);
			function(buffer);
			buffer += size;
		}

		m_CommandBufferPtr = m_CommandBuffer;
		m_CommandCount = 0;
	}


}