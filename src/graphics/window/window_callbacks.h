#pragma once

#include "GLFW/glfw3.h"


class WindowCallbacks
{
private:
	WindowCallbacks() = delete;
public:
	//Window events
	static void OnResize(GLFWwindow* W, int width, int height);

};