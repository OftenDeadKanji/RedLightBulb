#ifndef __MESH_HPP__
#define __MESH_HPP__
#include <vector>
#include "../Vertex/Vertex.hpp"
#include "SubMesh.h"

namespace RedLightbulb
{
	class MeshManager;
	class MeshObjLoader;

	class Mesh
	{
		friend MeshManager;
		friend MeshObjLoader;
	public:

	private:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;

		std::vector<SubMesh> m_subMeshes;
	};
}

#endif