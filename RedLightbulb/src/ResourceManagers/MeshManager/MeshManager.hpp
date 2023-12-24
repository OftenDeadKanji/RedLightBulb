#ifndef __MESH_MANAGER__
#define __MESH_MANAGER__
#include <string>
#include <unordered_map>
#include <memory>
#include "../../Render/General/Mesh/Mesh.h"

struct aiScene;
struct aiNode;

namespace RedLightbulb
{
	class MeshManager
	{
	public:
		static MeshManager& createInstance();
		static MeshManager& getInstance();
		static void destroy();

		// If meshName argument is empty, mesh name is the same as pathToFile argument.
		bool load(const std::string& pathToFile, const std::string& meshName, Mesh& outMesh);
		bool processScene(const aiScene* scene, Mesh& outMesh);
		bool processNode(const aiScene* scene, const aiNode* node, Mesh& outMesh);

	private:
		static std::unique_ptr<MeshManager> s_instance;

		std::unordered_map<std::string, Mesh> m_meshes;
	};
}

#endif