#ifndef __MESH_HPP__
#define __MESH_HPP__
#include <vector>
#include "../Vertex/Vertex.hpp"
#include "SubMesh.hpp"
namespace RedLightbulb
{
	class MeshManager;

	class Mesh
	{
		friend MeshManager;
	public:
		const std::vector<Vertex>& getVertices() const;
		const std::vector<unsigned int>& getIndices() const;
		const std::vector<SubMesh>& getSubMeshes() const;
	private:
		std::string m_name;
		
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;

		std::vector<SubMesh> m_subMeshes;
	};
}

#endif