#pragma once

#include "Event.h"

namespace RockEngine
{

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// TODO: Should this store previous size?
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(u32 width, u32 height)
			: m_Width(width), m_Height(height) {}

		inline u32 GetWidth() const { return m_Width; }
		inline u32 GetHeight() const { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		u32 m_Width, m_Height;
	};
}
