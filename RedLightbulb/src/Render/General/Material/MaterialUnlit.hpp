#ifndef __MATERIAL_UNLIT_HPP__
#define __MATERIAL_UNLIT_HPP__
#include "Material.hpp"
#include "../Texture/Texture.hpp"

namespace RedLightbulb
{
	struct MaterialPBR;
	struct MaterialLit;

	struct MaterialUnlit
		: public Material
	{
		Math::Vec3f baseColor = Math::Vec3f(1.0f, 1.0f, 1.0f);
		sPtr<Texture> baseColorTexture;

		MaterialUnlit() = default;
		explicit MaterialUnlit(const MaterialPBR&);
		explicit MaterialUnlit(const MaterialLit&);

		virtual MaterialUnlit toUnlit() override;
		virtual MaterialLit toLit() override;
	};
}

#endif