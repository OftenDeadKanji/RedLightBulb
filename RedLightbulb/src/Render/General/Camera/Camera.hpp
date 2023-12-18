#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

namespace RedLightbulb
{
	class Camera
	{
	public:
		void setPerspective(float fov, float aspect, float near, float far);

		void lookAt(const Vec3& position, const Vec3& target, const Vec3& up = Vec3(0.0f, 1.0f, 0.0f));

		void addLocalPosition(const Vec3& position);
		void addWorldPosition(const Vec3& position);
		void setWorldPosition(const Vec3& position);

		void addLocalRotation(const Quat& rotation);
		void addLocalRotation(const Vec3& rotation);
		void addWorldRotation(const Quat& rotation);
		void addWorldRotation(const Vec3& rotation);
		void setWorldRotation(const Quat& rotation);
		void setWorldRotation(const Vec3& rotation);

		Vec3 getPosition() const;
		Vec3 getRight() const;
		Vec3 getUp() const;
		Vec3 getForward() const;

		const Mat4& getView() const;
		const Mat4& getViewInv() const;

		const Mat4& getProj() const;
		const Mat4& getProjInv() const;

		const Mat4& getViewProj() const;
		const Mat4& getViewProjInv() const;

		void setIsRollEnabled(bool enabled);

		void update();
	private:
		void updateBasis();
		void updateMatrices();

		Mat4 m_view = Mat4(1.0);
		Mat4 m_viewInv = Mat4(1.0);

		Mat4 m_proj = Mat4(1.0);
		Mat4 m_projInv = Mat4(1.0);

		Mat4 m_viewProj = Mat4(1.0);
		Mat4 m_viewProjInv = Mat4(1.0);

		Quat m_rotation = Quat(1.0f, 0.0f, 0.0f, 0.0f);

		bool m_isRollEnabled = false;

		bool m_updateMatrices = false;
		bool m_updateBasis = false;
	};
}

#endif