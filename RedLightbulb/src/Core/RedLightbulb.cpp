#include "pch.h"
#include "RedLightbulb.hpp"
#include <iostream>
#include "../Window/WindowWindows.hpp"
#include "../Render/OpenGL/RendererOpenGL.hpp"
#include "../Config/OSInfo.hpp"
#include "../ResourceManagers/MeshManager/MeshManager.hpp"
#include "../ResourceManagers/TextureManager/TextureManager.hpp"

namespace RedLightbulb
{
	RedLighbulb::~RedLighbulb()
	{
		if (m_isInitialised)
		{
			std::cout << "[WARNING] RedLightbulb is being destroyed without deinit() before!" << std::endl;
		}
	}

	Window& RedLighbulb::getWindow()
	{
		return *m_mainWindow;
	}

	void RedLighbulb::init(const WindowProperties& properties)
	{
		if (m_isInitialised)
		{
			//deinit?
		}
		else
		{
		#ifdef __OS_WINDOWS_64__
			m_mainWindow = std::unique_ptr<Window>(new WindowWindows());
		#endif
			m_mainWindow->create(properties);

			Renderer::createInstance(*m_mainWindow);
			MeshManager::createInstance();
			TextureManager::createInstance();

			m_isInitialised = true;
		}
	}

	void RedLighbulb::deinit()
	{
		if (m_isInitialised)
		{
			TextureManager::destroy();
			MeshManager::destroy();
			Renderer::destroyInstance();

			m_mainWindow->destroy();
			m_mainWindow.release();

			m_isInitialised = false;
		}
	}
	void RedLighbulb::render(const Camera& camera)
	{
		Renderer::getInstance().render(1.0f, camera);
	}
}
