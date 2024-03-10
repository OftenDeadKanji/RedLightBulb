#include "pch.h"
#include "UnlitShadingModelOpenGL.hpp"
#include "../Texture/TextureOpenGL.hpp"

namespace RedLightbulb
{
	UnlitShadingModelOpenGL::UnlitShadingModelOpenGL()
		: m_shader("Unlit")
	{}

	void UnlitShadingModelOpenGL::create()
	{
		if (m_isInitialized)
		{
			// ???
		}

		m_shader.create("Shaders/Unlit/UnlitVS.glsl", "Shaders/Unlit/UnlitFS.glsl");
		m_materialUBO.create();
	}

	void UnlitShadingModelOpenGL::destroy()
	{
		if (m_isInitialized)
		{
			m_isInitialized = false;
		}
	}

	void UnlitShadingModelOpenGL::render(const Camera& camera)
	{
		UnlitShadingModel::render(camera);

		m_shader.bind();

		for (auto& perMesh : m_meshes)
		{
			VAO* vao{};
			for (auto& buffer : m_buffers)
			{
				if (buffer.first == &perMesh)
				{
					vao = &buffer.second;
					break;
				}
			}

			vao->bind();

			auto& subMeshes = perMesh.mesh->getSubMeshes();
			int subMeshesCount = subMeshes.size();
			for (int subMeshIndex = 0; subMeshIndex < subMeshesCount; subMeshIndex++)
			{
				const SubMesh& subMesh = subMeshes[subMeshIndex];
				for (int perMaterialsSetIndex = 0; perMaterialsSetIndex < perMesh.perMaterialsSet.size(); perMaterialsSetIndex++)
				{
					const auto& perMaterialSet = perMesh.perMaterialsSet[perMaterialsSetIndex];
					const auto& material = perMaterialSet.materials[subMeshIndex];

					if (material == nullptr)
					{
						continue;
					}

					auto* texture = sCast(TextureOpenGL*, material->baseColorTexture.get());
					texture->setToSlot(0, m_shader, "baseColorTexture");

					MaterialUniform uniform;
					uniform.baseColor = material->baseColor;
					uniform.usesBaseColorTexture = material->baseColorTexture != nullptr;

					m_materialUBO.bind();
					m_materialUBO.bufferData(&uniform, sizeof(uniform));
					m_materialUBO.setToSlot(3);

					vao->updateInstanceBuffer(perMaterialSet.instances.data(), sizeof(InstanceT) * perMaterialSet.instances.size());

					if (vao->withIndicesAndInstances())
					{
						glDrawElementsInstanced(GL_TRIANGLES, subMesh.getIndicesCount(), GL_UNSIGNED_INT, (void*)(subMesh.getFirstIndexIndex() * sizeof(unsigned int)), perMaterialSet.instances.size());
					}
					else if (vao->withIndices())
					{
						glDrawElements(GL_TRIANGLES, subMesh.getIndicesCount(), GL_UNSIGNED_INT, (void*)(subMesh.getFirstIndexIndex() * sizeof(unsigned int)));
					}
				}
			}
		}
	}

	void UnlitShadingModelOpenGL::createBuffer(PerMesh& perMesh)
	{
		const auto& vertices = perMesh.mesh->getVertices();
		const auto& indices = perMesh.mesh->getIndices();

		std::pair<PerMesh, VAO> meshBuffer;

		m_buffers.emplace_back();
		m_buffers.back().first = &perMesh;

		auto& buffer = m_buffers.back().second;
		buffer.create();
		buffer.createP3TX2IndexedInstancedBuffer(vertices, indices);
	}
}