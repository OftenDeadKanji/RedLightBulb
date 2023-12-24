#include "pch.h"

namespace RedLightbulb::Math
{
    float deg2rad(float deg)
    {
        return (deg * PI) / 180.0f;
    }
    Mat4f createPerspectiveMatrix(float fov, float aspect, float near, float far)
    {
        float ctg = 1.0f / (std::tanf(deg2rad(fov * 0.5f)));

        Mat4f mat;
        mat <<
            (ctg / aspect),     0.0f,     0.0f,                            0.0f,
            0.0f,               ctg,      0.0f,                            0.0f,
            0.0f,               0.0f,     (-far - near) / (near - far),    (2.0f * far * near) / (near - far),
            0.0f,               0.0f,     1.0f,                            0.0f;

        return mat;
    }
    Mat4f lookAt(const Vec3f& position, const Vec3f& target, const Vec3f& up)
    {
        Vec3f f = (target - position).normalized();
        Vec3f r = f.cross(up).normalized();
        Vec3f u = r.cross(f);

        Mat4f matrix;
        matrix <<
            r.x(), u.x(), f.x(), -r.dot(position),
            r.y(), u.y(), f.y(), -u.dot(position),
            r.z(), u.z(), f.z(),  f.dot(position),
            0.0f, 0.0f, 0.0f, 1.0f;

        return matrix;
    }
    void invertOrthonormal(const Mat4f& src, Mat4f& dst)
    {
        dst.block(0, 0, 3, 3) = src.block(0, 0, 3, 3).transpose();

        const Vec3f& pos = src.col(3).head<3>();

        dst.col(3).head<3>() =
            -pos[0] * dst.col(0).head<3>() +
            -pos[1] * dst.col(1).head<3>() +
            -pos[2] * dst.col(2).head<3>();

        dst.row(3) = Vec4f(0.0f, 0.0f, 0.0f, 1.0f);
    }
}