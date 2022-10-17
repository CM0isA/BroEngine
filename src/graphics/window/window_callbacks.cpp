#include "window_callbacks.h"

#include <iostream>

void WindowCallbacks::OnResize(GLFWwindow* W, int width, int height)
{
	glfwGetFramebufferSize(W, &width, &height);
	glViewport(0, 0, width, height);
}
