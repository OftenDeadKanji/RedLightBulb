#ifndef __MATH_HPP__
#define __MATH_HPP__
#include "../Dependencies/glm/glm.hpp"
#include "../Dependencies/glm/gtc/matrix_transform.hpp"
#include "../Dependencies/glm/gtx/quaternion.hpp"
#include "../Dependencies/glm/gtc/matrix_access.hpp"

namespace RedLightbulb
{
	using Vec2 = glm::vec2;
	using Vec2i = glm::ivec2;

	using Vec3 = glm::vec3;
	using Vec3i = glm::ivec3;

	using Vec4 = glm::vec4;
	using Vec4i = glm::ivec4;

	using Mat3 = glm::mat3;
	using Mat4 = glm::mat4;

	using Quat = glm::quat;
}

#endif