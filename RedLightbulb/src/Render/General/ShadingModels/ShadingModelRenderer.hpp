#pragma once

namespace RedLightbulb
{
	template<class ShaderType>
	class ShadingModelRenderer
	{
	public:
		virtual void render();
	protected:
		ShaderType m_shader;
	};
}
