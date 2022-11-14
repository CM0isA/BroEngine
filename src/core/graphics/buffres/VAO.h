#include <GL/glew.h>
#include "VBO.h"
#ifndef VAO_CLASS_H
#define VAO_CLASS_H

namespace broEngine {
	namespace graphics {
		class VAO
		{
		public:
			GLuint ID;
			VAO();

			void LinkVBO(VBO& VBO, GLuint layout);

			void Bind();
			void Unbind();
			void Delete();
		};

	}
}

#endif // !VBO_CLASS_H



