#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__
#include "TextureType.hpp"

namespace RedLightbulb
{
	class Texture
	{
	public:
		explicit Texture(TextureType type);

	protected:
		TextureType m_type;
	};
}

#endif