#include "pch.h"
#include "Camera.hpp"

namespace RedLightbulb
{
	void Camera::setPerspective(float fov, float aspect, float near, float far)
	{
		m_proj = glm::perspective(fov, aspect, near, far);
		m_projInv = glm::inverse(m_proj);
	
		m_updateMatrices = true;
	}
	void Camera::lookAt(const Vec3& position, const Vec3& target, const Vec3& up)
	{
		Mat4 lookAtMatrix = glm::lookAt(position, target, up);
		Mat3 lookAtMatrix3 = lookAtMatrix;
		//Mat3 lookAtMatrix3T = glm::transpose(lookAtMatrix3);
		m_rotation = Quat(lookAtMatrix3);

		setWorldPosition(position);

		m_updateBasis = true;
		m_updateMatrices = true;
	}

	void Camera::addLocalPosition(const Vec3& position)
	{
		updateBasis();
	
		m_viewInv[3] += Vec4(getRight() * position.x + getUp() * position.y + getForward() * position.z, 0.0f);
		m_updateMatrices = true;
	}
	void Camera::addWorldPosition(const Vec3& position)
	{
		m_viewInv[3] += Vec4(position, 0.0f);
		m_updateMatrices = true;
	}
	void Camera::setWorldPosition(const Vec3& position)
	{
		m_viewInv[3] = Vec4(position, 1.0f);
		m_updateMatrices = true;
	}
	void Camera::addLocalRotation(const Quat& rotation)
	{
		Vec3 rotationEuler = glm::eulerAngles(rotation);
		addLocalRotation(rotationEuler);
	}
	void Camera::addLocalRotation(const Vec3& rotation)
	{
		if (m_isRollEnabled)
		{
			m_rotation = glm::rotate(m_rotation, rotation.z, getForward());
			m_rotation = glm::rotate(m_rotation, rotation.x, getRight());
			m_rotation = glm::rotate(m_rotation, rotation.y, getUp());
		}
		else
		{
			m_rotation = glm::rotate(m_rotation, rotation.x, getRight());
			m_rotation = glm::rotate(m_rotation, rotation.y, Vec3(0.0f, 1.0f, 0.0f));
		}

		m_updateBasis = true;
		m_updateMatrices = true;
	}
	void Camera::addWorldRotation(const Quat& rotation)
	{
		Quat rot = rotation;
		if (!m_isRollEnabled)
		{
			Vec3 rotationEuler = glm::eulerAngles(rotation);
			rotationEuler.z = 0.0f;
			rot = Quat(rotationEuler);
		}
	
		m_rotation *= rot;
		m_updateBasis = true;
		m_updateMatrices = true;
	}
	void Camera::addWorldRotation(const Vec3& rotation)
	{
		Quat rot = rotation;
		if (!m_isRollEnabled)
		{
			Vec3 rotationEuler = rotation;
			rotationEuler.z = 0.0f;
			rot = Quat(rotationEuler);
		}

		m_rotation *= rot;
		m_updateBasis = true;
		m_updateMatrices = true;
	}
	void Camera::setWorldRotation(const Quat& rotation)
	{
		m_rotation = rotation;

		m_updateBasis = true;
		m_updateMatrices = true;
	}
	void Camera::setWorldRotation(const Vec3& rotation)
	{
		Quat rot = rotation;
		m_rotation = rotation;

		m_updateBasis = true;
		m_updateMatrices = true;
	}
	Vec3 Camera::getPosition() const
	{
		return Vec3(m_viewInv[3][0], m_viewInv[3][1], m_viewInv[3][2]);
	}
	Vec3 Camera::getRight() const
	{
		return Vec3(m_viewInv[0][0], m_viewInv[0][1], m_viewInv[0][2]);
	}
	Vec3 Camera::getUp() const
	{
		return Vec3(m_viewInv[1][0], m_viewInv[1][1], m_viewInv[1][2]);
	}
	Vec3 Camera::getForward() const
	{
		return Vec3(m_viewInv[2][0], m_viewInv[2][1], m_viewInv[2][2]);
	}
	const Mat4& Camera::getView() const
	{
		return m_view;
	}
	const Mat4& Camera::getViewInv() const
	{
		return m_viewInv;
	}
	const Mat4& Camera::getProj() const
	{
		return m_proj;
	}
	const Mat4& Camera::getProjInv() const
	{
		return m_projInv;
	}
	const Mat4& Camera::getViewProj() const
	{
		return m_viewProj;
	}
	const Mat4& Camera::getViewProjInv() const
	{
		return m_viewProjInv;
	}
	void Camera::setIsRollEnabled(bool enabled)
	{
		m_isRollEnabled = enabled;
	}
	void Camera::update()
	{
		m_rotation = glm::normalize(m_rotation);
	
		updateBasis();
		updateMatrices();
	}
	void Camera::updateBasis()
	{
		if (m_updateBasis)
		{
			m_updateBasis = false;

			Mat4 rotationMat = glm::toMat4(m_rotation);
			
			m_viewInv[0] = rotationMat[0];
			m_viewInv[1] = rotationMat[1];
			m_viewInv[2] = rotationMat[2];
		}
	}
	void Camera::updateMatrices()
	{
		if (!m_updateMatrices)
		{
			return;
		}
		m_updateMatrices = false;
		
		updateBasis();
		
		//viewInv -> view
		m_view[0][0] = m_viewInv[0][0];  m_view[1][0] = m_viewInv[0][1];  m_view[2][0] = m_viewInv[0][2];
		m_view[0][1] = m_viewInv[1][0];  m_view[1][1] = m_viewInv[1][1];  m_view[2][1] = m_viewInv[1][2];
		m_view[0][2] = m_viewInv[2][0];  m_view[1][2] = m_viewInv[2][1];  m_view[2][2] = m_viewInv[2][2];
		
		//Vec3 pos(m_viewInv[3][0], m_viewInv[3][1], m_viewInv[3][2]);
		
		
		//Vec3 col = Vec3(
		//	-pos[0] * Vec3(m_view[0][0], m_view[0][1], m_view[0][2])
		//	-pos[1] * Vec3(m_view[1][0], m_view[1][1], m_view[1][2])
		//	-pos[2] * Vec3(m_view[2][0], m_view[2][1], m_view[2][2])
		//);
		
		glm::row(m_view, 3, Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		//viewInv -> view
		
		Mat3 R = m_view;
		//R = glm::transpose(R);
		
		m_view[3] = Vec4(Vec3(m_viewInv[3]) * -R, 1.0f);
		

		//m_view = glm::inverse(m_viewInv);

		m_viewProj = m_proj * m_view;
		m_viewProjInv = m_viewInv * m_projInv;
	}
}