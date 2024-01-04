#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__
#include "ShadingModels/UnlitShadingModel.hpp"
#include "Camera/Camera.hpp"

namespace RedLightbulb
{
	class Window;
	class Camera;

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

		virtual void render(float deltaTime, const Camera& camera) = 0;
		
		virtual void addUnlitMesh(const Mesh* mesh, UnlitShadingModel::InstanceT instance);
		virtual void addUnlitMesh(const Mesh* mesh, const std::vector<std::pair<const SubMesh*, sPtr<UnlitShadingModel::MaterialT>>>& subMeshesMaterials, UnlitShadingModel::InstanceT instance);
	protected:
		static std::unique_ptr<Renderer> s_instance;
		Window* m_window;

		//------------------------------------------------------
		// Shading models
		//------------------------------------------------------
		UnlitShadingModel* m_unlitShadingModels;
	};
}
#endif