#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__
#include "Core/Core.hpp"
#include "InputSystem/Keyboard/Keyboard.hpp"
#include "InputSystem/Mouse/Mouse.hpp"
#include "Render/General/Camera/Camera.hpp"
#include "Utilities/Timer.hpp"

namespace RedLightbulb
{
	class Window;
	class EventManager;
	class Renderer;
	class MeshManager;
}

class Application
{
public:
	~Application();

	void init();
	void deinit();

	void run();
	
	bool startNewFrame();
	void processInputEvents();
	void updateCamera();
private:
	void loadMeshes();

	void setupUnlitMeshes();
	void setupLitMeshes();

	bool m_isInitialised = false;

	RedLightbulb::Core m_engine;

	RedLightbulb::Window* m_windowPtr {};
	
	RedLightbulb::EventManager* m_eventManagerPtr {};
	RedLightbulb::Keyboard m_keyboard;
	RedLightbulb::Mouse m_mouse;

	RedLightbulb::Camera m_camera;

	bool m_rotateCamera { false };
	Math::Vec2f m_mousePrevPos { 0.0f, 0.0f };

	float m_cameraMovementSpeed { 0.25f };
	float m_cameraRotationSpeed { 0.25f };

	Utilities::Timer m_timer;
	float m_deltaTime { 1.0f };
	float m_frameTimeLimit { 1.0f / 144.0f };

	bool m_mainLoopCondition { true };
};

#endif