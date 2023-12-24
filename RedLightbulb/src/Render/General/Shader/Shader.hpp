#pragma once
#include <string>
#include "../../../Math/Math.hpp"

namespace RedLightbulb
{
	class Shader
	{
	public:
		Shader() = default;
		explicit Shader(std::string name);
		virtual ~Shader();

		virtual void create(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) = 0;
		virtual void destroy() = 0;

		virtual void bind() = 0;
	protected:
		bool m_isInitialized = false;
		std::string m_name;
	};
}
