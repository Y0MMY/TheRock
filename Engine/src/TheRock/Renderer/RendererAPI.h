#pragma once

namespace RockEngine
{
	using RendererID = unsigned int;

	enum class RendererAPIType
	{
		None = 0,
		OpenGL = 1,
	};

	class RendererAPI
	{
	public:
		static void Init();
		static void Shutdown();

		static void Clear(float r, float g, float b, float a);
		static void SetClearColor(float r, float g, float b, float a);
		static void DrawIndexed(u32 count);
	public:
		static RendererAPIType Current() { return s_CurrentRendererAPI; }
	private:
		static RendererAPIType s_CurrentRendererAPI;
	};
}