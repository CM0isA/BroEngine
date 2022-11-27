#include "VAO.h"

namespace broEngine {
	namespace graphics {
		VAO::VAO()
		{
			glGenVertexArrays(1, &ID);
		}

		void VAO::LinkVBO(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
		{
			VBO.Bind();
			// Configure vertex attribute for VAO read
			glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
			// Enable the vertex attribute
			glEnableVertexAttribArray(layout);
			VBO.Unbind();
		}

		void VAO::Bind()
		{
			glBindVertexArray(ID);
		}

		void VAO::Unbind()
		{
			glBindVertexArray(0);
		}

		void VAO::Delete()
		{
			glDeleteVertexArrays(1, &ID);
		}
	}
}