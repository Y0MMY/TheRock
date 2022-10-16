#pragma once

#include "TheRock/Core/Window.h"

namespace RockEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow() override;

		void OnUpdate() override;
		virtual void SetEventCallback(const EventCallbackFn& callback) override { m_EventCallbackFn = callback; }

		inline u32 GetWidth() const override { return m_Width; }
		inline u32 GetHeight() const override { return m_Height; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		std::string m_Title;
		u32 m_Width, m_Height;

		EventCallbackFn m_EventCallbackFn;
	};
}