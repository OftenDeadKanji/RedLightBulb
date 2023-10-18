#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__
#include <memory>

namespace RedLightbulb
{
	class Window;

	class Renderer
	{
	protected:
		Renderer() = default;
	public:
		static Renderer& getInstance();
		static Renderer& createInstance(Window&);
		static void destroyInstance();

		virtual void init() = 0;
		virtual void deinit() = 0;

		virtual void render(float deltaTime) = 0;
	protected:
		static std::unique_ptr<Renderer> s_instance;
		Window* m_window;
	};
}
#endif