#ifndef __RENDERER_OPENGL_HPP__
#define __RENDERER_OPENGL_HPP__
#include "Renderer.hpp"
#include "../Config/OSInfo.hpp"

#include "../Dependencies/OS/Windows.hpp"


namespace RedLightbulb
{
	class RendererOpenGL : public Renderer
	{
	public:
		void init() override;
		void deinit() override;

		void render(float deltaTime) override;
	private:
		HGLRC m_context;
	};
}
#endif