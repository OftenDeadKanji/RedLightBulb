#ifndef __WINDOW_WINDOWS_HPP__
#define __WINDOW_WINDOWS_HPP__
#include "../Dependencies/OS/Windows.hpp"

#ifdef __OS_WINDOWS_64__
#include "Window.hpp"
#include <unordered_map>

namespace RedLightbulb
{
	class WindowWindows : public Window
	{
	public:
		void create(const WindowProperties&) override;
		void destroy() override;

		static WindowWindows* getInstancePtr(HWND);

		HWND getHWnd() const;
		HDC getHDC() const;

		void showWindow() override;
		void hideWindow() override;

		void swapBuffers() override;
	private:
		void init() override;
		void deinit() override;

		static std::unordered_map<HWND, WindowWindows*> s_instances;

		HWND m_hWnd;
		HDC m_hDC;
	};

}
#endif

#endif