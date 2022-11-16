#include <glad/glad.h>
#include <iostream>
#include <vector>
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

namespace broEngine {
	namespace graphics {
		class VBO
		{
		public:
			GLuint ID;
			VBO(std::vector<float> vertices);

			void Bind();
			void Unbind();
			void Delete();
		};

	}
}

#endif // !VBO_CLASS_H



