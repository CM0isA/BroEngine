#include<iostream>
#include<GLFW/glfw3.h>

#include "src/graphics/window/Window.h"

int main()
{
	using namespace broEngine;
	using namespace graphics;
	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);
	Window window(props); //Create a window
	glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color


	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		window.update();
	}

	//Terminate stuff
	glfwTerminate();
	return 0;
}