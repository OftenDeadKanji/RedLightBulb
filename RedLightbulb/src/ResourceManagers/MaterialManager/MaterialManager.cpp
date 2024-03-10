#include "pch.h"
#include "MaterialManager.hpp"

namespace RedLightbulb
{
	std::unique_ptr<MaterialManager> MaterialManager::s_instance = nullptr;

	MaterialManager& MaterialManager::createInstance()
	{
		s_instance = uPtr<MaterialManager>(new MaterialManager());

		return *s_instance;
	}
	MaterialManager& MaterialManager::getInstance()
	{
		return *s_instance;
	}
	MaterialManager* MaterialManager::getInstancePtr()
	{
		return s_instance.get();
	}
	void MaterialManager::destroy()
	{
		s_instance.release();
	}

	sPtr<Material> MaterialManager::addMaterial(const sPtr<Material>& material, const std::string& materialName)
	{
		auto result = m_materials.insert(std::make_pair(materialName, material));
		return result.first->second;
	}

	sPtr<Material> MaterialManager::getMaterial(const std::string& materialName)
	{
		if (m_materials.contains(materialName))
		{
			return m_materials.at(materialName);
		}

		return nullptr;
	}

}
