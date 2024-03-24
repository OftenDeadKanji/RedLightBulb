#pragma once
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
		static_assert(std::is_base_of<Shader, ShaderType>::value, "ShaderType must derive from RedLightbulb::Shader");

	public:
		using MaterialT = MaterialType;
		using InstanceT = InstanceType;
		using ShaderT = ShaderType;

		struct PerMaterialsSet
		{
			std::vector<sPtr<MaterialT>> materials;
			std::vector<InstanceT> instances;
		};

		struct PerMesh
		{
			sPtr<Mesh> mesh{};
			std::vector<PerMaterialsSet> perMaterialsSet;
		};

	public:
		virtual void create() = 0;
		virtual void destroy() = 0;

		void setDefaultMaterial(sPtr<MaterialT> material);

		virtual void render(const Camera& camera) = 0;

		virtual void addMesh(sPtr<Mesh> mesh, std::vector<sPtr<MaterialT>>& perSubMeshes, InstanceT instance);
	protected:
		virtual void createBuffer(PerMesh& perMesh) = 0;
		virtual sPtr<MaterialT> castToAppropriateMaterial(sPtr<Material> material) = 0;

		std::vector<PerMesh> m_meshes;
		sPtr<MaterialT> m_defaultMaterial;

	};

	template<class MaterialType, class InstanceType>
	inline void ShadingModel<MaterialType, InstanceType>::setDefaultMaterial(sPtr<MaterialT> material)
	{
		m_defaultMaterial = material;
	}

	template<class MaterialType, class InstanceType>
	inline void ShadingModel<MaterialType, InstanceType>::addMesh(sPtr<Mesh> mesh, std::vector<sPtr<MaterialT>>& materials, InstanceT instance)
	{
		auto materialsCount = mesh->getMaterials().size();
		auto inMaterialsCount = materials.size();

		if (inMaterialsCount > materialsCount)
		{
			return;
		}

		if (inMaterialsCount < materialsCount)
		{
			materials.resize(materialsCount);
		}

		for (int i = 0; i < materialsCount; i++)
		{
			if (materials[i] == nullptr)
			{
				materials[i] = m_defaultMaterial;
			}
		}

		// do we already have this mesh?
		for (auto& perMesh : m_meshes)
		{
			if (perMesh.mesh == mesh) // yes
			{
				for (auto& perMaterialSet : perMesh.perMaterialsSet)
				{
					for (int i = 0; i < materialsCount; i++)
					{
						if (materials[i] == perMaterialSet.materials[i])
						{
							// we've found the same materials set - we can just add a new instance element
							perMaterialSet.instances.push_back(instance);

							return;
						}
					}
				}

				// we need to add a new materials set
				PerMaterialsSet newPerMaterialsSet;
				newPerMaterialsSet.materials = materials;
				newPerMaterialsSet.instances.push_back(instance);

				perMesh.perMaterialsSet.push_back(newPerMaterialsSet);

				return;
			}
		}

		// we add completely new mesh

		PerMaterialsSet perMaterialSet;
		perMaterialSet.materials = materials;
		perMaterialSet.instances.push_back(instance);

		PerMesh perMeshToAdd;
		perMeshToAdd.mesh = mesh;
		perMeshToAdd.perMaterialsSet.push_back(perMaterialSet);

		m_meshes.push_back(perMeshToAdd);
		createBuffer(m_meshes.back());
	}
}
