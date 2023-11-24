#ifndef __RENDERER_OPENGL_HPP__
#define __RENDERER_OPENGL_HPP__
#include "../General/Renderer.hpp"
#include "../../Config/OSInfo.hpp"

#include "../../Dependencies/OS/Windows.hpp"
#include "ShadingModels/UnlitShadingModelOpenGL.hpp"

namespace RedLightbulb
{
	class RendererOpenGL : public Renderer
	{
	public:
		void init() override;
		void deinit() override;

		void render(float deltaTime) override;

		void addUnlitMesh(UnlitShadingModelOpenGL::);
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
		UnlitShadingModelOpenGL m_unlitShadingModel;
	};
}
#endif