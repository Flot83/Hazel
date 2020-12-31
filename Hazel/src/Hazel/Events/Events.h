#pragma once
#include "Hazel/Core.h"
#include <string>


namespace Hazel
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)

	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType() { return EventType::##type; } \
							   virtual const char* GetName() const override { return #type;} \
							   virtual EventType GetEventType() const override { return GetStaticEventType();} 
							   

	class HAZEL_API Event
	{
	public:
		Event() {};
		virtual ~Event() {};

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryClass() const = 0;
		virtual std::string ToString() const
		{
			return GetName();
		}

		inline bool IsInCategory(int category)
		{
			return GetCategoryClass() & category;
		}
		inline void SetEventHandled() 
		{
			m_Handled = true;
		}

		inline bool IsHandled()
		{
			return m_Handled;
		}
	private:

		bool m_Handled = false;
	};



}

