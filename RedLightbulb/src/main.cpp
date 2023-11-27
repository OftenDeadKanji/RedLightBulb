#include "pch.h"
#include <iostream>
#include "Core/RedLightbulb.hpp"
#include "EventManager/EventManager.hpp"
#include "ResourceManagers/MeshManager/MeshManager.hpp"
#include "Render/General/Renderer.hpp"

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

	Renderer& renderer = Renderer::getInstance();

	MeshManager& meshManager = MeshManager::getInstance();

	Mesh mesh;
	if (!meshManager.load("res/Meshes/key.glb", "Key", mesh))
	{

	}
	UnlitShadingModel::Instance instance{};
	renderer.addUnlitMesh(&mesh, instance);

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
