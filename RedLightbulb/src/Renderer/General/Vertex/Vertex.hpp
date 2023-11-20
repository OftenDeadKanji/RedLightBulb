#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__
#include "../../../Math/Math.hpp"

namespace RedLightbulb
{
	struct Vertex
	{
		Vec3 position;
		Vec3 color;
		Vec2 texCoord;
		Vec3 normal;
		Vec3 tangent;
		Vec3 bitangent;
	};
}

#endif