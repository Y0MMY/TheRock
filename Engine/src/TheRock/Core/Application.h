#pragma once

#include "TheRock/Core/Base.h"
#include "Window.h"

namespace RockEngine
{
	struct ApplicationProps
	{
		std::string Name;
		u32 WindowWidth, WindowHeight;
	};

	class Application
	{
	public:
		Application(const ApplicationProps& props);
		virtual ~Application();

		void Run();

		virtual void OnInit() {}
		virtual void OnShutdown() {}
		virtual void OnUpdate() {}
	private:
		Scope<Window> m_Window;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}