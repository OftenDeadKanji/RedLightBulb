#ifndef __RENDERER_OPENGL_HPP__
#define __RENDERER_OPENGL_HPP__
#include "../Renderer.hpp"
#include "../../Config/OSInfo.hpp"

#include "../../Dependencies/OS/Windows.hpp"
#include "ShadingModels/ShadingModelOpenGL.hpp"

namespace RedLightbulb
{
	class RendererOpenGL : public Renderer
	{
	public:
		void init() override;
		void deinit() override;

		void render(float deltaTime) override;
	private:
		void createContext();
		void initClearColors();

		void clearBuffers();

		HGLRC m_context;

		struct
		{
			Vec4 mainColorBuffer;
		} m_clearColors;

		//------------------------------------------------------
		// Shading models
		//------------------------------------------------------
		ShadingModelOpenGL m_unlitShadingModel;
	};
}
#endif