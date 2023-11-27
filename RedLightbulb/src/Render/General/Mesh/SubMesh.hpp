#ifndef __SUBMESH_HPP__
#define __SUBMESH_HPP__
#include "../Material/MaterialPBR.hpp"

namespace RedLightbulb
{
	class Mesh;
	class MeshManager;

	class SubMesh
	{
		friend MeshManager;
	public:
		unsigned int getFirstVertexIndex() const;
		unsigned int getVerticesCount() const;
	private:
		std::string m_name;

		Mesh* parent;
		unsigned int firstVertexIndex;
		unsigned int verticesCount;

		std::shared_ptr<MaterialPBR> material;
	};
}

#endif