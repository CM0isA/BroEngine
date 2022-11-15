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
	CameraInput cameraInput = CameraInput(activeCamera);

	glm::mat4 projectionMatrix = glm::perspective((60) * 0.0174532925194444f, 1980.0f / 1080.0f, 0.1f, 100.0f);
	glm::mat4 viewMatrix = activeCamera->GetViewMatrix();
	glm::vec3 position = glm::vec3(0, 0, 0);

	glm::mat4 Model = glm::mat4(1);

	Model = glm::translate(Model, position);


	std::vector<float> vertices = {
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

	Shader shaderProgram("VertexShader.glsl", "FragmentShader.glsl");

	VAO vao;
	vao.Bind();
	VBO vbo(vertices, vertices.size());
	EBO ebo(indices, indices.size());

	//link vbo to vao
	vao.LinkVBO(vbo, 0);


	vao.Unbind();
	ebo.Unbind();


	while (!window->closed())
	{
		glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color
		window->clear();

		activeCamera->Update(); //camera properties
		cameraInput.OnInputUpdate(5.0f, 0); // camera input

		shaderProgram.Activate();
		//glUniformMatrix4fv(shaderProgram->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(glGetUniformLocation(1, "Projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(glGetUniformLocation(1, "View"), 1, GL_FALSE, glm::value_ptr(activeCamera->GetViewMatrix()));
		glUniformMatrix4fv(glGetUniformLocation(1, "Model"), 1, GL_FALSE, glm::value_ptr(Model));

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