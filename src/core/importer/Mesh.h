#pragma once
#include "../graphics/buffres/VAO.h"
#include "../graphics/buffres/VBO.h"
#include "../graphics/buffres/EBO.h"
#include <gl/GL.h>
#include <assimp/Importer.hpp>
#include "assimp/postprocess.h"
#include "assimp/scene.h"

namespace broEngine {
	namespace importer {
		using namespace graphics;
		class Mesh
		{
		public:
			Mesh(std::string filename, std::string path = "");
			Mesh(std::vector<float> vertices, std::vector<GLuint> indices);
			std::vector<float> m_vertices;
			std::vector<GLuint> m_indices;

			VAO vao;

			const aiScene* scene;

			void LoadMesh();
			void RenderMesh();

		};

	}
}


