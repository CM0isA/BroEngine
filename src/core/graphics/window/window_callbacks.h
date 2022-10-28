#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

namespace broEngine {
	namespace graphics {

		class WindowCallbacks
		{
		private:
			WindowCallbacks() = delete;
		public:
			// Window events
			static void OnResize(GLFWwindow* window, int width, int height);

			// keyboard 
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

			// mouse
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			static void mouse_click();

		};

	}
}