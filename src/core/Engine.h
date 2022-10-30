#pragma once
#include <iostream>
#include "graphics/window/Window.h"
#include "input/Input.h"

namespace broEngine {
	
	class coreEngine {
	public:
		static graphics::Window* Init(graphics::WindowProperties& props);

		static graphics::Window* GetWindow();

		static Input_Controller::Input* Init();

		static Input_Controller::Input* GetInputController();


	private:
		static graphics::Window* window;

		static Input_Controller::Input* controller;
	};
}