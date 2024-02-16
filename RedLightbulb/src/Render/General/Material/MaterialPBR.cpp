#include "pch.h"
#include "MaterialPBR.hpp"
#include "MaterialUnlit.hpp"
#include "MaterialLit.hpp"

namespace RedLightbulb
{
    MaterialUnlit MaterialPBR::toUnlit()
    {
        return MaterialUnlit(*this);
    }
    MaterialLit MaterialPBR::toLit()
    {
        return MaterialLit(*this);
    }
}
