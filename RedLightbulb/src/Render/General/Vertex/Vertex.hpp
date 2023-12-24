#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__
#include "../../../Math/Math.hpp"

namespace RedLightbulb
{
	struct Vertex
	{
		Vec3f position;
		Vec3f color;
		Vec2f texCoord;
		Vec3f normal;
		Vec3f tangent;
		Vec3f bitangent;
	};
}

#endif