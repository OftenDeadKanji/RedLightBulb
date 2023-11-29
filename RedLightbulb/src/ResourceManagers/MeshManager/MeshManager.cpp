#include "pch.h"
#include "MeshManager.hpp"
#include <iostream>
#include "../../Dependencies/assimp/Importer.hpp"
#include "../../Dependencies/assimp/scene.h"
#include "../../Dependencies/assimp/postprocess.h"

namespace RedLightbulb
{
	std::unique_ptr<MeshManager> MeshManager::s_instance = nullptr;

	MeshManager& MeshManager::createInstance()
	{
		s_instance = std::unique_ptr<MeshManager>(new MeshManager());

		return *s_instance;
	}
	MeshManager& MeshManager::getInstance()
	{
		return *s_instance;
	}
	void MeshManager::destroy()
	{
		s_instance.release();
	}

	bool MeshManager::load(const std::string& pathToFile, const std::string& meshName, Mesh& outMesh)
	{
		std::string name = meshName.empty() ? pathToFile : meshName;

		if (m_meshes.contains(name))
		{
			outMesh = m_meshes[name];
			// RED_TODO warning? 
			return false;
		}

		outMesh.m_name = name;

		Assimp::Importer importer;

		unsigned int postprocessFlags =
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_CalcTangentSpace |
			aiProcess_ImproveCacheLocality
			;

		const aiScene* scene = importer.ReadFile(pathToFile, postprocessFlags);
		if (!scene)
		{
			//RED_TODO error? warning?
			std::cout << "[ERROR] While loading " << name << " mesh: \"" << importer.GetErrorString() << "\"";
			return false;
		}

		processScene(scene, outMesh);

		m_meshes[name] = outMesh;
		return true;
	}
	bool MeshManager::processScene(const aiScene* scene, Mesh& outMesh)
	{
		std::cout << "Processing " << scene->mName.C_Str() << " scene.\n";

		processNode(scene, scene->mRootNode, outMesh);
		return false;
	}
	bool MeshManager::processNode(const aiScene* scene, const aiNode* node, Mesh& outMesh)
	{
		std::cout << "\tProcessing " << node->mName.C_Str() << " node.\n";
		//node
		for (int i = 0; i < node->mNumMeshes; i++)
		{
			int meshIndex = node->mMeshes[i];
			const aiMesh* mesh = scene->mMeshes[meshIndex];

			outMesh.m_subMeshes.emplace_back();
			auto& subMesh = outMesh.m_subMeshes.back();

			subMesh.m_name = mesh->mName.C_Str();
			subMesh.firstVertexIndex = outMesh.m_vertices.size();

			for (int i = 0; i < mesh->mNumVertices; i++)
			{
				Vertex vertex;
				vertex.position = { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z };
				vertex.color = mesh->HasVertexColors(0) ? Vec3(mesh->mColors[0][i].r, mesh->mColors[0][i].g, mesh->mColors[0][i].b) : Vec3(1.0f, 1.0f, 1.0f);
				vertex.texCoord = mesh->HasTextureCoords(0) ? Vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y) : Vec2(0.0f, 0.0f);
				vertex.normal = mesh->HasNormals() ? Vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z) : Vec3(0.0f, 0.0f, 1.0f);
				vertex.tangent = mesh->HasTangentsAndBitangents() ? Vec3(mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z) : Vec3(1.0f, 0.0f, 0.0f);
				vertex.bitangent = mesh->HasTangentsAndBitangents() ? Vec3(mesh->mBitangents[i] .x, mesh->mBitangents[i].y, mesh->mBitangents[i].z) : Vec3(0.0f, 1.0f, 0.0f);

				outMesh.m_vertices.push_back(vertex);
			}

			subMesh.verticesCount = outMesh.m_vertices.size();
			
			aiMaterial* subMeshMaterial = scene->mMaterials[mesh->mMaterialIndex];
			auto name = subMeshMaterial->GetName().C_Str();

			aiColor3D baseColor;
			auto ret = subMeshMaterial->Get(AI_MATKEY_COLOR_DIFFUSE, baseColor);

			float metallic;
			ret = subMeshMaterial->Get(AI_MATKEY_METALLIC_FACTOR, metallic);

			float roughness;
			ret = subMeshMaterial->Get(AI_MATKEY_ROUGHNESS_FACTOR, roughness);

			for (int i = 0; i < mesh->mNumFaces; i++)
			{
				const aiFace& face = mesh->mFaces[i];
				if (face.mNumIndices != 3)
				{
					std::cout << "Mesh " << mesh->mName.C_Str() << " contains face that is not triagle!\n";
				}

				outMesh.m_indices.push_back(face.mIndices[0]);
				outMesh.m_indices.push_back(face.mIndices[1]);
				outMesh.m_indices.push_back(face.mIndices[2]);
			}
		}

		//children
		for (int i = 0; i < node->mNumChildren; i++)
		{
			processNode(scene, node->mChildren[i], outMesh);
		}
		return false;
	}
}