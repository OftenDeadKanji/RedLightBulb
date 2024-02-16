#include "pch.h"
#include "MaterialLit.hpp"
#include "MaterialUnlit.hpp"
#include "MaterialPBR.hpp"

namespace RedLightbulb
{
	MaterialLit::MaterialLit(const MaterialPBR& materialPBR)
		: baseColor(materialPBR.baseColor), baseColorTexture(materialPBR.baseColorTexture),
		normalTexture(materialPBR.normalTexture),
		metallic(materialPBR.metallic), usesMetallicTexture(materialPBR.usesMetallicTexture),
		roughness(materialPBR.roughness), usesRoughnessTexture(materialPBR.usesRoughnessTexture),
		ARMTexture(materialPBR.ARMTexture)
	{}

	MaterialLit::MaterialLit(const MaterialUnlit& materialUnlit)
		: baseColor(materialUnlit.baseColor), baseColorTexture(materialUnlit.baseColorTexture)
	{}
	MaterialUnlit MaterialLit::toUnlit()
	{
		return MaterialUnlit(*this);
	}
	MaterialLit MaterialLit::toLit()
	{
		return MaterialLit(*this);
	}
}
