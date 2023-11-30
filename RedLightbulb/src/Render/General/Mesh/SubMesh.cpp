#include "pch.h"
#include "SubMesh.hpp"

namespace RedLightbulb
{
    unsigned int SubMesh::getFirstVertexIndex() const
    {
        return firstVertexIndex;
    }

    unsigned int SubMesh::getVerticesCount() const
    {
        return verticesCount;
    }
    unsigned int SubMesh::getFirstIndexIndex() const
    {
        return firstIndexIndex;
    }
    unsigned int SubMesh::getIndicesCount() const
    {
        return indicesCount;
    }
}