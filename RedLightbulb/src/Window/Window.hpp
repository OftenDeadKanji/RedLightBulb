#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include "../Window/WindowProperties.hpp"
#include "../InputSystem/Events/EventManager.hpp"

namespace RedLightbulb
{
	class Window
	{
	public:
		virtual ~Window();

		virtual void create(const WindowProperties&);
		virtual void destroy();

		virtual void showWindow() = 0;
		virtual void hideWindow() = 0;

		virtual void swapBuffers() = 0;

		EventManager& getEventManager();

	protected:
		virtual void init() = 0;
		virtual void deinit() = 0;

		bool m_isInitialised = false;
		WindowProperties m_properties;

		EventManager* m_eventManager;
	};
}

#endif
