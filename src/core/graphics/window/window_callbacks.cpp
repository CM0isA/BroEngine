#include "window_callbacks.h"

#include <iostream>
#include "../../Engine.h"

namespace broEngine {
	namespace graphics {
		void WindowCallbacks::OnResize(GLFWwindow* window, int width, int height)
		{
			glfwGetFramebufferSize(window, &width, &height);
			glViewport(0, 0, width, height);
		}

		void WindowCallbacks::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			coreEngine::GetWindow()->key_callback(key, scancode, action, mods);
		}

		void WindowCallbacks::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{

		}

		void WindowCallbacks::mouse_click()
		{

		}


	}
}