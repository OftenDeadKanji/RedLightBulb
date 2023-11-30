#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__
#include <queue>
#include <optional>
#include "../Utilities/Utilities.hpp"
#include "Event.hpp"
//#include "../Keyboard/Keyboard.hpp"

namespace RedLightbulb
{
	class Window;
	class Keyboard;

	class EventManager
	{
		friend Window;
	public:
		virtual void pollEvents() = 0;
		std::optional<Event> getNextEvent();

		void setKeyboard(Keyboard& keyboard);

	protected:
		Window* m_window;
		std::queue<Event> m_eventsQueue;
		Keyboard* m_keyboard;
	};
}

#endif
