#include "pch.h"
#include "Mesh.h"

namespace RedLightbulb
{
    const std::vector<Vertex>& Mesh::getVertices() const
    {
        return m_vertices;
    }

    const std::vector<unsigned int>& Mesh::getIndices() const
    {
        return m_indices;
    }

    const std::vector<SubMesh>& Mesh::getSubMeshes() const
    {
        return m_subMeshes;
    }
}