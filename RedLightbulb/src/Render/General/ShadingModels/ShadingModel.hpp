#pragma once
#include <vector>
//#include "../Material/Material.hpp"

namespace RedLightbulb
{
	class Mesh;
	class SubMesh;
	class Camera;
	struct Material;

	template<class MaterialType, class InstanceType>
	class ShadingModel
	{
	public:
		using Material = MaterialType;
		using Instance = InstanceType;

		struct PerMaterial
		{
			Material* material{};
			std::vector<Instance> instances;
		};
		struct PerMesh
		{
			const Mesh* mesh{};
			std::vector<std::pair<const SubMesh*, PerMaterial>> submeshes;
		};

	public:
		virtual void create() = 0;
		virtual void destroy() = 0;

		virtual void render(const Camera& camera) = 0;

		virtual void addMesh(const Mesh* mesh, Instance instance);
		virtual void addMesh(const Mesh* mesh, const std::vector<std::pair<const SubMesh*, Material*>>& subMeshesMaterials, Instance instance);
	protected:
		virtual void createBuffer(PerMesh& perMesh) = 0;
		virtual void castToAppropriateMaterial(std::shared_ptr<RedLightbulb::Material> material) = 0;

		std::vector<PerMesh> m_meshes;
	};

	template<class MaterialType, class InstanceType>
	inline void ShadingModel<MaterialType, InstanceType>::addMesh(const Mesh* mesh, Instance instance)
	{
		const auto& subMeshes = mesh->getSubMeshes();

		std::vector<std::pair<const SubMesh*, Material*>> materials;
		for (int i = 0; i < subMeshes.size(); i++)
		{
			//auto* material = subMeshes[i].getMaterial().get();
			//if (auto* materialPBR = dynamic_cast<MaterialPBR*>(material))
			//{
			//	std::shared_ptr<MaterialUnlit> materialUnlit = std::make_shared<MaterialUnlit>(*materialPBR);
			//}
			
			materials.push_back(std::pair<const SubMesh*, Material*>(& subMeshes[i], nullptr));
		}

		addMesh(mesh, materials, instance);
	}

	template<class Material, class Instance>
	inline void ShadingModel<Material, Instance>::addMesh(const Mesh* mesh, const std::vector<std::pair<const SubMesh*, Material*>>& subMeshesMaterials, Instance instance)
	{
		PerMesh perMeshToAdd;
		perMeshToAdd.mesh = mesh;


		for (const auto& subMeshMaterial : subMeshesMaterials)
		{
			PerMaterial perMaterial;
			perMaterial.material = subMeshMaterial.second;
			perMaterial.instances.push_back(instance);

			std::pair<const SubMesh*, PerMaterial> subMeshToAdd = std::make_pair(subMeshMaterial.first, perMaterial);
			perMeshToAdd.submeshes.push_back(subMeshToAdd);
		}

		m_meshes.push_back(perMeshToAdd);
		createBuffer(m_meshes.back());
	}
}
