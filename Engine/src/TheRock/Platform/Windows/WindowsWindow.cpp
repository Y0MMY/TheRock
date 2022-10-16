#include "pch.h"
#include "WindowsWindow.h"

#include "TheRock/Core/Log.h"

namespace RockEngine
{

	Window* Window::Create(const WindowProps& props /* = WindowProps() */)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	void WindowsWindow::OnUpdate()
	{
		RE_CORE_TRACE("OnUpdate");
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		/*m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;*/
	}



	void WindowsWindow::Shutdown()
	{

	}

}