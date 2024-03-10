#ifndef __MATH_HPP__
#define __MATH_HPP__
#include "../Dependencies/Eigen/Dense"

namespace Math
{
	using Vec2f = Eigen::Matrix<float, 2, 1, Eigen::ColMajor>;
	using Vec2i = Eigen::Matrix<int,   2, 1, Eigen::ColMajor>;

	using Vec3f = Eigen::Matrix<float, 3, 1, Eigen::ColMajor>;
	using Vec3i = Eigen::Matrix<int,   3, 1, Eigen::ColMajor>;

	using Vec4f = Eigen::Matrix<float, 4, 1, Eigen::ColMajor>;
	using Vec4i = Eigen::Matrix<int,   4, 1, Eigen::ColMajor>;

	using Mat3f = Eigen::Matrix<float, 3, 3, Eigen::ColMajor>;
	using Mat4f = Eigen::Matrix<float, 4, 4, Eigen::ColMajor>;

	using Quat = Eigen::Quaternion<float>;

	constexpr float PI = 3.141592653589793238f;

	float deg2rad(float deg);

	Mat4f createPerspectiveMatrix(float fov, float aspect, float near, float far);

	Mat4f lookAt(const Math::Vec3f& position, const Math::Vec3f& target, const Math::Vec3f& up = Math::Vec3f(0.0f, 1.0f, 0.0f));
	void invertOrthonormal(const Math::Mat4f& src, Math::Mat4f& dst);
}

#endif