#include "Mesh.h"


namespace broEngine {
	namespace importer {
		Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices)
		{
			m_vertices = vertices;
			m_indices = indices;
		}

		/// <summary>
		/// Upload vertices and indices for created onject
		/// </summary>
		/// <param name="vertices"></param>
		/// <param name="indices"></param>
		void Mesh::UploadData()
		{
			VBO vbo(m_vertices);
			EBO ebo(m_indices);

			meshVao.Bind();
			meshVao.LinkVBO(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
			meshVao.LinkVBO(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(sizeof(glm::vec3)));
			meshVao.LinkVBO(vbo, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(sizeof(glm::vec3) * 2));

			meshVao.Unbind();
		}

		void Mesh::RenderMesh()
		{
			meshVao.Bind();
			glDrawElements(GL_TRIANGLES, static_cast<int>(m_indices.size()), GL_UNSIGNED_INT, 0);
			meshVao.Unbind();
		}



	}
}