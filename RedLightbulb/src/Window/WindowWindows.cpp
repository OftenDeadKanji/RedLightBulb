#include "pch.h"
#include "windowWindows.hpp"
#include "../InputSystem/Events/EventManagerWindows.h"

namespace RedLightbulb
{
	std::unordered_map<HWND, WindowWindows*> WindowWindows::s_instances;


	void WindowWindows::create(const WindowProperties& properties)
	{
		Window::create(properties);
		s_instances[m_hWnd] = this;
	}

	void WindowWindows::destroy()
	{
		Window::destroy();

		s_instances.erase(m_hWnd);
	}

	WindowWindows* WindowWindows::getInstancePtr(HWND hWnd)
	{
	#ifdef _SHIPPING
		return s_instances[hWnd];
	#else
		return s_instances.contains(hWnd) ? s_instances[hWnd] : nullptr;
	#endif
	}

	HWND WindowWindows::getHWnd() const
	{
		return m_hWnd;
	}

	HDC WindowWindows::getHDC() const
	{
		return m_hDC;
	}

	void WindowWindows::showWindow()
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
	}

	void WindowWindows::hideWindow()
	{
		ShowWindow(m_hWnd, SW_HIDE);
	}

	void WindowWindows::swapBuffers()
	{
		SwapBuffers(m_hDC);
	}

	void WindowWindows::init()
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);

		const char wndClassName[] = "WindowClass1";

		WNDCLASSEXA wndClass{};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.lpfnWndProc = EventManagerWindows::WndProc;
		wndClass.hInstance = hInstance;
		wndClass.style = CS_OWNDC;
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
			dwStyle |= WS_OVERLAPPED | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
			if (m_properties.isResizeable)
			{
				dwStyle |= WS_MAXIMIZEBOX;
			}

			x = (screenWidth - m_properties.width) / 2;
			y = (screenHeight - m_properties.height) / 2;
		}
		else
		{
			dwStyle |= WS_POPUP;

			m_properties.width = screenWidth;
			m_properties.height = screenHeight;
		}

		m_hWnd = CreateWindowExA(
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

		if (!m_hWnd)
		{
			auto error = GetLastError();

			return;
		}

		m_hDC = GetDC(m_hWnd);

		m_eventManager = new EventManagerWindows();
	}

	void WindowWindows::deinit()
	{
		DestroyWindow(m_hWnd);
		m_eventManager->pollEvents();
		//delete m_eventManager;
	}
}