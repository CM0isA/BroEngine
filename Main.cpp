#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "src/core/graphics/window/Window.h"
#include "src/core/input/Input.h"
#include "src/core/Engine.h"
#include "src/core/camera/camera.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(0.8f, 0.3f, 0.2f, 1.0);\n"
"}\n\0";


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

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(fragmentShader, vertexShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLuint VAO, VBO, elementBuffer;

	// Generate the VAO, VBO, and EBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &elementBuffer);
	glGenBuffers(1, &VBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Bind the VBO specifying it's a GL_ELEMENT_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	// Introduce the indices into the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	// Configure vertex attribute for VAO read
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// Enable the vertex attribute
	glEnableVertexAttribArray(0);

	// Bind VBO and VAO to 0
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);




	while (!window->closed())
	{
		glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color
		window->clear();

		activeCamera->Update(activeCamera->cameraPosition); //camera properties
		cameraInput.OnInputUpdate(0.5f, 0); // camera input

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

		glDrawElements(
			GL_TRIANGLES,      // mode
			indices.size(),    // count
			GL_UNSIGNED_INT,   // type
			(void*)0           // element array buffer offset
		);
		window->update();
	}


	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &elementBuffer);
	glDeleteProgram(shaderProgram);

	//Terminate stuff
	glfwTerminate();
	return 0;
}