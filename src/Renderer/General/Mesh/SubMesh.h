#ifndef __SUBMESH_HPP__
#define __SUBMESH_HPP__
#include "../Vertex/Vertex.hpp"
#include <vector>

namespace RedLightbulb
{
	class Mesh;

	class SubMesh
	{
	public:

	private:
		std::vector<Vertex>::const_iterator m_vertexIterStart, m_vertexIterEnd;
		std::vector<unsigned int>::const_iterator m_indexIterStart, m_indexIterEnd;
	};
}

#endif