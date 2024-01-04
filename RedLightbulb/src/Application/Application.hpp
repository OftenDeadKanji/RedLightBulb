#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__
#include "Core/RedLightbulb.hpp"
#include "InputSystem/Keyboard/Keyboard.hpp"
#include "InputSystem/Mouse/Mouse.hpp"

namespace RedLightbulb
{
	class Window;
	class EventManager;
}

class Application
{
public:
	~Application();

	void init();
	void deinit();

	void run();
private:
	bool m_isInitialised = false;

	RedLighbulb engine;

	Window* window;
	
	EventManager* eventManager;
	Keyboard keyboard;
	Mouse mouse;
};

#endif