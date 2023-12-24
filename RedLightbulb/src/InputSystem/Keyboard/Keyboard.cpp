#include "pch.h"
#include "Keyboard.hpp"

namespace RedLightbulb
{


	bool Keyboard::isPressed(KeyCode key)
	{
		return m_keys[static_cast<int>(key)];
	}
}