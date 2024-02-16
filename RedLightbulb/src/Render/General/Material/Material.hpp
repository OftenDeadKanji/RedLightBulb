#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

namespace RedLightbulb
{
	struct MaterialUnlit;
	struct MaterialLit;

	struct Material
	{
		std::string name;

		bool operator==(const Material& other);
		bool operator!=(const Material& other);

		virtual MaterialUnlit toUnlit() = 0;
		virtual MaterialLit toLit() = 0;
	};
}

#endif