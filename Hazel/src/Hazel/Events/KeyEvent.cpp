#include "pch.h"
#include "KeyEvent.h"


inline bool Hazel::EventDispatcher::Dispatch(EventFn f) {
	return f(*(static_cast<Hazel::KeyPressedEvent*>(&m_Event)));
}
