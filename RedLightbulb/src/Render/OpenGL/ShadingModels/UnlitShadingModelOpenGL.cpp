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

		//m_shader.setMat4Uniform();

		for (auto& mesh : m_meshes)
		{
			VAO* vao{};
			for (auto& buffer : m_buffers)
			{
				if (buffer.first == &mesh)
				{
					vao = &buffer.second;
					break;
				}
			}

			vao->bind();
			for (const auto& perSubmesh : mesh.submeshes)
			{
				const SubMesh* subMesh = perSubmesh.first;
				const PerMaterial& perMaterial = perSubmesh.second;

				const MaterialUnlit* material = perMaterial.material.get();
				auto* texture = sCast(TextureOpenGL*, material->baseColorTexture.get());
				
				texture->setToSlot(0, m_shader, "baseColorTexture");
				
				MaterialUniform uniform;
				uniform.baseColor = material->baseColor;
				uniform.usesBaseColorTexture = material->baseColorTexture != nullptr;
				
				m_materialUBO.bind();
				m_materialUBO.bufferData(&uniform, sizeof(uniform));
				m_materialUBO.setToSlot(3);

				//for (const auto& instance : perMaterial.instances)
				//{
				//
				//}

				vao->updateInstanceBuffer(perMaterial.instances.data(), sizeof(InstanceT) * perMaterial.instances.size());

				if (vao->withIndices())
				{
					glDrawElements(GL_TRIANGLES, subMesh->getIndicesCount(), GL_UNSIGNED_INT, (void*)(subMesh->getFirstIndexIndex() * sizeof(unsigned int)));
				}
				else if(vao->withIndicesAndInstances())
				{
					glDrawElementsInstanced(GL_TRIANGLES, subMesh->getIndicesCount(), GL_UNSIGNED_INT, (void*)(subMesh->getFirstIndexIndex() * sizeof(unsigned int)), perMaterial.instances.size());
				}
				//glDrawArrays(GL_TRIANGLES, subMesh->getFirstVertexIndex(), subMesh->getVerticesCount());
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