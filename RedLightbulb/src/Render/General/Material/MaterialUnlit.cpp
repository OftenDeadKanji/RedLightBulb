#include "pch.h"
#include "MaterialUnlit.hpp"
#include "MaterialLit.hpp"

namespace RedLightbulb
{
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