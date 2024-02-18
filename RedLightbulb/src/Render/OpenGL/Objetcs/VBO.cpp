#include "pch.h"
#include "VBO.hpp"

namespace RedLightbulb
{
	VBO::~VBO()
	{
		destroy();
	}
	void VBO::create()
	{
		if (id != 0)
		{
			// ??
		}
		glGenBuffers(1, &id);
	}
	void VBO::destroy()
	{
		if (id != 0)
		{
			glDeleteBuffers(1, &id);
			id = 0;
		}
	}
	void VBO::bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}
	void VBO::unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VBO::bufferStaticData(const void* data, unsigned int size)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	void VBO::bufferDynamicData(const void* data, unsigned int size)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	void VBO::bufferSubData(const void* data, unsigned int size, unsigned int offset)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	}
}