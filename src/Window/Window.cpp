#include "Window.hpp"

namespace RedLightbulb
{
	std::unique_ptr<Window> Window::s_instance = nullptr;

	Window& Window::create()
	{
		if (s_instance)
		{
			//destroy?
		}

		s_instance = std::unique_ptr<Window>(new Window());
		s_instance->init();

		return *s_instance;
	}

	void Window::destroy()
	{
		if (s_instance)
		{
			s_instance->deinit();
			s_instance.release();
			s_instance = nullptr;
		}
	}

	LRESULT Wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	void Window::init()
	{
	
	#ifdef __OS_WINDOWS_64__
		HINSTANCE hInstance = GetModuleHandle(NULL);
		
		const char wndClassName[] = "WindowClass1";
		//RegisterClassExA()

		WNDCLASSEXA wndClass{};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.lpfnWndProc = Wndproc;
		wndClass.hInstance = hInstance;
		wndClass.lpszClassName = wndClassName;

		if (!RegisterClassExA(&wndClass))
		{
			auto error = GetLastError();

			return;
		}

		HWND hWnd = CreateWindowExA(
			0,
			wndClassName,
			"RedLightbulb",
			WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU,
			0, 0,
			800, 800,
			NULL,
			NULL,
			hInstance,
			NULL
		);

		if (!hWnd)
		{
			auto error = GetLastError();

			return;
		}

		ShowWindow(hWnd, SW_SHOWNORMAL);
	#endif

	}

	void Window::deinit()
	{
	
	}



}