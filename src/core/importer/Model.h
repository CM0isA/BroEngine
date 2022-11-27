#pragma once
#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"

namespace broEngine {
	namespace importer {
		class Model {
		public:
			glm::vec3 m_worldPosition = glm::vec3(0);

		protected:
			std::vector<Mesh> meshEntries;
			Assimp::Importer importer;
			const aiScene *scene;
			GLenum glDrawMode = GL_TRIANGLES;
		public:
			Model(std::string filename, std::string path = "");
			void InitModel();
		protected:
			bool InitFromScene(const aiScene* scene);
			std::vector<glm::vec3> model_positions;
			std::vector<glm::vec3> model_normals;
			std::vector<glm::vec2> model_texCoords;
			std::vector<GLuint> model_indices;

		};
		
	}
}

