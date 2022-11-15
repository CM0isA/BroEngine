#include "VBO.h"

namespace broEngine {
	namespace graphics {
		VBO::VBO(std::vector<float> vertices, GLsizeiptr size)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
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