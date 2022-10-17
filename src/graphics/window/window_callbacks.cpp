#include "window_callbacks.h"

#include <iostream>

void WindowCallbacks::OnResize(GLFWwindow* window, int width, int height)
{
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
}
