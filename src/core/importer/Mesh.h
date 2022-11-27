#pragma once
#include "../graphics/buffres/VAO.h"
#include "../graphics/buffres/VBO.h"
#include "../graphics/buffres/EBO.h"
#include <glm/glm.hpp>
#include <gl/GL.h>
#include <assimp/Importer.hpp>
#include "assimp/postprocess.h"
#include "assimp/scene.h"

namespace broEngine {
	namespace importer {
		using namespace graphics;

		static const unsigned int INVALID_MATERIAL = std::numeric_limits<unsigned int>::max();

		class Mesh
		{
		public:
			Mesh();
			Mesh(std::vector<float> vertices, std::vector<GLuint> indices);
			std::vector<float> m_vertices;
			std::vector<GLuint> m_indices;
			unsigned int m_numVertices;
			unsigned int m_numIndices;
			unsigned int baseVertex;
			unsigned int baseIndex;

			unsigned int materialIndex;
			std::vector<glm::vec3> positions;
			std::vector<glm::vec3> normals;
			std::vector<glm::vec2> texCoords;
			glm::vec3 m_localPosition;

			VAO vao;

			void LoadMesh();
			void RenderMesh();

		private:
			void Clear();


		public:
			void InitMesh(const aiMesh* paiMesh);
			void UploadData(const std::vector<glm::vec3>& positions, const std::vector<glm::vec3>& normals, const std::vector<glm::vec2>& texCoords);
			void UploadData(const std::vector<float>& vertices, const std::vector<float>& indices);
		};

	}
}


