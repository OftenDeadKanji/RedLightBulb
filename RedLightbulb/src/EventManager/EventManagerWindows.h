#ifndef __EVENT_MANGER_WINDOWS_HPP__
#define __EVENT_MANGER_WINDOWS_HPP__
#include "../Dependencies/OS/Windows.hpp"

#ifdef __OS_WINDOWS_64__
#include "EventManager.hpp"

namespace RedLightbulb
{
	class WindowWindows;

	class EventManagerWindows : public EventManager
	{
		friend WindowWindows;
	public:
		void pollEvents() override;

	private:
		static LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	};
}
#endif

#endif