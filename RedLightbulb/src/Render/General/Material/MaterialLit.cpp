#include "pch.h"
#include "MaterialLit.hpp"
#include "MaterialUnlit.hpp"

namespace RedLightbulb
{
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
