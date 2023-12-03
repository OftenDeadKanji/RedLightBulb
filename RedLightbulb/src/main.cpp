#include "pch.h"
#include <iostream>
#include "Core/RedLightbulb.hpp"
#include "../InputSystem/Events/EventManager.hpp"
#include "../InputSystem/Keyboard/Keyboard.hpp"
#include "../InputSystem/Mouse/Mouse.hpp"
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

	Keyboard keyboard;
	eventManager.setKeyboard(keyboard);

	Mouse mouse;
	eventManager.setMouse(mouse);

	Renderer& renderer = Renderer::getInstance();

	MeshManager& meshManager = MeshManager::getInstance();

	Mesh mesh;
	if (!meshManager.load("res/Meshes/key.glb", "Key", mesh))
	{

	}
	UnlitShadingModel::Instance instance{};
	renderer.addUnlitMesh(&mesh, instance);

	Camera camera;
	camera.setPerspective(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
	camera.lookAt(Vec3(0.0f, 0.0f, -0.2f), Vec3(0.0f, 0.0f, 0.0f));
	
	bool rotateCamera = false;
	Vec2 mousePrevPos;


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
				case Event::Type::MouseButtonPressed:
					if (mouse.isPressed(Mouse::Button::Left))
					{
						rotateCamera = true;
						mousePrevPos = mouse.getPosition();
					}
					break;
				case Event::Type::MouseButtonReleased:
					if (mouse.isPressed(Mouse::Button::Left))
					{
						rotateCamera = false;
					}
					break;
			}
		}

		if (keyboard.isPressed(Keyboard::KeyCode::D))
		{
			camera.addLocalPosition(Vec3(0.01f, 0.0f, 0.0f));
		}
		if (keyboard.isPressed(Keyboard::KeyCode::A))
		{
			camera.addLocalPosition(Vec3(-0.01f, 0.0f, 0.0f));
		}
		if (keyboard.isPressed(Keyboard::KeyCode::W))
		{
			camera.addLocalPosition(Vec3(0.0f, 0.0f, -0.01f));
		}
		if (keyboard.isPressed(Keyboard::KeyCode::S))
		{
			camera.addLocalPosition(Vec3(0.0f, 0.0f, 0.01f));
		}
		if (keyboard.isPressed(Keyboard::KeyCode::E))
		{
			camera.addLocalPosition(Vec3(0.0f, 0.01f, 0.0f));
		}
		if (keyboard.isPressed(Keyboard::KeyCode::Q))
		{
			camera.addLocalPosition(Vec3(0.0f, -0.01f, 0.0f));
		}

		if (rotateCamera)
		{
			Vec2 newPos = mouse.getPosition();
			Vec2 deltaPos = newPos - mousePrevPos;

			camera.addLocalRotation()
		}

		camera.update();

		engine.render(camera);
		window.swapBuffers();
	}

	engine.deinit();

	return 0;
}
