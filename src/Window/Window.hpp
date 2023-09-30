#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include "../Config/OSInfo.hpp"

#include <memory>

#ifdef __OS_WINDOWS_64__
#include <Windows.h>
#endif

#include "../Utilities/NonCopyable.hpp"



namespace RedLightbulb
{
	class Window : public NonCopyable
	{
	private:
		Window() = default;
	public:
		static Window& create();
		static void destroy();

	private:
		void init();
		void deinit();

	#ifdef __OS_WINDOWS_64__
		//LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	#endif

		static std::unique_ptr<Window> s_instance;
	};
}

#endif
