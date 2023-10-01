#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__
#include "../Config/OSInfo.hpp"

#include <queue>
#include <optional>

#ifdef __OS_WINDOWS_64__
#include <Windows.h>
#endif

#include "../Utilities/Utilities.hpp"
#include "Event.hpp"

namespace RedLightbulb
{
	class Window;

	class EventManager
	{
		friend Window;
	public:
		void pollEvents();
		std::optional<Event> getNextEvent();

	private:
	#ifdef __OS_WINDOWS_64__
		static LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	#endif

		void init();
		void deinit();
		
		Window* m_window;
		std::queue<Event> m_eventsQueue;
	};
}

#endif
