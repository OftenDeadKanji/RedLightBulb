#ifndef __RED_LIGHTBULB_HPP__
#define __RED_LIGHTBULB_HPP__
#include <memory>
#include "../Window/Window.hpp"
#include "../Render/General/Camera/Camera.hpp"

namespace RedLightbulb
{
	struct WindowProperties;
	class RedLighbulb
	{
	public:
		~RedLighbulb();

		void init(const WindowProperties&);
		void deinit();

		void render(const Camera& camera);

		Window& getWindow();
	private:
		bool m_isInitialised = false;
		std::unique_ptr<Window> m_mainWindow;
	};
}

#endif
