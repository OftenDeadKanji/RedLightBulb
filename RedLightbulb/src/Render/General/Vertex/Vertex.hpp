#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__
#include "../../../Math/Math.hpp"

namespace RedLightbulb
{
	struct Vertex
	{
		Math::Vec3f position;
		Math::Vec3f color;
		Math::Vec2f texCoord;
		Math::Vec3f normal;
		Math::Vec3f tangent;
		Math::Vec3f bitangent;
	};
}

#endif