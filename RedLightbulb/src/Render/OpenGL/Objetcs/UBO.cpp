#include "pch.h"
#include "UBO.hpp"

namespace RedLightbulb
{
	void UniformBufferObject::create()
	{
		glGenBuffers(1, &m_id);
		//m_index = glGetUniformBlockIndex(shaderProgram, name.c_str());
	}
	void UniformBufferObject::bind()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_id);
	}
	void UniformBufferObject::unbind()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	void UniformBufferObject::bufferData(const void* data, unsigned int size)
	{
		glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);
	}
	void UniformBufferObject::setToSlot(int slot)
	{
		glBindBufferBase(GL_UNIFORM_BUFFER, slot, m_id);
	}
}