#pragma once

#include "Event.h"
#include "TheRock/Core/KeyCodes.h"

namespace RockEngine
{
	class KeyEvent : public Event
	{
	public:
		inline KeyCode GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(KeyCode key)
			: m_KeyCode(key){}

		KeyCode m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode key, int repeatCount)
			: KeyEvent(key), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(KeyCode key)
			:
			 KeyEvent(key) {}

		EVENT_CLASS_TYPE(KeyTyped)
	private:
		KeyCode m_KeyCode;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode key)
			: KeyEvent(key){}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}