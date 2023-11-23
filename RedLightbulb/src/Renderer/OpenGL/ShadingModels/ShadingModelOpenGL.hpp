#pragma once
#include "../../General/ShadingModels/ShadingModel.hpp"
#include "../Shader/ShaderOpenGL.hpp"

namespace RedLightbulb
{
	class ShadingModelOpenGL
		: public ShadingModel
	{
	public:
		virtual void create() override;
		virtual void destroy() override;
	private:
		bool m_isInitialized = false;
		ShaderOpenGL shader;
	};
}
