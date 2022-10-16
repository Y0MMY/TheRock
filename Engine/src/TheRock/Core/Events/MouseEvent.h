#pragma once

#include "Event.h"

namespace RockEngine
{
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y, float dx, float dy)
			: m_MouseX(x), m_MouseY(y),m_MouseDX(dx),m_MouseDY(dy) {}

		float inline GetX() const { return m_MouseX; }
		float inline GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(EventType::MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseDX;
		float m_MouseY, m_MouseDY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(int button)
			: m_Button(button) {}
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		int m_Button;
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	private:
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button, int repeatCount)
			: MouseButtonEvent(button), m_RepeatCount(repeatCount)
		{}
	private:
		int m_RepeatCount;
	};
}