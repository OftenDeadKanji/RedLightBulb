#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

namespace RedLightbulb
{
	class Camera
	{
	public:
		void setPerspective(float fov, float aspect, float near, float far);

		void lookAt(const Vec3f& position, const Vec3f& target, const Vec3f& up = Vec3f(0.0f, 1.0f, 0.0f));

		void addLocalPosition(const Vec3f& position);
		void addWorldPosition(const Vec3f& position);
		void setWorldPosition(const Vec3f& position);

		void addLocalRotation(const Quat& rotation, bool rollEnabled = false);
		void addLocalRotation(const Vec3f& rotation, bool rollEnabled = false);
		void addWorldRotation(const Quat& rotation);
		void addWorldRotation(const Vec3f& rotation);
		void setWorldRotation(const Quat& rotation);
		void setWorldRotation(const Vec3f& rotation);

		Vec3f getPosition() const;
		Vec3f getRight() const;
		Vec3f getUp() const;
		Vec3f getForward() const;

		const Mat4f& getView() const;
		const Mat4f& getViewInv() const;

		const Mat4f& getProj() const;
		const Mat4f& getProjInv() const;

		const Mat4f& getViewProj() const;
		const Mat4f& getViewProjInv() const;

		void update();
	private:
		void updateBasis();
		void updateMatrices();

		Mat4f m_view = Mat4f::Identity();
		Mat4f m_viewInv = Mat4f::Identity();

		Mat4f m_proj = Mat4f::Identity();
		Mat4f m_projInv = Mat4f::Identity();

		Mat4f m_viewProj = Mat4f::Identity();
		Mat4f m_viewProjInv = Mat4f::Identity();

		Quat m_rotation = Quat::Identity();

		bool m_updateMatrices = false;
		bool m_updateBasis = false;
	};
}

#endif