#pragma once
#include "ShadingModel.hpp"

namespace RedLightbulb
{
	class UnlitShadingModel
		: public ShadingModel<int, int>
	{
	public:
		virtual void create() override;
		virtual void destroy() override;

		virtual void render() override;
	private:
		
	};
}
