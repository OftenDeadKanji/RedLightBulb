#ifndef __MESH_MANAGER__
#define __MESH_MANAGER__
#include <string>
#include <unordered_map>
#include <memory>
#include "../../Render/General/Mesh/Mesh.h"
#include "Utilities/Utilities.hpp"

struct aiScene;
struct aiNode;
struct aiMesh;

namespace RedLightbulb
{
	class MeshManager
	{
	public:
		static MeshManager& createInstance();
		static MeshManager& getInstance();
		static MeshManager* getInstancePtr();
		static void destroy();

		// If meshName argument is empty, mesh name is the same as pathToFile argument.
		sPtr<Mesh> loadMesh(const std::string& pathToFile, const std::string& meshName);
		sPtr<Mesh> getMesh(const std::string& meshName);

		bool processScene(const aiScene* scene, sPtr<Mesh> outMesh);
		bool processNode(const aiScene* scene, const aiNode* node, sPtr<Mesh> outMesh);

	private:
		bool importMaterial(const aiScene* scene, const aiMesh* mesh, sPtr<Mesh> outMesh, SubMesh& outSubMesh);

		static std::unique_ptr<MeshManager> s_instance;

		std::unordered_map<std::string, sPtr<Mesh>> m_meshes;
	};
}

#endif