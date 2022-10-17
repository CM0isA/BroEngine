#include<iostream>
#include<GLFW/glfw3.h>

#include "src/graphics/window/Window.h"

int main()
{
	using namespace broEngine;
	using namespace graphics;
	//std::string windowName = "BroEngine";
	//char* var = &windowName;
	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);

	Window window(props);

	glClearColor(0.4f, 0.89f, 0.89f, 1.0f);

	std::cout << glGetString(GL_VERSION);

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