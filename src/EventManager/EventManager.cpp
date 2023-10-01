#include "EventManager.hpp"
#include "../Config/OSInfo.hpp"

#ifdef __OS_WINDOWS_64__
#include <Windows.h>
#endif

#include "../Window/Window.hpp"

namespace RedLightbulb
{

	void EventManager::pollEvents()
	{
	#ifdef __OS_WINDOWS_64__
		MSG msg{};
		GetMessageA(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	#endif
	}

	std::optional<Event> EventManager::getNextEvent()
	{
		if (m_eventsQueue.empty())
		{
			return {};
		}

		Event nextEvent = std::move(m_eventsQueue.front());
		m_eventsQueue.pop();

		return nextEvent;
	}

	LRESULT EventManager::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		auto* window = Window::getInstancePtr(hWnd);
		if (!window)
		{
			return DefWindowProcA(hWnd, uMsg, wParam, lParam);
		}

		auto& eventManager = window->getEventManager();
		Event receivedEvent;

		switch (uMsg)
		{
			case WM_CLOSE:
				receivedEvent.type = Event::Type::WindowClose;
				eventManager.m_eventsQueue.emplace(receivedEvent);
				break;
			default:
				return DefWindowProcA(hWnd, uMsg, wParam, lParam);
		}
	}
}