#pragma once
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "Texture.h"

namespace broEngine {
	namespace importer {
		class Model {
		public:
			glm::vec3 m_worldPosition = glm::vec3(0);

		protected:
			std::vector<Mesh> meshEntries;
			std::vector<Texture*> meshTextures;
			Assimp::Importer importer;
			const aiScene *scene;
			GLenum glDrawMode = GL_TRIANGLES;
			VAO vao;
		public:
			Model(std::string filename, std::string path = "");
			void InitModel();
			void RenderModel();
			void RenderMesh(unsigned int i);
		protected:
			bool InitFromScene(const aiScene* scene);
			void PopulateBuffers();
			void InitAllMeshes(const aiScene* scene);
			void ReserveSpace(unsigned int nrVertices, unsigned int nrIndices);
			void CountVerticesAndIndices(const aiScene* scene, unsigned int& nrIndices, unsigned int& nrVertices);
			void InitMesh(const aiMesh* paiMesh);
			void UploadData(std::vector<Vertex>& vertex, const std::vector<GLuint>& indices);


			//Store vertex and index data before loading into the GPU
			std::vector<Vertex> model_vertex;
			std::vector<GLuint> model_indices;

		};
		
	}
}

