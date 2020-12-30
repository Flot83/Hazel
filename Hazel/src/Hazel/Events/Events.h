#pragma once
#include "Hazel/Core.h"



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

	class Event
	{
	public:
		Event() {};
		virtual ~Event() {};

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;

	private:
	};


	class KeyPress : public Event
	{

	};
}