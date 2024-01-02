#include "pch.h"
#include <iostream>
#include "Core/RedLightbulb.hpp"
#include "../InputSystem/Events/EventManager.hpp"
#include "../InputSystem/Keyboard/Keyboard.hpp"
#include "../InputSystem/Mouse/Mouse.hpp"
#include "ResourceManagers/MeshManager/MeshManager.hpp"
#include "Render/General/Renderer.hpp"
#include "Utilities/Timer.hpp"

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
	if (!meshManager.load("res/Meshes/keyTextured.glb", "Key", mesh))
	{

	}
	UnlitShadingModel::Instance instance{};
	renderer.addUnlitMesh(&mesh, instance);

	Camera camera;
	camera.setPerspective(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
	camera.lookAt(Vec3f(0.0f, 0.0f, 0.5f), Vec3f(0.0f, 0.0f, 0.0f));
	camera.update();

	bool rotateCamera = false;
	Vec2f mousePrevPos(0.0f, 0.0f);

	float movementSpeed = 10.0f;
	float rotationSpeed = 0.1f;

	Utilities::Timer timer;
	timer.setNewTimePoint();

	bool loopCondition = true;
	while (loopCondition)
	{
		float deltaTime = timer.elapsed();
		if (deltaTime < 0.016f)
		{
			continue;
		}
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
					if (!mouse.isPressed(Mouse::Button::Left))
					{
						rotateCamera = false;
					}
					break;
			}
		}

		
		timer.setNewTimePoint();

		if (keyboard.isPressed(Keyboard::KeyCode::D))
		{
			camera.addLocalPosition(Vec3f(0.01f, 0.0f, 0.0f) * deltaTime * movementSpeed);
		}
		if (keyboard.isPressed(Keyboard::KeyCode::A))
		{
			camera.addLocalPosition(Vec3f(-0.01f, 0.0f, 0.0f) * deltaTime * movementSpeed);
		}
		if (keyboard.isPressed(Keyboard::KeyCode::W))
		{
			camera.addLocalPosition(Vec3f(0.0f, 0.0f, 0.01f) * deltaTime * movementSpeed);
		}
		if (keyboard.isPressed(Keyboard::KeyCode::S))
		{
			camera.addLocalPosition(Vec3f(0.0f, 0.0f, -0.01f) * deltaTime * movementSpeed);
		}
		if (keyboard.isPressed(Keyboard::KeyCode::E))
		{
			camera.addLocalPosition(Vec3f(0.0f, 0.01f, 0.0f) * deltaTime * movementSpeed);
		}
		if (keyboard.isPressed(Keyboard::KeyCode::Q))
		{
			camera.addLocalPosition(Vec3f(0.0f, -0.01f, 0.0f) * deltaTime * movementSpeed);
		}

		if (rotateCamera)
		{
			Vec2f newPos = mouse.getPosition();
			Vec2f deltaPos = newPos - mousePrevPos;

			Vec3f cameraRotation{ 0.0f, 0.0f, 0.0f };

			cameraRotation.x() = -Math::deg2rad(deltaPos.y());
			cameraRotation.y() = Math::deg2rad(deltaPos.x());

			cameraRotation *= deltaTime * rotationSpeed;

			camera.addLocalRotation(cameraRotation);
		}

		camera.update();

		engine.render(camera);
		window.swapBuffers();
	}

	engine.deinit();

	return 0;
}
