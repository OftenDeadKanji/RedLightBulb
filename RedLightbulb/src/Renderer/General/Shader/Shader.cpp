#include "Shader.hpp"
#include <iostream>

namespace RedLightbulb
{
	Shader::~Shader()
	{
		if (m_isInitialized)
		{
			std::cout << "[WARNING] Shader is being destroyed without explicit destroy() before." << std::endl;
		}
	}
}
