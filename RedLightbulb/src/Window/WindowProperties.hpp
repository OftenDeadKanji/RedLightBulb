#ifndef __WINDOW_PROPERTIES_HPP__
#define __WINDOW_PROPERTIES_HPP__
#include <string>

namespace RedLightbulb
{
	struct WindowProperties
	{
		enum class Mode
		{
			Windowed,
			Fullscreen,
			WindowedFullscreen
		};

		int width;
		int height;
		//int refreshRate;
		Mode mode;
		std::string title;
		bool isResizeable;
	};
}

#endif
