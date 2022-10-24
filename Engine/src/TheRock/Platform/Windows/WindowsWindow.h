#pragma once

#include "TheRock/Core/Window.h"

#include <GLFW/glfw3.h>

namespace RockEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow() override;

		void OnUpdate() override;

		inline u32 GetWidth() const override { return m_Data.Width; }
		inline u32 GetHeight() const override { return m_Data.Height; }
		virtual std::pair<float, float> GetWindowPos() const override;


		inline void* GetNativeWindow() const override { return m_Window; }

		// Window attribute
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; } // Set pointer to call a function
		virtual void SetVSync(bool enabled) override { m_Data.VSync = enabled; }
		virtual bool IsVSync() const override { return m_Data.VSync; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			u32 Width, Height;
			bool VSync = true;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
		float m_LastFrameTime = 0.0f;
	};
}