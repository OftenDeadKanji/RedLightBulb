#include "Window.hpp"

namespace RedLightbulb
{
	std::unordered_map<HWND, Window*> Window::s_instances;

	void Window::create(const WindowProperties& properties)
	{
		if (bIsInitialised)
		{
			//destroy?
		}

		m_properties = properties;
		
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

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		DWORD dwStyle{};
		int x = 0, y = 0;

		if (m_properties.mode == WindowProperties::Mode::Windowed)
		{
			dwStyle |= WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
			if (m_properties.isResizeable)
			{
				dwStyle |= WS_MAXIMIZEBOX;
			}

			x = (screenWidth - m_properties.width) / 2;
			y = (screenHeight - m_properties.height) / 2;
		}
		else
		{
			m_properties.width = screenWidth;
			m_properties.height = screenHeight;
		}

		hWnd = CreateWindowExA(
			0,
			wndClassName,
			m_properties.title.c_str(),
			dwStyle,
			x, y,
			m_properties.width, m_properties.height,
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