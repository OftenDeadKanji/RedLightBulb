#include "pch.h"
#include "Material.hpp"

namespace RedLightbulb
{
	bool Material::operator==(const Material& other)
	{
		return name == other.name;
	}
	bool Material::operator!=(const Material& other)
	{
		return !(*this == other);
	}
}