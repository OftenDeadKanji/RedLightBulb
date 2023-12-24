#ifndef __MATERIAL_UNLIT_HPP__
#define __MATERIAL_UNLIT_HPP__
#include "Material.hpp"

namespace RedLightbulb
{
	struct MaterialPBR;

	struct MaterialUnlit
		: public Material
	{
		Vec3f baseColor = Vec3f(1.0f, 1.0f, 1.0f);
		bool usesColorTexture = false;
		//texture

		explicit MaterialUnlit(const MaterialPBR&);
	};
}

#endif