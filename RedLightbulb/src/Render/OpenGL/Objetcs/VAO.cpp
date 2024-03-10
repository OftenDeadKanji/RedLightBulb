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
		m_vertices.create();

		bind();
		m_vertices.bind();
		
		unsigned int vertexSize = sizeof(Math::Vec3f);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			m_vertices.bufferSubData(sCast(const void*, &vertex.position.x()), vertexSize, i * vertexSize);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);
	}
	void VAO::createP3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;

		bind();

		m_vertices.create();
		m_vertices.bind();

		unsigned int vertexSize = sizeof(Math::Vec3f);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			m_vertices.bufferSubData(sCast(const void*, &vertex.position.x()), vertexSize, i * vertexSize);
		}

		m_indices.create();
		m_indices.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_indices.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);
	}
	
	void VAO::createP3TX2Buffer(const std::vector<Vertex>& vertices)
	{
		m_vertices.create();

		bind();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord };

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);
	}
	void VAO::createP3TX2IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;

		bind();

		m_vertices.create();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord };

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		m_indices.create();
		m_indices.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_indices.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);
	}
	void VAO::createP3TX2IndexedInstancedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;
		m_withInstances = true;

		bind();

		m_vertices.create();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord };

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		m_indices.create();
		m_indices.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_indices.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, sCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);

		m_instances.create();
		m_instances.bind();

		glVertexAttribPointer(2, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 0));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(3, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 1 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(4, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 2 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(5, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 3 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(5);

		glVertexAttribDivisor(2, 1);
		glVertexAttribDivisor(3, 1);
		glVertexAttribDivisor(4, 1);
		glVertexAttribDivisor(5, 1);
	}

	void VAO::createP3TX2NM3TG3BT3Buffer(const std::vector<Vertex>& vertices)
	{
		m_vertices.create();

		bind();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
			Math::Vec3f normal;
			Math::Vec3f tangent;
			Math::Vec3f bitangent;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord, vertex.normal, vertex.tangent, vertex.bitangent};

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);
		
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 2 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(3);

		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 3 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(4);
	}
	void VAO::createP3TX2NM3TG3BT3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;

		bind();

		m_vertices.create();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
			Math::Vec3f normal;
			Math::Vec3f tangent;
			Math::Vec3f bitangent;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord, vertex.normal, vertex.tangent, vertex.bitangent };

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		m_indices.create();
		m_indices.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_indices.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 2 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(3);

		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 3 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(4);
	}
	void VAO::createP3TX2NM3TG3BT3IndexedInstancedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
	{
		m_withIndices = true;
		m_withInstances = true;

		bind();

		m_vertices.create();
		m_vertices.bind();

		struct SubVertex
		{
			Math::Vec3f position;
			Math::Vec2f uv;
			Math::Vec3f normal;
			Math::Vec3f tangent;
			Math::Vec3f bitangent;
		};

		unsigned int vertexSize = sizeof(SubVertex);
		unsigned int verticesCount = vertices.size();
		unsigned int dataSize = verticesCount * vertexSize;

		m_vertices.bufferStaticData(nullptr, dataSize);

		for (int i = 0; i < verticesCount; i++)
		{
			const auto& vertex = vertices[i];
			SubVertex subVertex = { vertex.position, vertex.texCoord, vertex.normal, vertex.tangent, vertex.bitangent };

			m_vertices.bufferSubData(sCast(const void*, &subVertex), vertexSize, i * vertexSize);
		}

		m_indices.create();
		m_indices.bind();

		unsigned int indexSize = sizeof(unsigned int);
		unsigned int indicesCount = indices.size();
		unsigned int indicesDataSize = indexSize * indicesCount;

		m_indices.bufferData(indices.data(), indicesDataSize);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(2);

		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 2 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(3);

		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, vertexSize, rCast(void*, 3 * sizeof(Math::Vec3f) + sizeof(Math::Vec2f)));
		glEnableVertexAttribArray(4);

		m_instances.create();
		m_instances.bind();

		glVertexAttribPointer(5, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 0));
		glEnableVertexAttribArray(5);
		glVertexAttribPointer(6, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 1 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(7, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 2 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(7);
		glVertexAttribPointer(8, 4, GL_FLOAT, false, sizeof(Math::Mat4f), rCast(void*, 3 * sizeof(Math::Vec4f)));
		glEnableVertexAttribArray(8);

		glVertexAttribDivisor(5, 1);
		glVertexAttribDivisor(6, 1);
		glVertexAttribDivisor(7, 1);
		glVertexAttribDivisor(8, 1);
	}

	void VAO::updateInstanceBuffer(const void* data, unsigned int size)
	{
		m_instances.bind();
		m_instances.bufferDynamicData(data, size);
	}

	void VAO::updateInstanceBuffer(const void* data, unsigned int size, unsigned int offset)
	{
		m_instances.bind();
		m_instances.bufferSubData(data, size, offset);
	}

	bool VAO::withIndices() const
	{
		return m_withIndices;
	}
	bool VAO::withIndicesAndInstances() const
	{
		return m_withIndices && m_withInstances;
	}
}