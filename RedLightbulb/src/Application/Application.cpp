#include "pch.h"
#include "Application.hpp"
#include "Window/WindowProperties.hpp"
#include "Render/General/Renderer.hpp"
#include "ResourceManagers/MeshManager/MeshManager.hpp"

using namespace RedLightbulb;
using namespace Math;

#define RendererInst Renderer::getInstance()
#define RendererPtr  Renderer::getInstancePtr()

#define MeshManagerInst MeshManager::getInstance()
#define MeshManagerPtr  MeshManager::getInstancePtr()

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

	m_engine.init(windowProperties);
	m_windowPtr = m_engine.getWindowPtr();

	m_eventManagerPtr = m_windowPtr->getEventManagerPtr();
	m_eventManagerPtr->setKeyboard(m_keyboard);
	m_eventManagerPtr->setMouse(m_mouse);
	
	m_camera.setPerspective(45.0f, 16.0f / 9.0f, 0.01f, 1000.0f);
	m_camera.lookAt(Vec3f(0.0f, 0.0f, 0.5f), Math::Vec3f(0.0f, 0.0f, 0.0f));
	m_camera.update();

	sPtr<Mesh> keyMesh = std::make_shared<Mesh>();
	if (!MeshManagerInst.load("res/Meshes/keyTextured.glb", "Key", keyMesh))
	{
	
	}

	//sPtr<Mesh> r2d2Mesh = std::make_shared<Mesh>();
	//if (!MeshManagerInst.load("res/Meshes/r2d2.glb", "R2D2", r2d2Mesh))
	//{
	//
	//}

	{
		UnlitShadingModel::InstanceT instance;
		instance.transform = Math::Mat4f::Identity();

		RendererInst.addUnlitMesh(keyMesh, instance);

		instance.transform.col(3) = Math::Vec4f(1.0f, 1.0f, 0.0f, 1.0f);
		RendererInst.addUnlitMesh(keyMesh, instance);
	}

	//{
	//	LitShadingModel::InstanceT instance {};
	//	//RendererInst.addLitMesh(r2d2Mesh, instance);
	//}

	m_timer.setNewTimePoint();

	m_isInitialised = true;
}

void Application::deinit()
{
	if (!m_isInitialised)
	{
		return;
	}

	m_engine.deinit();
}

void Application::run()
{
	if (m_isInitialised == false)
	{
		std::cout << "Application::run() called without being initialised!" << std::endl;
		return;
	}

	while (m_mainLoopCondition)
	{
		if (startNewFrame() == false)
		{
			continue;
		}

		processInputEvents();
		updateCamera();

		m_engine.render(m_camera);
	}
}

bool Application::startNewFrame()
{
	float deltaTime = m_timer.elapsed();
	if (deltaTime >= m_frameTimeLimit)
	{
		m_deltaTime = deltaTime;
		m_timer.setNewTimePoint();

		return true;
	}

	return false;
}

void Application::processInputEvents()
{
	m_eventManagerPtr->pollEvents();
	while (auto nextEvent = m_eventManagerPtr->getNextEvent())
	{
		switch (nextEvent->type)
		{
		case Event::Type::WindowClose:
			m_mainLoopCondition = false;
			break;
		case Event::Type::MouseButtonPressed:
			if (m_mouse.isPressed(Mouse::Button::Left))
			{
				m_rotateCamera = true;
				m_mousePrevPos = m_mouse.getPosition();
			}
			break;
		case Event::Type::MouseButtonReleased:
			if (!m_mouse.isPressed(Mouse::Button::Left))
			{
				m_rotateCamera = false;
			}
			break;
		}
	}
}

void Application::updateCamera()
{
	Vec3f cameraMovement { 0.0f, 0.0f, 0.0f };
	if (m_keyboard.isPressed(Keyboard::KeyCode::D))
	{
		cameraMovement += Math::Vec3f(1.0f, 0.0f, 0.0f);
	}
	if (m_keyboard.isPressed(Keyboard::KeyCode::A))
	{
		cameraMovement += Math::Vec3f(-1.0f, 0.0f, 0.0f);
	}
	if (m_keyboard.isPressed(Keyboard::KeyCode::W))
	{
		cameraMovement += Math::Vec3f(0.0f, 0.0f, 1.0f);
	}
	if (m_keyboard.isPressed(Keyboard::KeyCode::S))
	{
		cameraMovement += Math::Vec3f(0.0f, 0.0f, -1.0f);
	}
	if (m_keyboard.isPressed(Keyboard::KeyCode::E))
	{
		cameraMovement += Math::Vec3f(0.0f, 1.0f, 0.0f);
	}
	if (m_keyboard.isPressed(Keyboard::KeyCode::Q))
	{
		cameraMovement += Math::Vec3f(0.0f, -1.0f, 0.0f);
	}

	Vec3f cameraRotation { 0.0f, 0.0f, 0.0f };
	if (m_rotateCamera)
	{
		Vec2f newPos = m_mouse.getPosition();
		Vec2f deltaPos = newPos - m_mousePrevPos;

		cameraRotation.x() = -Math::deg2rad(deltaPos.y());
		cameraRotation.y() = Math::deg2rad(deltaPos.x());
	}
	
	cameraMovement *= m_deltaTime * m_cameraMovementSpeed;
	m_camera.addLocalPosition(cameraMovement);
	
	cameraRotation *= m_deltaTime * m_cameraRotationSpeed;
	m_camera.addLocalRotation(cameraRotation);
	
	m_camera.update();
}

