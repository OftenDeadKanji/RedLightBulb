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
	
	void UnlitShadingModel::castToAppropriateMaterial(std::shared_ptr<RedLightbulb::Material> material)
	{
		std::shared_ptr<MaterialUnlit> materialUnlit = std::make_shared<MaterialUnlit>(material->toUnlit());
	}
}