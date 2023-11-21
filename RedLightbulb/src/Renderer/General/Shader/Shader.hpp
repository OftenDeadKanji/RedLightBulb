#pragma once
#include <string>
#include "../../../Math/Math.hpp"

namespace RedLightbulb
{
	class Shader
	{
	public:
		virtual ~Shader();

		virtual void create(std::string name, const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
		virtual void destroy() = 0;

		virtual void setIntUniform(int value) = 0;
		virtual void setFloatUniform(float value) = 0;
		virtual void setVec2Uniform(const Vec2& value) = 0;
		virtual void setVec2iUniform(const Vec2i& value) = 0;
		virtual void setVec3Uniform(const Vec3& value) = 0;
		virtual void setVec4Uniform(const Vec4& value) = 0;
		virtual void setMat4Uniform(const Mat4& value) = 0;
	protected:
		bool m_isInitialized = false;
		std::string m_name;


	};
}
