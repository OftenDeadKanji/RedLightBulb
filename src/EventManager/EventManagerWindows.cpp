#include "EventManagerWindows.h"
#include "../Window/WindowWindows.hpp"

namespace RedLightbulb
{
	void EventManagerWindows::pollEvents()
	{
		MSG msg{};
		GetMessageA(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

	LRESULT EventManagerWindows::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		WindowWindows* window = WindowWindows::getInstancePtr(hWnd);
		if (!window)
		{
			return DefWindowProcA(hWnd, uMsg, wParam, lParam);
		}

		EventManagerWindows& eventManager = static_cast<EventManagerWindows&>(window->getEventManager());
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
