#include "Mesh.h"


namespace broEngine {
	namespace importer {
		Mesh::Mesh()
		{
			m_localPosition = glm::vec3(0, 0, 0);
			baseIndex = 0;
			baseVertex = 0;
			m_numIndices = 0;
			m_numVertices = 0;

		}
		Mesh::Mesh(std::vector<float> vertices, std::vector<GLuint> indices)
		{
			m_vertices = vertices;
			m_indices = indices;
		}

		void Mesh::LoadMesh()
		{
			//InitFromScene(scene);
		}

		void Mesh::RenderMesh()
		{
			vao.Bind();
			glDrawElements(GL_TRIANGLES, (GLuint)m_indices.size(), GL_UNSIGNED_INT, (void*)0);
			vao.Unbind();
		}

		void Mesh::Clear()
		{


		}

		void Mesh::InitMesh(const aiMesh* paiMesh)
		{
			const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

			for (unsigned i = 0; i < paiMesh->mNumVertices; i++)
			{
				const aiVector3D* pPos = &(paiMesh->mVertices[i]);
				const aiVector3D* pNormal = &(paiMesh->mNormals[i]);
				const aiVector3D* pTextureCoord = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTextureCoords[0][i]) : &Zero3D;

				positions.push_back(glm::vec3(pPos->x, pPos->y, pPos->z));
				normals.push_back(glm::vec3(pNormal->x, pNormal->y, pNormal->z));
				texCoords.push_back(glm::vec3(pTextureCoord->x, pTextureCoord->y, pTextureCoord->z));
			}

			for (unsigned int i = 0; i < paiMesh->mNumFaces; i++) {
				const aiFace& Face = paiMesh->mFaces[i];
				m_indices.push_back(Face.mIndices[0]);
				m_indices.push_back(Face.mIndices[1]);
				m_indices.push_back(Face.mIndices[2]);
				if (Face.mNumIndices == 4)
					m_indices.push_back(Face.mIndices[3]);
			}
		}

		/// <summary>
		/// Upload data for an imported object
		/// </summary>
		/// <param name="positions"></param>
		/// <param name="normals"></param>
		/// <param name="texCoords"></param>
		void Mesh::UploadData(const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& texCoords)
		{
			VBO vbo_positions;
			glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * positions.size(), &positions[0], GL_STATIC_DRAW);
			vbo_positions.Unbind();

			VBO vbo_normals;
			glBufferData(GL_ARRAY_BUFFER, sizeof(normals[0]) * normals.size(), &normals[0], GL_STATIC_DRAW);
			vbo_normals.Unbind();

			VBO vbo_texCoords;
			glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
			vbo_texCoords.Unbind();

			VBO vbo_indices;
			glBufferData(GL_ARRAY_BUFFER, sizeof(m_indices[0]) * m_indices.size(), &m_indices[0], GL_STATIC_DRAW);
			vbo_indices.Unbind();

			vao.Bind();
			vao.LinkVBO(vbo_positions, 0, 3, GL_FLOAT, sizeof(positions[0]) * positions.size(), (void*)0);
			vao.LinkVBO(vbo_normals, 1, 3, GL_FLOAT, sizeof(normals[0]) * normals.size(), (void*)(3 * sizeof(float)));
			vao.LinkVBO(vbo_texCoords, 2, 3, GL_FLOAT, sizeof(texCoords[0]) * texCoords.size(), (void*)(6 * sizeof(float)));
			vao.LinkVBO(vbo_indices, 3, 2, GL_FLOAT, sizeof(m_indices[0]) * m_indices.size(), (void*)(9 * sizeof(float)));
			vao.Unbind();
		}

		/// <summary>
		/// Upload vertices and indices for created onject
		/// </summary>
		/// <param name="vertices"></param>
		/// <param name="indices"></param>
		void Mesh::UploadData(const std::vector<float>& vertices, const std::vector<float>& indices)
		{
			VBO vbo(m_vertices);
			EBO ebo(m_indices);

			vao.Bind();


			vao.Unbind();
		}

	}
}