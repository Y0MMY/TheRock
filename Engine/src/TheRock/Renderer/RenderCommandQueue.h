#pragma once

namespace RockEngine
{
	class RenderCommandQueue
	{
	public:
		using RenderCommand = std::function<u32(void*)>;
		typedef u32(*RenderCommandFn)(void*);

		RenderCommandQueue();
		~RenderCommandQueue();

		void Submit(const RenderCommand& fn);
		void SubmitCommand(RenderCommandFn command, void* params, u32 size);

		void Execute();
	private:
		byte* m_CommandBuffer;
		byte* m_CommandBufferPtr;
		u32 m_RenderCommandCount = 0;
	};
}