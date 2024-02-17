#include "pch.h"
#include "LitShadingModelOpenGL.hpp"
#include "../Texture/TextureOpenGL.hpp"

namespace RedLightbulb
{
	LitShadingModelOpenGL::LitShadingModelOpenGL()
		: m_shader("Lit")
	{
	}
	void LitShadingModelOpenGL::create()
	{
		if (m_isInitialized)
		{
			// ???
		}

		m_shader.create("Shaders/Lit/LitVS.glsl", "Shaders/Lit/LitFS.glsl");
		m_materialUBO.create();

		m_isInitialized = true;
	}
	void LitShadingModelOpenGL::destroy()
	{
		if (m_isInitialized)
		{
			m_isInitialized = false;
		}
	}
	void LitShadingModelOpenGL::render(const Camera& camera)
	{
		LitShadingModel::render(camera);

		m_shader.bind();

		for (auto& mesh : m_meshes)
		{
			VAO* vao {};
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

				const MaterialLit* material = perMaterial.material.get();
				auto* baseColorTexture = sCast(TextureOpenGL*, material->baseColorTexture.get());
				auto* normalTexture = sCast(TextureOpenGL*, material->normalTexture.get());
				auto* ARMTexture = sCast(TextureOpenGL*, material->ARMTexture.get());


				MaterialUniform uniform;
				
				uniform.baseColor = material->baseColor;
				if (baseColorTexture)
				{
					uniform.usesBaseColorTexture = true;
					baseColorTexture->setToSlot(0, m_shader, "baseColorTexture");
				}

				if (normalTexture != nullptr)
				{
					uniform.usesNormalTexture = true;
					normalTexture->setToSlot(1, m_shader, "normalTexture");
				}

				uniform.roughness = material->roughness;
				uniform.usesRoughnessTexture = material->usesRoughnessTexture;

				uniform.metallic = material->metallic;
				uniform.usesMetallicTexture = material->usesMetallicTexture;

				if (ARMTexture != nullptr)
				{
					ARMTexture->setToSlot(2, m_shader, "armTexture");
				}

				m_materialUBO.bind();
				m_materialUBO.bufferData(&uniform, sizeof(uniform));
				m_materialUBO.setToSlot(3);

				for (const auto& instance : perMaterial.instances)
				{
					if (vao->withIndices())
					{
						glDrawElements(GL_TRIANGLES, subMesh->getIndicesCount(), GL_UNSIGNED_INT, (void*)(subMesh->getFirstIndexIndex() * sizeof(unsigned int)));
					}
					else
					{
						glDrawArrays(GL_TRIANGLES, subMesh->getFirstVertexIndex(), subMesh->getVerticesCount());
					}
				}
			}
		}
	}
	void LitShadingModelOpenGL::createBuffer(PerMesh& perMesh)
	{
		const auto& vertices = perMesh.mesh->getVertices();
		const auto& indices = perMesh.mesh->getIndices();

		std::pair<PerMesh, VAO> meshBuffer;

		m_buffers.emplace_back();
		m_buffers.back().first = &perMesh;

		auto& buffer = m_buffers.back().second;
		buffer.create();
		buffer.createP3TX2NM3TG3BT3IndexedBuffer(vertices, indices);
	}
}