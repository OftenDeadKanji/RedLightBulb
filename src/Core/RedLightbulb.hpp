#ifndef __RED_LIGHTBULB_HPP__
#define __RED_LIGHTBULB_HPP__
#include "../Window/Window.hpp"

namespace RedLightbulb
{
	struct WindowProperties;
	class RedLighbulb
	{
	public:
		~RedLighbulb();

		void init(const WindowProperties&);
		void deinit();

		Window& getWindow();
	private:
		bool m_isInitialised = false;
		Window m_mainWindow;
	};
}

#endif
