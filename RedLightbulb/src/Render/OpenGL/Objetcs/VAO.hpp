#ifndef __VAO_HPP__
#define __VAO_HPP__
#include "VBO.hpp"
#include "EBO.hpp"

namespace RedLightbulb
{
	struct Vertex;

	class VAO
	{
	public:
		~VAO();

		void create();
		void destroy();

		void bind();
		void unbind();

		// Position 3D
		void createP3Buffer(const std::vector<Vertex>& vertices);
		void createP3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

		// Position 3D
		// Texture Coordinate 2D
		void createP3TX2Buffer(const std::vector<Vertex>& vertices);
		void createP3TX2IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
		void createP3TX2IndexedInstancedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

		// Position 3D
		// Texture Coordinate 2D
		// Normal 3D
		// Tangent 3D
		// Bitangent 3D
		void createP3TX2NM3TG3BT3Buffer(const std::vector<Vertex>& vertices);
		void createP3TX2NM3TG3BT3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
		void createP3TX2NM3TG3BT3IndexedInstancedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

		void updateInstanceBuffer(const void* data, unsigned int size);
		void updateInstanceBuffer(const void* data, unsigned int size, unsigned int offset);

		bool withIndices() const;
		bool withIndicesAndInstances() const;
	private:
		GLuint m_id = 0;
		VBO m_vertices;
		VBO m_instances;
		EBO m_indices;

		bool m_withIndices = false;
		bool m_withInstances = false;
	};
}

#endif