#include "VAO.h"

namespace broEngine {
	namespace graphics {
		VAO::VAO()
		{
			glGenVertexArrays(1, &ID);
		}

		void VAO::LinkVBO(VBO& VBO, GLuint layout)
		{
			VBO.Bind();
			// Configure vertex attribute for VAO read
			glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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