#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__
#include "ShadingModels/UnlitShadingModel.hpp"

namespace RedLightbulb
{
	class Window;

	class Renderer : public Utilities::NonCopyable
	{
	protected:
		Renderer() = default;
	public:
		static Renderer& createInstance(Window&);
		static Renderer& getInstance();
		static void destroyInstance();

		virtual void init() = 0;
		virtual void deinit() = 0;

		virtual void render(float deltaTime) = 0;
		
		virtual void addUnlitMesh(const Mesh* mesh, const std::vector<std::pair<Mesh::SubMesh*, UnlitShadingModel::Material*>>& subMeshesMaterials, UnlitShadingModel::Instance instance);
	protected:
		static std::unique_ptr<Renderer> s_instance;
		Window* m_window;
	};
}
#endif