#pragma once

#include "RenderCommandQueue.h"
#include "RendererAPI.h"

namespace RockEngine
{
	class Renderer
	{
	public:
		// Commands
		static void Clear();
		static void Clear(float r, float g, float b, float a = 1.0f);
		static void SetClearColor(float r, float g, float b, float a);

		static void ClearMagenta();
		void Init();

		static void Submit(const std::function<void()>& command)
		{
			//s_Instance->m_CommandQueue.Submit(command);
		}

		void WaitAndRender();

		inline static Renderer& Get() { return *s_Instance; }
	private:
		static Renderer* s_Instance;

		RenderCommandQueue m_CommandQueue;

	};
#define RE_RENDER(x) ::RockEngine::Renderer::Submit([=](){ RendererAPI::x; })
}