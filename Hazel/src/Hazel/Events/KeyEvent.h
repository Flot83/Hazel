#pragma once

#include "Events.h"
#include <functional>

namespace Hazel
{

	class  HAZEL_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const
		{
			return m_KeyCode;
		}

		int GetCategoryClass() const override
		{
			return EventCategoryInput | EventCategoryKeyboard;
		}
	protected:

		explicit KeyEvent(int keycode) : m_KeyCode(keycode)
		{}

		int m_KeyCode;
	};

	class  HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) :
			KeyEvent(keycode), m_RepeateCount(repeatCount)
		{};

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeateCount;
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event) : m_Event(event)
		{

		}
		using EventFn = std::function<bool(Hazel::KeyPressedEvent&)>;


	
		bool Dispatch(EventFn f);

	private:
		Event& m_Event;
	};
}