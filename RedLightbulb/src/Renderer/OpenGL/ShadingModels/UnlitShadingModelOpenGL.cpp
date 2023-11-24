#include "pch.h"
#include "UnlitShadingModelOpenGL.hpp"

namespace RedLightbulb
{
	UnlitShadingModelOpenGL::UnlitShadingModelOpenGL()
		: m_shader("Unlit")
	{}

	void UnlitShadingModelOpenGL::create()
	{
		if (m_isInitialized)
		{
			// ???
		}

		m_shader.create("Shaders/Unlit/UnlitVS.glsl", "Shaders/Unlit/UnlitFS.glsl");
	}

	void UnlitShadingModelOpenGL::destroy()
	{
		if (m_isInitialized)
		{
			m_isInitialized = false;
		}
	}

	void UnlitShadingModelOpenGL::render()
	{
		UnlitShadingModel::render();


	}
}