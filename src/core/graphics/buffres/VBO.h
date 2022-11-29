#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

namespace broEngine {
	namespace graphics {
		struct Vertex {
			glm::vec3 positions;
			glm::vec3 normals;
			glm::vec2 texCoordinates;
			glm::vec4 color;
		};


		class VBO
		{
		public:
			GLuint ID;
			VBO(std::vector<Vertex> vertex);

			void Bind();
			void Unbind();
			void Delete();
		};
	}
}

#endif // !VBO_CLASS_H



