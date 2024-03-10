#ifndef __MATERIAL_MANAGER_HPP__
#define __MATERIAL_MANAGER_HPP__

namespace RedLightbulb
{
	class Material;

	class MaterialManager
	{
	public:
		static MaterialManager& createInstance();
		static MaterialManager& getInstance();
		static MaterialManager* getInstancePtr();
		static void destroy();

		sPtr<Material> addMaterial(const sPtr<Material>& material, const std::string& materialName);
		sPtr<Material> getMaterial(const std::string& materialName);
	private:
		static uPtr<MaterialManager> s_instance;

		std::unordered_map<std::string, sPtr<Material>> m_materials;
	};
}
#endif
