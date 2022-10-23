#pragma once

#include "TheRock/Core/Base.h"
#include "TheRock/Core/Timestep.h"

#include "TheRock/Core/LayerStack.h"

#include "Window.h"

#include "TheRock/ImGui/ImGuiLayer.h"

#include "TheRock/Core/Events/ApplicationEvent.h"

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
		virtual void OnEvent(Event& e);

		virtual void OnInit() {}
		virtual void OnShutdown() {}
		virtual void OnUpdate(Timestep ts) {}

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void RenderImGui();

		inline Window& GetWindow() { return *m_Window; }
		static inline Application& Get() { return *s_Instance; }

		std::string OpenFile(const std::string& filter = "All\0*.*\0") const;
		float GetTime() const; // TODO: This should be in "Platform"
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		LayerStack m_LayerStack;
		static Application* s_Instance;
		ImGuiLayer* m_ImGuiLayer;

		Scope<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;

		Timestep m_Timestep;

		float m_LastFrameTime = 0.0f;

	};

	// Implemented by CLIENT
	Application* CreateApplication();
}