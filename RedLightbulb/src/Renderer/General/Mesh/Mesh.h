#ifndef __MESH_HPP__
#define __MESH_HPP__
#include <vector>
#include "../Vertex/Vertex.hpp"

namespace RedLightbulb
{
	class MeshManager;
	class MeshObjLoader;

	class Mesh
	{
		friend MeshManager;
		friend MeshObjLoader;
	public:
		class SubMesh
		{
		public:
			unsigned int getFirstVertexIndex() const;
			unsigned int getVerticesCount() const;
		private:
			std::vector<Vertex>::const_iterator m_vertexIterStart, m_vertexIterEnd;
			std::vector<unsigned int>::const_iterator m_indexIterStart, m_indexIterEnd;

			unsigned int firstVertexIndex;
			unsigned int verticesCount;
		};
	public:
		const std::vector<Vertex>& getVertices() const;
		const std::vector<unsigned int>& getIndices() const;
		const std::vector<SubMesh>& getSubMeshes() const;
	private:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;

		std::vector<SubMesh> m_subMeshes;
	};
}

#endif