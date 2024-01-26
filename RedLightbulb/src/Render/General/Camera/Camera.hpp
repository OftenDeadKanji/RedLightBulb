#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

namespace RedLightbulb
{
	class Camera
	{
	public:
		void setPerspective(float fov, float aspect, float near, float far);

		void lookAt(const Math::Vec3f& position, const Math::Vec3f& target, const Math::Vec3f& up = Math::Vec3f(0.0f, 1.0f, 0.0f));

		void addLocalPosition(const Math::Vec3f& position);
		void addWorldPosition(const Math::Vec3f& position);
		void setWorldPosition(const Math::Vec3f& position);

		void addLocalRotation(const Math::Quat& rotation, bool rollEnabled = false);
		void addLocalRotation(const Math::Vec3f& rotation, bool rollEnabled = false);
		void addWorldRotation(const Math::Quat& rotation);
		void addWorldRotation(const Math::Vec3f& rotation);
		void setWorldRotation(const Math::Quat& rotation);
		void setWorldRotation(const Math::Vec3f& rotation);

		Math::Vec3f getPosition() const;
		Math::Vec3f getRight() const;
		Math::Vec3f getUp() const;
		Math::Vec3f getForward() const;

		const Math::Mat4f& getView() const;
		const Math::Mat4f& getViewInv() const;

		const Math::Mat4f& getProj() const;
		const Math::Mat4f& getProjInv() const;

		const Math::Mat4f& getViewProj() const;
		const Math::Mat4f& getViewProjInv() const;

		void update();
	private:
		void updateBasis();
		void updateMatrices();

		Math::Mat4f m_view = Math::Mat4f::Identity();
		Math::Mat4f m_viewInv = Math::Mat4f::Identity();

		Math::Mat4f m_proj = Math::Mat4f::Identity();
		Math::Mat4f m_projInv = Math::Mat4f::Identity();

		Math::Mat4f m_viewProj = Math::Mat4f::Identity();
		Math::Mat4f m_viewProjInv = Math::Mat4f::Identity();

		Math::Quat m_rotation = Math::Quat::Identity();

		bool m_updateMatrices = false;
		bool m_updateBasis = false;
	};
}

#endif