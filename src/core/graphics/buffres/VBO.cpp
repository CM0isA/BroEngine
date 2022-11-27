#include "VBO.h"
#include <glm/glm.hpp>

namespace broEngine {
	namespace graphics {
		VBO::VBO()
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
		}
		VBO::VBO(std::vector<float> vertices)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
		}

		VBO::VBO(const std::vector<glm::vec2>& vec2, glm::vec2 vec)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, vec2.size() * sizeof(glm::vec2), &vec2[0], GL_STATIC_DRAW);
		}


		VBO::VBO(const std::vector<glm::vec3>& vec3, glm::vec3 vec, bool one)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, vec3.size() * sizeof(vec3[0]), &vec3[0], GL_STATIC_DRAW);
		}

		void VBO::Bind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, ID);
		}

		void VBO::Unbind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void VBO::Delete()
		{
			glDeleteBuffers(1, &ID);
		}
	}
}