#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "src/core/graphics/window/Window.h"
#include "src/core/input/Input.h"
#include "src/core/Engine.h"
#include "src/core/camera/camera.h"

int main()
{
	using namespace broEngine;
	using namespace graphics;
	using namespace camera;
	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);
	Window* window = coreEngine::Init(props);

	Input_Controller::Input* controller = coreEngine::Init();


	glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	MainCamera* activeCamera = new MainCamera();

	activeCamera->Init();
	CameraInput cameraInput = CameraInput(activeCamera);


	while (!window->closed())
	{
		window->clear();
		//double x, y;
		activeCamera->Update(activeCamera->cameraPosition);
		cameraInput.OnInputUpdate(0.5f, 0);


		//controller->getMousePosition(x, y);

		//std::cout << controller->isKeyPressed(GLFW_KEY_A);
		//std::cout << window->isButtonPressed(GLFW_MOUSE_BUTTON_1);
		//std::cout << x << ", " << y << std::endl;

#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window->update();
	}

	//Terminate stuff
	glfwTerminate();
	return 0;
}