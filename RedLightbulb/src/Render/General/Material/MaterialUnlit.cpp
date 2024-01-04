#include "pch.h"
#include "MaterialUnlit.hpp"
#include "MaterialPBR.hpp"

namespace RedLightbulb
{
	MaterialUnlit::MaterialUnlit(const MaterialPBR& materialPBR)
		: baseColor(materialPBR.baseColor), usesColorTexture(materialPBR.usesColorTexture), baseColorTexture(materialPBR.baseColorTexture)
	{}
	MaterialUnlit MaterialUnlit::toUnlit()
	{
		return *this;
	}
}