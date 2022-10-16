#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	//Initialize glfw
	glfwInit();

	//Setup version for OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create main window
	GLFWwindow* window = glfwCreateWindow(800, 800, "BroEngine", NULL, NULL);
	glfwMakeContextCurrent(window); //Use the window

	gladLoadGL();//Load OpenGl

	//Specify window properties
	glViewport(0, 0, 800, 800);

	//window color
	glClearColor(0.4f, 0.89f, 0.89f, 1.0f);
	//clear the buffer color
	glClear(GL_COLOR_BUFFER_BIT);
	//swap buffer to display color
	glfwSwapBuffers(window);


	//Process window operations (avoid unresponding window)
	while (!glfwWindowShouldClose(window))
	{
		//glfw events
		glfwPollEvents();
	}

	//Terminate stuff
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}