#include "pch.h"
#include "Shader.hpp"

namespace RedLightbulb
{
	Shader::~Shader()
	{
		if (m_isInitialized)
		{
			std::cout << "[WARNING] Shader is being destroyed without explicit destroy() before." << std::endl;
		}
	}
	void Shader::create(std::string name, const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		m_name = std::move(name);
	}
}
