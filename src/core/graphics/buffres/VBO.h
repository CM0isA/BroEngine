#include <GL/glew.h>
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

namespace broEngine {
	namespace graphics {
		class VBO
		{
		public:
			GLuint ID;
			VBO(GLfloat* vertices, GLsizeiptr size);

			void Bind();
			void Unbind();
			void Delete();
		};

	}
}

#endif // !VBO_CLASS_H



