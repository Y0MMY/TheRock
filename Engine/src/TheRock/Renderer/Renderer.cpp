#include "pch.h"
#include "Renderer.h"

namespace RockEngine {

	RendererAPIType RendererAPI::s_CurrentRendererAPI = RendererAPIType::OpenGL;

	struct RendererData
	{
		RenderCommandQueue m_CommandQueue;
	};

	static RendererData s_Data;

	void Renderer::Init()
	{
		Renderer::Submit([=]() mutable
			{
				RendererAPI::Init();
			});
	}

	void Renderer::DrawIndexed(u32 count)
	{
		Renderer::Submit([=]()
			{
				RendererAPI::DrawIndexed(count);
			});
	}

	void Renderer::Clear()
	{
		// HZ_RENDER(Clear());
	}

	void Renderer::Clear(float r, float g, float b, float a)
	{
		Renderer::Submit([=]()
			{
				RendererAPI::Clear(r, g, b, a);
			});
	}

	void Renderer::ClearMagenta()
	{
		Clear(1, 0, 1);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
		// HZ_RENDER(SetClearColor(r, g, b, a));
	}

	void Renderer::WaitAndRender()
	{
		s_Data.m_CommandQueue.Execute();
	}

	RenderCommandQueue& Renderer::GetRenderCommandQueue()
	{
		return s_Data.m_CommandQueue;
	}

}
