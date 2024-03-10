#include "pch.h"
#include "Core.hpp"
#include "Config/OSInfo.hpp"
#include "Render/OpenGL/RendererOpenGL.hpp"
#include "ResourceManagers/MeshManager/MeshManager.hpp"
#include "ResourceManagers/TextureManager/TextureManager.hpp"
#include "ResourceManagers/MaterialManager/MaterialManager.hpp"
#include "Window/WindowWindows.hpp"

namespace RedLightbulb
{
	Core::~Core()
	{
		if (m_isInitialised)
		{
			std::cout << "[WARNING] RedLightbulb is being destroyed without deinit() before!" << std::endl;
		}
	}

	Window* Core::getWindowPtr()
	{
		return m_mainWindow.get();
	}

	void Core::init(const WindowProperties& properties)
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
			MaterialManager::createInstance();

			m_isInitialised = true;
		}
	}

	void Core::deinit()
	{
		if (m_isInitialised == false)
		{
			return;
		}

		MaterialManager::destroy();
		TextureManager::destroy();
		MeshManager::destroy();
		Renderer::destroyInstance();

		m_mainWindow->destroy();
		m_mainWindow.release();

		m_isInitialised = false;
	}

	void Core::render(const Camera& camera)
	{
		Renderer::getInstance().render(1.0f, camera);

		m_mainWindow->swapBuffers();
	}
}
