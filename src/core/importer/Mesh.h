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
			Mesh() {
				m_localPosition = glm::vec3(0, 0, 0);
				baseIndex = 0;
				baseVertex = 0;
				m_numIndices = 0;
				m_numVertices = 0;
				materialIndex = INVALID_MATERIAL;
			};
			Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);

			VAO meshVao;
			std::vector<Vertex> m_vertices;
			std::vector<GLuint> m_indices;
			unsigned int m_numVertices;
			unsigned int m_numIndices;
			unsigned int baseVertex;
			unsigned int baseIndex;
			unsigned int materialIndex;
			glm::vec3 m_localPosition;

		public:
			//void InitMesh(const aiMesh* paiMesh);
			//void UploadData(VAO& vao, std::vector<Vertex>& vertex, const std::vector<GLuint>& indices);
			//void UploadData(VAO& vao, const std::vector<float>& vertices, const std::vector<GLuint>& indices);
			void UploadData();
			void RenderMesh();
		};

	}
}


