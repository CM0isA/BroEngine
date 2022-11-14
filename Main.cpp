#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "src/core/graphics/window/Window.h"
#include "src/core/input/Input.h"
#include "src/core/Engine.h"
#include "src/core/camera/camera.h"
#include "src/core/graphics/buffres/EBO.h"
#include "src/core/graphics/buffres/VAO.h"
#include "src/core/graphics/buffres/VBO.h"
#include "src/core/graphics/shaders/ShaderClass.h"


int main()
{
	using namespace broEngine;
	using namespace graphics;
	using namespace camera;
	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);
	Window* window = coreEngine::Init(props);

	Input_Controller::Input* controller = coreEngine::Init();
	MainCamera* activeCamera = new MainCamera();

	activeCamera->Init();
	CameraInput cameraInput = CameraInput(activeCamera);

	GLfloat vertices[] = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	std::vector<unsigned int> indices = {
		0,3,5,
		3,2,4,
		5,4,1
	};

	Shader shaderProgram("VertexShader.vert", "FragmentShader.frag");

	VAO vao;
	vao.Bind();

	VBO vbo(vertices, sizeof(vertices));

	EBO ebo(indices, sizeof(indices));

	//link vbo to vao
	vao.LinkVBO(vbo, 0);


	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();


	while (!window->closed())
	{
		glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color
		window->clear();

		activeCamera->Update(activeCamera->cameraPosition); //camera properties
		cameraInput.OnInputUpdate(0.5f, 0); // camera input

		shaderProgram.Activate();
		vao.Bind();

		glDrawElements(
			GL_TRIANGLES,      // mode
			indices.size(),    // count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
		);
		window->update();
	}


	vao.Delete();
	ebo.Delete();
	vbo.Delete();


	//Terminate stuff
	glfwTerminate();
	return 0;
}