#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__
#include <queue>
#include <optional>
#include "../Utilities/Utilities.hpp"
#include "Event.hpp"

namespace RedLightbulb
{
	class Window;

	class EventManager
	{
		friend Window;
	public:
		virtual void pollEvents() = 0;
		std::optional<Event> getNextEvent();

	protected:
		Window* m_window;
		std::queue<Event> m_eventsQueue;
	};
}

#endif
