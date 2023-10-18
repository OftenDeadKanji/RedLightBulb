#include "Window.hpp"

namespace RedLightbulb
{
	Window::~Window()
	{
		if (m_isInitialised)
		{
			destroy();
		}
	}

	void Window::create(const WindowProperties& properties)
	{
		if (m_isInitialised)
		{
			//destroy?
		}

		m_properties = properties;
		
		init();
		showWindow();

		m_eventManager->m_window = this;

		m_isInitialised = true;
	}

	void Window::destroy()
	{
		if (m_isInitialised)
		{
			deinit();

			m_isInitialised = false;
		}
	}

	EventManager& Window::getEventManager()
	{
		return *m_eventManager;
	}
}