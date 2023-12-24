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
	private:
		void loadVertexShaderFile(const std::string& vertexShaderFile);
		void loadFragmentShaderFile(const std::string& vertexShaderFile);

		GLuint m_id;
	};
}
