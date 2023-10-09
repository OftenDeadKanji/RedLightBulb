#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__
#include "../Config/OSInfo.hpp"

#include <unordered_map>
#ifdef __OS_WINDOWS_64__
#include <Windows.h>
#endif

#include "../Window/WindowProperties.hpp"
#include "../EventManager/EventManager.hpp"


namespace RedLightbulb
{
	class Window
	{
	public:
		void create(const WindowProperties&);
		void destroy();

	#ifdef __OS_WINDOWS_64__
		static Window* getInstancePtr(HWND);
	#endif

		EventManager& getEventManager();
	private:
		void init();
		void deinit();

	#ifdef __OS_WINDOWS_64__
		static std::unordered_map<HWND, Window*> s_instances;
		HWND hWnd;
	#endif
		bool bIsInitialised = false;
		WindowProperties m_properties;

		EventManager m_eventManager;
	};
}

#endif
