#pragma once
#include <vector>
#include "../Material/Material.hpp"

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
		using MaterialT = MaterialType;
		using InstanceT = InstanceType;

		struct PerMaterial
		{
			sPtr<MaterialT> material{};
			std::vector<InstanceT> instances;
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

		virtual void addMesh(const Mesh* mesh, InstanceT instance);
		virtual void addMesh(const Mesh* mesh, const std::vector<std::pair<const SubMesh*, sPtr<MaterialT>>>& subMeshesMaterials, InstanceT instance);
	protected:
		virtual void createBuffer(PerMesh& perMesh) = 0;
		virtual sPtr<MaterialT> castToAppropriateMaterial(sPtr<Material> material) = 0;

		std::vector<PerMesh> m_meshes;
	};

	template<class MaterialType, class InstanceType>
	inline void ShadingModel<MaterialType, InstanceType>::addMesh(const Mesh* mesh, InstanceT instance)
	{
		const auto& subMeshes = mesh->getSubMeshes();

		std::vector<std::pair<const SubMesh*, sPtr<MaterialT>>> materials;
		for (int i = 0; i < subMeshes.size(); i++)
		{
			auto material = castToAppropriateMaterial(subMeshes[i].getMaterial());
			//auto* material = subMeshes[i].getMaterial().get();
			//if (auto* materialPBR = dynamic_cast<MaterialPBR*>(material))
			//{
			//	std::shared_ptr<MaterialUnlit> materialUnlit = std::make_shared<MaterialUnlit>(*materialPBR);
			//}
			
			std::pair < const SubMesh*, sPtr<MaterialT>> pair1 = std::make_pair(&subMeshes[i], material);
			materials.push_back(pair1);
		}

		addMesh(mesh, materials, instance);
	}

	template<class MaterialType, class InstanceType>
	inline void ShadingModel<MaterialType, InstanceType>::addMesh(const Mesh* mesh, const std::vector<std::pair<const SubMesh*, sPtr<MaterialT>>>& subMeshesMaterials, InstanceT instance)
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
