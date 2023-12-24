#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

namespace RedLightbulb
{
	struct Material
	{
		std::string name;

		bool operator==(const Material& other);
		bool operator!=(const Material& other);
	};
}

#endif