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
			EBO(std::vector<GLuint> indices);

			void Bind();
			void Unbind();
			void Delete();
		};

	}
}

#endif // !EBO_CLASS_H



