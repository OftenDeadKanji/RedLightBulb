#include "pch.h"
#include <iostream>
#include "Core/RedLightbulb.hpp"
#include "EventManager/EventManager.hpp"
#include "ResourceManagers/MeshManager/MeshManager.hpp"

using namespace RedLightbulb;

int main()
{
	std::cout << "Hello there!" << std::endl;

	WindowProperties windowProperties;
	windowProperties.width = 1600;
	windowProperties.height = 900;
	windowProperties.mode = WindowProperties::Mode::Windowed;
	windowProperties.title = "RedLightbulb!";
	windowProperties.isResizeable = false;

	RedLighbulb engine;
	engine.init(windowProperties);

	Window& window = engine.getWindow();
	EventManager& eventManager = window.getEventManager();

	MeshManager& meshManager = MeshManager::getInstance();

	Mesh mesh;
	if (!meshManager.load("res/Meshes/key.fbx", "", mesh))
	{

	}
	
	bool loopCondition = true;
	while (loopCondition)
	{
		eventManager.pollEvents();
		while (auto ev = eventManager.getNextEvent())
		{
			switch (ev->type)
			{
				case Event::Type::WindowClose:
					loopCondition = false;
					break;
			}
		}

		engine.render();
		window.swapBuffers();
	}

	engine.deinit();

	return 0;
}
