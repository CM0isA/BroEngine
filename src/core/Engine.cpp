#include "Engine.h"

namespace broEngine {

	graphics::Window* coreEngine::window = nullptr;
	Input_Controller::Input* coreEngine::controller = nullptr;


	graphics::Window* coreEngine::Init(graphics::WindowProperties& props)
	{
		// Initialize the library
		if (!glfwInit())
			exit(0);

		window = new graphics::Window(props);

		return window;
	}

	Input_Controller::Input* coreEngine::Init()
	{
		controller = new Input_Controller::Input();

		return controller;
	}


	graphics::Window* coreEngine::GetWindow()
	{
		return window;
	}

	Input_Controller::Input* coreEngine::GetInputController()
	{
		return controller;
	}

}