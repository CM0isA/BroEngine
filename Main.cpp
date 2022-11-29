#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "src/core/graphics/window/Window.h"
#include "src/core/input/Input.h"
#include "src/core/Engine.h"
#include "src/core/camera/camera.h"
#include "src/core/graphics/shaders/ShaderClass.h"
#include "src/core/importer/Mesh.h"
#include "src/core/importer/Model.h"
using namespace broEngine;
using namespace graphics;
using namespace camera;
using namespace importer;

int main()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);




	WindowProperties props = WindowProperties(false, "BroEngine", 1980, 1080);
	Window* window = coreEngine::Init(props);

	Input_Controller::Input* controller = coreEngine::Init();
	MainCamera* activeCamera = new MainCamera();
	CameraInput cameraInput = CameraInput(activeCamera);

	glm::mat4 projectionMatrix = glm::perspective((60) * 0.0174532925194444f, 1980.0f / 1080.0f, 0.1f, 100.0f);
	glm::mat4 viewMatrix = activeCamera->GetViewMatrix();
	glm::vec3 position = glm::vec3(0, 0, 0);

	glm::mat4 ModelMatrix = glm::mat4(1);

	ModelMatrix = glm::translate(ModelMatrix, position);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	std::vector<Vertex> vertices = {
	{ glm::vec3(-1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0,0), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f) },
	{ glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0,1), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f) },
	{ glm::vec3( 1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1,1), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f) },
	{ glm::vec3( 1.0f, 0.0f,  1.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1,0), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f) }
	};

	std::vector<GLuint> indices = {
		0,1,2,
		0,2,3
	};

	Mesh modelFromData(vertices, indices);
	modelFromData.UploadData();

	Shader shaderProgram("VertexShader.glsl", "FragmentShader.glsl");

	//Model model("box.obj", "src\\models\\");
	//model.InitModel();


	while (!window->closed())
	{
		glClearColor(0.4f, 0.89f, 0.89f, 1.0f); //set clear color
		window->clear();

		cameraInput.OnInputUpdate(0.1f, 0); // camera input

		shaderProgram.Activate();
		glm::mat4 view = activeCamera->GetViewMatrix();

		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "Projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "View"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));

		//model.RenderModel();
		modelFromData.RenderMesh();
		window->update();
		glGetError();
	}
	


	//Terminate stuff
	glfwTerminate();
	return 0;
}