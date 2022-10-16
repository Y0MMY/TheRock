#include "pch.h"
#include "Application.h"

namespace RockEngine
{
	Application::~Application()
	{
	
	}

	Application::Application(const ApplicationProps& props)
	{
		m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(props.Name, props.WindowWidth, props.WindowHeight)));
	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
		}
	}
}