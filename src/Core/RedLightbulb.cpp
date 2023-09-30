#include "RedLightbulb.hpp"
#include "../Window/Window.hpp"

RedLightbulb::RedLighbulb::~RedLighbulb()
{
	deinit();
}

void RedLightbulb::RedLighbulb::init()
{
	if (m_isInitialised)
	{
		//deinit?
	}
	else
	{
		auto& window = Window::create();
		
	}
}

void RedLightbulb::RedLighbulb::deinit()
{
	if (m_isInitialised)
	{

	}
}
