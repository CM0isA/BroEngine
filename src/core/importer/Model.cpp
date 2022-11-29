#include "Model.h"
#include "../graphics/buffres/VAO.h"
#define ASSIMP_LOAD_FLAGS (aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_JoinIdenticalVertices)


namespace broEngine {
	namespace importer {
		Model::Model(std::string filename, std::string path)
		{
			std::string filePath;
			if (path == "")
			{
				filePath = "src\\models\\" + filename;
			}
			else filePath = path + filename;
			scene = importer.ReadFile(filePath.c_str(), ASSIMP_LOAD_FLAGS);

			if (!scene)
			{
				std::cout << importer.GetErrorString();
			}
		}

		void Model::InitModel()
		{
			InitFromScene(scene);
		}

		void Model::RenderModel()
		{
			for (unsigned int i = 0; i < meshEntries.size(); i++)
			{
				Mesh mesh = meshEntries[i];
				mesh.RenderMesh();
			}
		}

		bool Model::InitFromScene(const aiScene* scene)
		{
			//number of meshes in an object
			meshEntries.resize(scene->mNumMeshes);
			meshTextures.resize(scene->mNumMaterials);

			unsigned int nrVertices = 0;
			unsigned int nrIndices = 0;

			CountVerticesAndIndices(scene, nrIndices, nrVertices);

			ReserveSpace(nrVertices, nrIndices);

			InitAllMeshes(scene);

			PopulateBuffers();

			return glGetError();
		}

		/// <summary>
		/// Send the data to the buffers
		/// </summary>
		void Model::PopulateBuffers()
		{
			for (unsigned int i = 0; i < meshEntries.size(); i++)
			{
				UploadData(model_vertex,model_indices);
			}
		}

		/// <summary>
		/// Initialize all meshes in the scene
		/// </summary>
		/// <param name="scene"></param>
		void Model::InitAllMeshes(const aiScene* scene)
		{
			for (unsigned int i = 0; i < meshEntries.size(); i++)
			{
				const aiMesh* aiMesh = scene->mMeshes[i];
				InitMesh(aiMesh);
				meshEntries[i].m_indices = model_indices;
				meshEntries[i].m_vertices = model_vertex;

			}
		}

		/// <summary>
		/// Reserve space for vertices and indices
		/// </summary>
		/// <param name="nrVertices"></param>
		/// <param name="nrIndices"></param>
		void Model::ReserveSpace(unsigned int nrVertices, unsigned int nrIndices)
		{
			model_vertex.reserve(nrVertices);
			model_indices.reserve(nrIndices);
		}

		/// <summary>
		/// Count the number of vertices and indices in a model
		/// </summary>
		/// <param name="scene"></param>
		/// <param name="nrIndices"></param>
		/// <param name="nrVertices"></param>
		void Model::CountVerticesAndIndices(const aiScene* scene, unsigned int& nrIndices, unsigned int& nrVertices)
		{
			for (unsigned int i = 0; i < scene->mNumMeshes; i++)
			{
				meshEntries[i].materialIndex = scene->mMeshes[i]->mMaterialIndex;
				meshEntries[i].m_numIndices = scene->mMeshes[i]->mNumFaces * 3;
				meshEntries[i].baseVertex = nrVertices;
				meshEntries[i].baseIndex = nrIndices;

				nrVertices += scene->mMeshes[i]->mNumVertices;
				nrIndices += meshEntries[i].m_numIndices;
			}
		}

		/// <summary>
		/// Initialize individual mesh
		/// </summary>
		/// <param name="paiMesh"></param>
		void Model::InitMesh(const aiMesh* paiMesh)
		{
			const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);
			const aiColor4D White4D(1.0f, 1.0f, 1.0f, 1.0f);

			for (unsigned i = 0; i < paiMesh->mNumVertices; i++)
			{
				const aiVector3D& pPos = paiMesh->mVertices[i];
				const aiVector3D& pNormal = paiMesh->mNormals[i];
				const aiVector3D& pTextureCoord = paiMesh->HasTextureCoords(0) ? paiMesh->mTextureCoords[0][i] : Zero3D;
				const aiColor4D& pColors = paiMesh->HasVertexColors(0) ? paiMesh->mColors[0][i] : White4D;

				struct Vertex vert = {
					glm::vec3(pPos.x, pPos.y, pPos.z),
					glm::vec3(pNormal.x, pNormal.y, pNormal.z),
					glm::vec2(pTextureCoord.x, pTextureCoord.y),
					glm::vec4(pColors.r, pColors.g, pColors.b, pColors.a)
				};
				model_vertex.push_back(vert);
			}

			for (unsigned int i = 0; i < paiMesh->mNumFaces; i++) {
				const aiFace& Face = paiMesh->mFaces[i];
				assert(Face.mNumIndices == 3);
				model_indices.push_back(Face.mIndices[0]);
				model_indices.push_back(Face.mIndices[1]);
				model_indices.push_back(Face.mIndices[2]);
			}
		}

		/// <summary>
		/// Creates VBO buffers for positions, normals, texture coordinates and indices then binds everything in a VAO buffer
		/// </summary>
		/// <param name="positions"></param>
		/// <param name="normals"></param>
		/// <param name="texCoords"></param>
		/// <param name="indices"></param>
		void Model::UploadData(std::vector<Vertex>& vertex, const std::vector<GLuint>& indices)
		{
			VBO vbo_vertex(vertex);
			EBO ebo_indices(indices);
			vao.Bind();

			vao.LinkVBO(vbo_vertex, 0, 3, GL_FLOAT, sizeof(Vertex), 0); //positions
			vao.LinkVBO(vbo_vertex, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)sizeof(glm::vec3)); //normals
			vao.LinkVBO(vbo_vertex, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(2 * sizeof(glm::vec3))); //texCoordinates
			vao.LinkVBO(vbo_vertex, 3, 4, GL_FLOAT, sizeof(Vertex), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2))); //colors

			vao.Unbind();
		}
	}
}