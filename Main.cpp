#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "src/graphics/window/Window.h"

int main()
{
	using namespace broEngine;
	using namespace graphics;
	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);
	Window window(props); //Create a window
	glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	while (!window.closed())
	{
		window.clear();
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);

		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	//Terminate stuff
	glfwTerminate();
	return 0;
}