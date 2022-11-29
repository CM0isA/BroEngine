#pragma once
#include <glm/glm.hpp>

namespace broEngine {
	namespace importer {
		class Material {
		public:
			glm::vec4 ambient;
			glm::vec4 diffuse;
			glm::vec4 specular;
			glm::vec4 emissive;
			float shininess;
		public:
			Material() {
				ambient = glm::vec4(1);
			}
		};
	}
}