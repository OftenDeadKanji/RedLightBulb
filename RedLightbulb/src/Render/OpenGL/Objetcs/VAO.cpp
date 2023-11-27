#include "pch.h"
#include "VAO.hpp"

namespace RedLightbulb
{
	VAO::~VAO()
	{
		destroy();
	}

	void VAO::create()
	{
		if (m_id != 0)
		{
			// ??
		}
		glCreateVertexArrays(1, &m_id);
	}
	void VAO::destroy()
	{
		if (m_id != 0)
		{
			glDeleteVertexArrays(1, &m_id);
		}
	}
	void VAO::bind()
	{
		glBindVertexArray(m_id);
	}
	void VAO::unbind()
	{
		glBindVertexArray(0);
	}
	void VAO::createP3Buffer(const std::vector<Vertex>& vertices)
	{
		m_vbo.create();

		bind();
		m_vbo.bind();
		
		unsigned int vertexSize = sizeof(Vec3);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vbo.bufferData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			m_vbo.bufferSubData(sCast(const void*, &vertex.position.x), vertexSize, i * vertexSize);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);
	}
}