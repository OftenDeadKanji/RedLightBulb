#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__
#include <queue>
#include <optional>
#include "../Utilities/Utilities.hpp"
#include "Event.hpp"

namespace RedLightbulb
{
	class Window;
	class Keyboard;
	class Mouse;

	class EventManager
	{
		friend Window;
	public:
		virtual void pollEvents() = 0;
		std::optional<Event> getNextEvent();

		void setKeyboard(Keyboard& keyboard);
		void setMouse(Mouse& mouse);

	protected:
		Window* m_window;
		std::queue<Event> m_eventsQueue;
		Keyboard* m_keyboard;
		Mouse* m_mouse;
	};
}

#endif
