#include "pch.h"
#include "UnlitShadingModelOpenGL.hpp"

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

		m_shader.setMat4Uniform()

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

				const Material* material = perMaterial.material;

				// for instances

				glDrawArrays(GL_TRIANGLES, subMesh->getFirstVertexIndex(), subMesh->getVerticesCount());
			}
		}
	}

	void UnlitShadingModelOpenGL::createBuffer(PerMesh& perMesh)
	{
		const auto& vertices = perMesh.mesh->getVertices();
		
		std::pair<PerMesh, VAO> meshBuffer;

		m_buffers.emplace_back();
		m_buffers.back().first = &perMesh;

		auto& buffer = m_buffers.back().second;
		buffer.create();
		buffer.createP3Buffer(vertices);
	}
}