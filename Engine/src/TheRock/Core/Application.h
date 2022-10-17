#pragma once

#include "TheRock/Core/Base.h"
#include "Window.h"
#include "TheRock/Core/LayerStack.h"

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
		virtual void OnUpdate() {}

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void RenderImGui();

		inline Window& GetWindow() { return *m_Window; }
		static inline Application& Get() { return *s_Instance; }
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		LayerStack m_LayerStack;
		static Application* s_Instance;
		ImGuiLayer* m_ImGuiLayer;

		Scope<Window> m_Window;
		bool m_Running = true;
	};

	// Implemented by CLIENT
	Application* CreateApplication();
}