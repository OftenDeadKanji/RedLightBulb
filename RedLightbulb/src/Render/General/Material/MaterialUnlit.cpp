#include "pch.h"
#include "MaterialUnlit.hpp"
#include "MaterialPBR.hpp"

namespace RedLightbulb
{
	MaterialUnlit::MaterialUnlit(const MaterialPBR& materialPBR)
		: baseColor(materialPBR.baseColor), usesColorTexture(materialPBR.usesColorTexture)
	{}
}