#pragma once

namespace RockEngine
{
	class RenderCommandQueue
	{
	public:
		typedef void(*RenderCommandFn)(void*);

		RenderCommandQueue();
		~RenderCommandQueue();

		void* Allocate(RenderCommandFn fn, unsigned int size);

		void Execute();
	private:
		byte* m_CommandBuffer;
		byte* m_CommandBufferPtr;
		u32 m_CommandCount = 0;
	};
}