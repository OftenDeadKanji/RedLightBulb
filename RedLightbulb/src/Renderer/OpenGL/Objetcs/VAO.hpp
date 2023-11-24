#ifndef __VAO_HPP__
#define __VAO_HPP__
#include "VBO.hpp"

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

		void createP3Buffer(const std::vector<Vertex>& vertices);
	private:
		GLuint m_id = 0;
		VBO m_vbo;
	};
}

#endif