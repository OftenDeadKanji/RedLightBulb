#ifndef __SUBMESH_HPP__
#define __SUBMESH_HPP__

namespace RedLightbulb
{
	class Mesh;
	class MeshManager;
	struct Material;

	class SubMesh
	{
		friend MeshManager;
	public:
		unsigned int getFirstVertexIndex() const;
		unsigned int getVerticesCount() const;

		unsigned int getFirstIndexIndex() const;
		unsigned int getIndicesCount() const;

		std::shared_ptr<Material> getMaterial() const;
		unsigned int getMaterialIndex() const;
	private:
		std::string m_name;

		Mesh* m_parent{};
		
		unsigned int m_firstVertexIndex;
		unsigned int m_verticesCount;

		unsigned int m_firstIndexIndex;
		unsigned int m_indicesCount;

		unsigned int m_materialIndex;
	};
}

#endif