#pragma once
#include "ShadingModel.hpp"
#include "../Material/MaterialUnlit.hpp"

namespace RedLightbulb
{
	struct InstanceUnlit
	{
		Mat4f transform;
	};

	class UnlitShadingModel
		: public ShadingModel<MaterialUnlit, InstanceUnlit>
	{
	public:
		virtual void create() override;
		virtual void destroy() override;

		virtual void render(const Camera& camera) override;
	private:
		virtual void castToAppropriateMaterial(std::shared_ptr<RedLightbulb::Material> material) override;
	};
}
