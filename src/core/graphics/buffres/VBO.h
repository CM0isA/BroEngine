#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

namespace broEngine {
	namespace graphics {
		class VBO
		{
		public:
			GLuint ID;
			VBO();
			VBO(std::vector<float> vertices);
			VBO(const std::vector<glm::vec2>& vector2, glm::vec2 vec2);
			VBO(const std::vector<glm::vec3>& positions, glm::vec3 vec3, bool one);

			void Bind();
			void Unbind();
			void Delete();
		};
	}
}

#endif // !VBO_CLASS_H



