#include "pch.h"
#include "MaterialUnlit.hpp"
#include "MaterialLit.hpp"
#include "MaterialPBR.hpp"

namespace RedLightbulb
{
	MaterialUnlit::MaterialUnlit(const MaterialPBR& materialPBR)
		: baseColor(materialPBR.baseColor), baseColorTexture(materialPBR.baseColorTexture)
	{}
	MaterialUnlit::MaterialUnlit(const MaterialLit& materialLit)
		: baseColor(materialLit.baseColor), baseColorTexture(materialLit.baseColorTexture)
	{}
	MaterialUnlit MaterialUnlit::toUnlit()
	{
		return *this;
	}
	MaterialLit MaterialUnlit::toLit()
	{
		return MaterialLit(*this);
	}
}