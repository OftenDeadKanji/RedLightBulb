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
}