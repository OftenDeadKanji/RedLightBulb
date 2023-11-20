#include "ShaderOpenGL.hpp"
#include <fstream>

namespace RedLightbulb
{
	void ShaderOpenGL::create(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		if (m_isInitialized)
		{
			//??
		}


	}

	void ShaderOpenGL::destroy()
	{}

	void ShaderOpenGL::setIntUniform(int value)
	{}

	void ShaderOpenGL::setFloatUniform(float value)
	{}

	void ShaderOpenGL::setVec2Uniform(const Vec2& value)
	{}

	void ShaderOpenGL::setVec2iUniform(const Vec2i& value)
	{}

	void ShaderOpenGL::setVec3Uniform(const Vec3& value)
	{}

	void ShaderOpenGL::setVec4Uniform(const Vec4& value)
	{}

	void ShaderOpenGL::setMat4Uniform(const Mat4& value)
	{}

	void ShaderOpenGL::loadVertexShaderFile(const std::string & vertexShaderFile)
	{
		std::ifstream shaderFile(vertexShaderFile);

		shaderFile.seekg(0, std::ios::end);
		size_t size = shaderFile.tellg();

		std::string buffer(size, ' ');

		shaderFile.seekg(0);
		shaderFile.read(&buffer[0], size);
	}
	void ShaderOpenGL::loadFragmentShaderFile(const std::string & vertexShaderFile)
	{
		std::ifstream shaderFile(vertexShaderFile);

		shaderFile.seekg(0, std::ios::end);
		size_t size = shaderFile.tellg();

		std::string buffer(size, ' ');

		shaderFile.seekg(0);
		shaderFile.read(&buffer[0], size);
	}
}