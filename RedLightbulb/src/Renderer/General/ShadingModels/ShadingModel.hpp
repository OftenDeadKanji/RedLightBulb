#pragma once
#include <vector>

namespace RedLightbulb
{
	class Mesh;

	class ShadingModel
	{
	public:
		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual void render() = 0;

	protected:
		std::vector<Mesh> m_meshes;
	};
}
