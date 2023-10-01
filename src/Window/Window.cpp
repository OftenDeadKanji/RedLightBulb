#include "Window.hpp"

namespace RedLightbulb
{
	std::unordered_map<HWND, Window*> Window::s_instances;

	void Window::create()
	{
		if (bIsInitialised)
		{
			//destroy?
		}

		init();
		s_instances[hWnd] = this;
		m_eventManager.m_window = this;

		bIsInitialised = true;
	}

	void Window::destroy()
	{
		if (bIsInitialised)
		{
			deinit();
			s_instances.erase(hWnd);

			bIsInitialised = false;
		}
	}

	Window* Window::getInstancePtr(HWND hWnd)
	{
	#ifdef _SHIPPING
		return s_instances[hWnd];
	#else
		return s_instances.contains(hWnd) ? s_instances[hWnd] : nullptr;
	#endif
	}

	EventManager& Window::getEventManager()
	{
		return m_eventManager;
	}

	void Window::init()
	{
	
	#ifdef __OS_WINDOWS_64__
		HINSTANCE hInstance = GetModuleHandle(NULL);
		
		const char wndClassName[] = "WindowClass1";

		WNDCLASSEXA wndClass{};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.lpfnWndProc = EventManager::WndProc;
		wndClass.hInstance = hInstance;
		wndClass.lpszClassName = wndClassName;

		if (!RegisterClassExA(&wndClass))
		{
			auto error = GetLastError();

			return;
		}

		int width = 800;
		int height = 800;

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		int x = (screenWidth - width) / 2;
		int y = (screenHeight - height) / 2;

		hWnd = CreateWindowExA(
			0,
			wndClassName,
			"RedLightbulb",
			WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU,
			x, y,
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
	{}
}