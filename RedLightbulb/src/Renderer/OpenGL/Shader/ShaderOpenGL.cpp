#include "pch.h"
#include "ShaderOpenGL.hpp"
#include <fstream>
#include "../../../Utilities/Utilities.hpp"

namespace RedLightbulb
{
	ShaderOpenGL::ShaderOpenGL(std::string name)
		: Shader(name)
	{}

	void ShaderOpenGL::create(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		if (m_isInitialized)
		{
			//??
		}

		std::string vertexShaderCode, fragmentShaderCode;
		Utilities::readFile(vertexShaderFile, vertexShaderCode);
		Utilities::readFile(fragmentShaderFile, fragmentShaderCode);

		const char* vertexShaderCodeC = vertexShaderCode.c_str();
		const char* fragmentShaderCodeC = fragmentShaderCode.c_str();

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertexShader, 1, &vertexShaderCodeC, nullptr);
		glCompileShader(vertexShader);

		int success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char log[1024];
			glGetShaderInfoLog(vertexShader, 1024, nullptr, log);
			std::cout << "[ERROR] " << m_name << " - Vertex shader compilation failed: " << log << "\n";
		}

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char log[1024];
			glGetShaderInfoLog(fragmentShader, 1024, nullptr, log);
			std::cout << "[ERROR] " << m_name << " - Fragment shader compilation failed: " << log << "\n";
		}

		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			char log[1024];
			glGetProgramInfoLog(shaderProgram, 1024, nullptr, log);
			std::cout << "[ERROR] " << m_name << " - shader linkage failed: " << log << "\n";
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
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

	void ShaderOpenGL::loadVertexShaderFile(const std::string& vertexShaderFile)
	{
		std::ifstream shaderFile(vertexShaderFile);

		shaderFile.seekg(0, std::ios::end);
		size_t size = shaderFile.tellg();

		std::string buffer(size, ' ');

		shaderFile.seekg(0);
		shaderFile.read(&buffer[0], size);
	}
	void ShaderOpenGL::loadFragmentShaderFile(const std::string& vertexShaderFile)
	{
		std::ifstream shaderFile(vertexShaderFile);

		shaderFile.seekg(0, std::ios::end);
		size_t size = shaderFile.tellg();

		std::string buffer(size, ' ');

		shaderFile.seekg(0);
		shaderFile.read(&buffer[0], size);
	}
}