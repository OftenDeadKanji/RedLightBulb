#include "pch.h"
#include "UnlitShadingModel.hpp"

namespace RedLightbulb
{
	void UnlitShadingModel::create()
	{

	}

	void UnlitShadingModel::destroy()
	{

	}
	void UnlitShadingModel::render(const Camera& camera)
	{}
	
	std::shared_ptr<MaterialUnlit> UnlitShadingModel::castToAppropriateMaterial(std::shared_ptr<Material> material)
	{
		return std::make_shared<MaterialUnlit>(material->toUnlit());
	}
}