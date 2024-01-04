#include "pch.h"
#include "Application.hpp"
#include "Window/WindowProperties.hpp"

using namespace RedLightbulb;

Application::~Application()
{
	deinit();
}

void Application::init()
{
	WindowProperties windowProperties;
	windowProperties.width = 1600;
	windowProperties.height = 900;
	windowProperties.mode = WindowProperties::Mode::Windowed;
	windowProperties.title = "RedLightbulb!";
	windowProperties.isResizeable = false;

	engine.init(windowProperties);

	window = engine.getWindowPtr();

	eventManager = window->getEventManagerPtr();
	eventManager->setKeyboard(keyboard);
	eventManager->setMouse(mouse);
	
	m_isInitialised = true;
}

void Application::deinit()
{
	if (!m_isInitialised)
	{
		return;
	}
}

void Application::run()
{
}
