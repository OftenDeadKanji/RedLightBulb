#ifndef __MATERIAL_PBR_HPP__
#define __MATERIAL_PBR_HPP__
#include "Material.hpp"
#include "../Texture/Texture.hpp"

namespace RedLightbulb
{
	struct MaterialUnlit;

	struct MaterialPBR
		: public Material
	{
		Math::Vec3f baseColor = Math::Vec3f(1.0f, 1.0f, 1.0f);
		bool usesColorTexture = false;
		std::shared_ptr<Texture> baseColorTexture;

		bool usesNormalTexture = false;
		//texture

		float roughness = 1.0f;
		bool usesRoughnessTexture = false;
		//texture

		float metallic = 0.0f;
		bool usesMetallicTexture = false;
		//texture

		virtual MaterialUnlit toUnlit() override;
	};
}

#endif