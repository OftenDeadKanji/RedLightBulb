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

		// Position 3D
		// Texture Coordinate 2D
		// Normal 3D
		// Tangent 3D
		// Bitangent 3D
		void createP3TX2NM3TG3BT3Buffer(const std::vector<Vertex>& vertices);
		void createP3TX2NM3TG3BT3IndexedBuffer(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

		bool withIndices() const;
	private:
		GLuint m_id = 0;
		VBO m_vbo;
		EBO m_ebo;

		bool m_withIndices = false;
	};
}

#endif