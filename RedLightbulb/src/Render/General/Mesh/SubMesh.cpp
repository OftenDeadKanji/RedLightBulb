#include "pch.h"
#include "SubMesh.hpp"

namespace RedLightbulb
{
    unsigned int SubMesh::getFirstVertexIndex() const
    {
        return m_firstVertexIndex;
    }

    unsigned int SubMesh::getVerticesCount() const
    {
        return m_verticesCount;
    }
    unsigned int SubMesh::getFirstIndexIndex() const
    {
        return m_firstIndexIndex;
    }
    unsigned int SubMesh::getIndicesCount() const
    {
        return m_indicesCount;
    }
    std::shared_ptr<Material> SubMesh::getMaterial() const
    {
        return m_parent->getMaterials()[m_materialIndex];
    }
    unsigned int SubMesh::getMaterialIndex() const
    {
        return m_materialIndex;
    }
}