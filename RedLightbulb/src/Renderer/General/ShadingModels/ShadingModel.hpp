#pragma once
#include <vector>

namespace RedLightbulb
{
	class Mesh;

	template<class Material, class Instance>
	class ShadingModel
	{
	public:
		struct PerMaterial
		{
			Material* material;
			std::vector<Instance> instances;
		};
		//struct PerSubMesh
		//{
		//	SubMesh* subMesh;
		//	
		//};
		struct PerMesh
		{
			Mesh* mesh;
			std::vector<std::pair<SubMesh*, PerMaterial>> submeshes;
		};

	public:
		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual void render() = 0;

	protected:
		std::vector<Mesh*> m_meshes;
	};
}
