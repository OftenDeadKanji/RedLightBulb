#ifndef __MATERIAL_UNLIT_HPP__
#define __MATERIAL_UNLIT_HPP__
#include "Material.hpp"
#include "../Texture/Texture.hpp"

namespace RedLightbulb
{
	struct MaterialPBR;

	struct MaterialUnlit
		: public Material
	{
		Vec3f baseColor = Vec3f(1.0f, 1.0f, 1.0f);
		bool usesColorTexture = false;
		//texture

		std::shared_ptr<Texture> baseColorTexture;

		MaterialUnlit() = default;
		explicit MaterialUnlit(const MaterialPBR&);

		virtual MaterialUnlit toUnlit() override;
	};
}

#endif