#include "pch.h"
#include "MaterialPBR.hpp"
#include "MaterialUnlit.hpp"

namespace RedLightbulb
{
    MaterialUnlit MaterialPBR::toUnlit()
    {
        return MaterialUnlit(*this);
    }
}
