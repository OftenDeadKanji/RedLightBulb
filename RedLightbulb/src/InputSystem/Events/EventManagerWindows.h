#ifndef __EVENT_MANGER_WINDOWS_HPP__
#define __EVENT_MANGER_WINDOWS_HPP__
#include "../Dependencies/OS/Windows.hpp"

#ifdef __OS_WINDOWS_64__
#include "EventManager.hpp"
#include "../Keyboard/Keyboard.hpp"
#include "../Mouse/Mouse.hpp"

namespace RedLightbulb
{
	class WindowWindows;

	class EventManagerWindows : public EventManager
	{
		friend WindowWindows;
	public:
		void pollEvents() override;

	private:
		static WPARAM processKey(WPARAM wparam, LPARAM lParam);
		static Keyboard::KeyCode translateKeyCode(WPARAM key);

		

		static LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	};
}
#endif

#endif