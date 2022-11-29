#include "VBO.h"
#include <glm/glm.hpp>

namespace broEngine {
	namespace graphics {
		VBO::VBO(std::vector<Vertex> vertex)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertex[0]) * vertex.size(), &vertex[0], GL_STATIC_DRAW);
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