#ifndef __MATERIAL_LIT_HPP__
#define __MATERIAL_LIT_HPP__

#include "Material.hpp"

namespace RedLightbulb
{
	class Texture;

	struct MaterialLit
		: public Material
	{
		Math::Vec3f baseColor = Math::Vec3f(1.0f, 1.0f, 1.0f);
		sPtr<Texture> baseColorTexture;

		std::shared_ptr<Texture> normalTexture;

		float roughness = 0.0f;
		bool usesRoughnessTexture = false;

		float metallic = 0.0f;
		bool usesMetallicTexture = false;
		
		sPtr<Texture> ARMTexture;

		MaterialLit() = default;
		explicit MaterialLit(const MaterialUnlit&);

		virtual MaterialUnlit toUnlit() override;
		virtual MaterialLit toLit() override;
	};
}
#endif
