#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <GL/glew.h>

namespace broEngine {
	namespace graphics {
		std::string get_file_contents(std::string filename);


		class Shader {
		public:
			GLuint ID;
			Shader(const char* vertexFile, const char* fragmentFile);

			void Activate();
			void Delete();

		};
	}
}



#endif // !SHADER_CLASS_H

