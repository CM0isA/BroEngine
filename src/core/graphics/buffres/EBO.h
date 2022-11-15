//#include <GL/glew.h>
#include <glad/glad.h>
#include <vector>
#ifndef EBO_CLASS_H
#define EBO_CLASS_H

namespace broEngine {
	namespace graphics {
		class EBO
		{
		public:
			GLuint ID;
			EBO(std::vector<unsigned int> indices, GLsizeiptr size);

			void Bind();
			void Unbind();
			void Delete();
		};

	}
}

#endif // !EBO_CLASS_H



