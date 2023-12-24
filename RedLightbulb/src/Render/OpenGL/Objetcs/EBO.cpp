#include "pch.h"
#include "EBO.hpp"

namespace RedLightbulb
{
	EBO::~EBO()
	{
		if (m_isInitialized)
		{
			destroy();
		}
	}
	void EBO::create()
	{
		glCreateBuffers(1, &m_id);
		m_isInitialized = true;
	}
	void EBO::destroy()
	{
		glDeleteBuffers(1, &m_id);
		m_isInitialized = false;
	}
	void EBO::bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}
	void EBO::unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void EBO::bufferData(const void* data, unsigned int size)
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}