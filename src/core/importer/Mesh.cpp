#include "Mesh.h"


namespace broEngine {
	namespace importer {
		Mesh::Mesh(std::string filename, std::string path)
		{
			std::string filePath;
			if (path == "")
			{
				filePath = "src\\models\\" + filename;
			}
			else filePath = path + filename;

			Assimp::Importer importer;
			unsigned int flags = aiProcess_GenSmoothNormals | aiProcess_FlipUVs;
			scene = importer.ReadFile(filePath, flags);

			for (int i = 0; i < scene->mNumMeshes; i++)
			{
				aiMesh* currentMesh = scene->mMeshes[i];

				for (int j = 0; j < currentMesh->mNumVertices; j++)
				{
					m_vertices.push_back(currentMesh->mVertices[j].x);
					m_vertices.push_back(currentMesh->mVertices[j].y);
					m_vertices.push_back(currentMesh->mVertices[j].z);
				}
			}

			for (int i = 0; i < scene->mNumMeshes; i++)
			{
				aiMesh* currentMesh = scene->mMeshes[i];

				for (int j = 0; j < currentMesh->mNumFaces * 3; j++)
				{
					m_indices.push_back(currentMesh->mTangents[j].x);
					m_indices.push_back(currentMesh->mTangents[j].y);
					m_indices.push_back(currentMesh->mTangents[j].z);
				}
			}


		}

		Mesh::Mesh(std::vector<float> vertices, std::vector<GLuint> indices)
		{
			m_vertices = vertices;
			m_indices = indices;
		}

		void Mesh::LoadMesh()
		{
			vao.Bind();
			VBO vbo(m_vertices);
			EBO ebo(m_indices);

			vao.LinkVBO(vbo, 0);
			vao.Unbind();
			ebo.Unbind();
		}

		void Mesh::RenderMesh()
		{
			vao.Bind();
			glDrawElements(GL_TRIANGLES, (GLuint)m_indices.size(), GL_UNSIGNED_INT, (void*)0);
			vao.Unbind();
		}
	}
}