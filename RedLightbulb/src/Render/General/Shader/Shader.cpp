#include "pch.h"
#include "Shader.hpp"

namespace RedLightbulb
{
	Shader::Shader(std::string name)
		: m_name(std::move(name))
	{}

	Shader::~Shader()
	{
		if (m_isInitialized)
		{
			std::cout << "[WARNING] Shader is being destroyed without explicit destroy() before." << std::endl;
		}
	}
}
