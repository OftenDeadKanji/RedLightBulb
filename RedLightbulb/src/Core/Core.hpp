#ifndef __RED_LIGHTBULB_HPP__
#define __RED_LIGHTBULB_HPP__
#include "Window/Window.hpp"

namespace RedLightbulb
{
	class Camera;
	struct WindowProperties;

	class Core
	{
	public:
		~Core();

		void init(const WindowProperties&);
		void deinit();

		void render(const Camera& camera);

		Window* getWindowPtr();
	private:
		bool m_isInitialised{ false };
		std::unique_ptr<Window> m_mainWindow;
	};
}

#endif
