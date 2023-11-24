#include "pch.h"
#include "Mesh.h"

namespace RedLightbulb
{
    unsigned int Mesh::SubMesh::getFirstVertexIndex() const
    {
        return firstVertexIndex;
    }
    unsigned int Mesh::SubMesh::getVerticesCount() const
    {
        return verticesCount;
    }

    const std::vector<Vertex>& Mesh::getVertices() const
    {
        return m_vertices;
    }

    const std::vector<unsigned int>& Mesh::getIndices() const
    {
        return m_indices;
    }

    const std::vector<Mesh::SubMesh>& Mesh::getSubMeshes() const
    {
        return m_subMeshes;
    }
}