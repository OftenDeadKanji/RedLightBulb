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
		m_viewInv[3] = Vec4(position, 0.0f);
		m_updateMatrices = true;
	}
	void Camera::addLocalRotation(const Quat& rotation)
	{
		Vec3 rotationEuler = glm::eulerAngles(rotation);
		if (m_isRollEnabled)
		{
			rotationEuler.z = 0.0f;
		}
	
		m_rotation = glm::rotate(m_rotation, rotationEuler.z, getForward());
		m_rotation = glm::rotate(m_rotation, rotationEuler.x, getRight());
		m_rotation = glm::rotate(m_rotation, rotationEuler.y, getUp());
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
	void Camera::setWorldRotation(const Quat& rotation)
	{
		m_rotation = rotation;
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
	void Camera::setIsRollEnabled(bool enabled)
	{
		m_isRollEnabled = enabled;
	}
	void Camera::update()
	{
		glm::normalize(m_rotation);
	
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
		if (m_updateMatrices)
		{
			m_updateMatrices = false;
			updateBasis();
		}

		//viewInv -> view
		m_view[0][0] = m_viewInv[0][0];  m_view[1][0] = m_viewInv[0][1];  m_view[2][0] = m_viewInv[0][2];
		m_view[0][1] = m_viewInv[1][0];  m_view[1][1] = m_viewInv[1][1];  m_view[2][1] = m_viewInv[1][2];
		m_view[0][2] = m_viewInv[2][0];  m_view[1][2] = m_viewInv[2][1];  m_view[2][2] = m_viewInv[2][2];
		
		glm::row(m_view, 3, Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		Mat3 R = m_view;
		
		m_view[3] = Vec4(Vec3(m_viewInv[3]) * -R, 1.0f);
		
		m_viewProj = m_proj * m_view;
		m_viewProjInv = m_viewInv * m_projInv;
	}
}