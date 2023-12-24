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
		
		unsigned int vertexSize = sizeof(Vec3f);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vbo.bufferData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			m_vbo.bufferSubData(sCast(const void*, &vertex.position.x()), vertexSize, i * vertexSize);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);
	}
	void VAO::createP3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;

		bind();

		m_vbo.create();
		m_vbo.bind();

		unsigned int vertexSize = sizeof(Vec3f);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vbo.bufferData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			m_vbo.bufferSubData(sCast(const void*, &vertex.position.x()), vertexSize, i * vertexSize);
		}

		m_ebo.create();
		m_ebo.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_ebo.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);
	}
	bool VAO::withIndices() const
	{
		return m_withIndices;
	}
}