#pragma once

#include "TheRock/Core/Base.h"

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

	};

	// Implemented by CLIENT
	Application* CreateApplication();
}