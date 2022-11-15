#include<iostream>
#include<glad/glad.h>
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
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	std::vector<float> vertices = {
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	std::vector<GLuint> indices = {
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
	//ebo.Unbind();


	while (!window->closed())
	{
		glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color
		window->clear();

		cameraInput.OnInputUpdate(0.1f, 0); // camera input

		shaderProgram.Activate();
		glm::mat4 view = activeCamera->GetViewMatrix();

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "Projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "View"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "Model"), 1, GL_FALSE, glm::value_ptr(Model));

		vao.Bind();

		glDrawElements(
			GL_TRIANGLES,      // mode
			indices.size(),    // count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
		);

		//glDrawArrays(GL_TRIANGLES, 0, vertices.size());

		window->update();
	}


	vao.Delete();
	//ebo.Delete();
	vbo.Delete();


	//Terminate stuff
	glfwTerminate();
	return 0;
}