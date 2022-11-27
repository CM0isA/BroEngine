#include "Model.h"

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
			unsigned int flags = aiProcess_GenSmoothNormals | aiProcess_FlipUVs;
			if (glDrawMode == GL_TRIANGLES) flags |= aiProcess_Triangulate;
			scene = importer.ReadFile(filePath.c_str(), flags);

			if (!scene)
			{
				std::cout << importer.GetErrorString();
			}
		}

		void Model::InitModel()
		{
			this->InitFromScene(this->scene);
		}


		bool Model::InitFromScene(const aiScene* scene)
		{
			//number of meshes in an object
			meshEntries.resize(scene->mNumMeshes);
			unsigned int nrVertices = 0;
			unsigned int nrIndices = 0;

			// Count the number of vertices and indices
			for (unsigned int i = 0; i < scene->mNumMeshes; i++)
			{
				meshEntries[i].materialIndex = scene->mMeshes[i]->mMaterialIndex;
				meshEntries[i].m_numIndices = scene->mMeshes[i]->mNumFaces * (glDrawMode == GL_TRIANGLES ? 3 : 4);
				meshEntries[i].m_numVertices = scene->mMeshes[i]->mNumVertices;
				meshEntries[i].baseIndex = nrIndices;
				meshEntries[i].baseVertex = nrVertices;

				nrVertices += scene->mMeshes[i]->mNumVertices;
				nrIndices += meshEntries[i].m_numIndices;
				aiVector3D* vertices = scene->mMeshes[i]->mVertices;
			}

			model_positions.reserve(nrVertices);
			model_normals.reserve(nrVertices);
			model_texCoords.reserve(nrVertices);
			model_indices.reserve(nrIndices);

			for (unsigned int i = 0; i < meshEntries.size(); i++)
			{
				const aiMesh* mesh = scene->mMeshes[i];
				meshEntries[i].InitMesh(mesh);
			}

			for (unsigned int i = 0; i < meshEntries.size(); i++)
			{
				meshEntries[i].UploadData(meshEntries[i].positions, meshEntries[i].normals, meshEntries[i].texCoords);
			}


			return true;
		}
	}
}