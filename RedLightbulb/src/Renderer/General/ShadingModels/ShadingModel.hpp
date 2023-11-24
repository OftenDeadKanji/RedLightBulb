#pragma once
#include <vector>

namespace RedLightbulb
{
	class Mesh;
	class SubMesh;
	

	template<class MaterialType, class InstanceType>
	class ShadingModel
	{
	public:
		using Material = MaterialType;
		using Instance = InstanceType;

		struct PerMaterial
		{
			Material* material;
			std::vector<Instance> instances;
		};
		struct PerMesh
		{
			const Mesh* mesh;
			std::vector<std::pair<Mesh::SubMesh*, PerMaterial>> submeshes;
		};

	public:
		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual void render() = 0;

		virtual void addMesh(const Mesh* mesh, const std::vector<std::pair<Mesh::SubMesh*, Material*>>& subMeshesMaterials, Instance instance);
	protected:
		virtual void createBuffer(PerMesh& perMesh) = 0;

		std::vector<PerMesh> m_meshes;
	};

	template<class Material, class Instance>
	inline void ShadingModel<Material, Instance>::addMesh(const Mesh* mesh, const std::vector<std::pair<Mesh::SubMesh*, Material*>>& subMeshesMaterials, Instance instance)
	{
		PerMesh perMeshToAdd;
		perMeshToAdd.mesh = mesh;

		for (const auto& subMeshMaterial : subMeshesMaterials)
		{
			PerMaterial perMaterial;
			perMaterial.material = subMeshMaterial.second;
			perMaterial.instances.push_back(instance);

			std::pair<Mesh::SubMesh*, PerMaterial> subMeshToAdd = std::make_pair(subMeshMaterial.first, perMaterial);
			perMeshToAdd.submeshes.push_back(subMeshToAdd);
		}

		m_meshes.push_back(perMeshToAdd);
	}
}
