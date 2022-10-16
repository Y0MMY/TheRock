#pragma once

#include <functional>

#include "TheRock/Core/Base.h"
#include "TheRock/Core/Events/Event.h"


namespace RockEngine
{
	struct WindowProps
	{
		std::string Name;
		u32 Width, Height;

		WindowProps(const std::string& name = "TheRock", u32 Width = 1280, u32 Height = 720)
			: Name(name),Width(Width), Height(Height) {}

	};

	// Interface representing a desktop system based Window
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowProps& props);
		virtual ~Window(){}

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual u32 GetWidth() const = 0;
		virtual u32 GetHeight() const = 0;
	};
}