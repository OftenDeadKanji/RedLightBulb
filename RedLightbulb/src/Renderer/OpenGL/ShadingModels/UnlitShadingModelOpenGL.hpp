#pragma once
#include "../../General/ShadingModels/UnlitShadingModel.hpp"
#include "../Shader/ShaderOpenGL.hpp"

namespace RedLightbulb
{
	class UnlitShadingModelOpenGL
		: public UnlitShadingModel
	{
	public:
		UnlitShadingModelOpenGL();

		virtual void create() override;
		virtual void destroy() override;

		virtual void render() override;
	private:
		bool m_isInitialized = false;

		ShaderOpenGL m_shader;
	};
}
