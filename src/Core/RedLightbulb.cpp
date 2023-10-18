#include "RedLightbulb.hpp"
#include "../Window/WindowWindows.hpp"
#include "../Renderer/RendererOpenGL.hpp"
#include "../Config/OSInfo.hpp"

namespace RedLightbulb
{

	RedLighbulb::~RedLighbulb()
	{
		deinit();
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
			m_mainWindow = new WindowWindows();
			m_mainWindow->create(properties);
		#endif
			Renderer::createInstance(*m_mainWindow);
		}
	}

	void RedLighbulb::deinit()
	{
		if (m_isInitialised)
		{
			m_mainWindow->destroy();
			delete m_mainWindow;
		}
	}
	void RedLighbulb::render()
	{
		Renderer::getInstance().render(1.0f);
	}
}
