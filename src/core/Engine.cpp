#include "Engine.h"

namespace broEngine {

	graphics::Window* coreEngine::window = nullptr;


	graphics::Window* coreEngine::Init(graphics::WindowProperties& props)
	{
		// Initialize the library
		if (!glfwInit())
			exit(0);

		window = new graphics::Window(props);

		return window;
	}

	graphics::Window* coreEngine::GetWindow()
	{
		return window;
	}

}