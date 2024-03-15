#pragma once
#include "../../General/Shader/Shader.hpp"


namespace RedLightbulb
{
	class ShaderOpenGL : public Shader
	{
	public:
		ShaderOpenGL() = default;
		explicit ShaderOpenGL(std::string name);

		void create(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) override;
		void destroy() override;

		void bind() override;

		void setInt(int value, const std::string& name) const;
	private:
		GLuint m_id = 0;
	};
}
