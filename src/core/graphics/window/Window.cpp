#include "Window.h"
#include "window_callbacks.h"

namespace broEngine {
	namespace graphics {
		struct WindowDataImpl
		{
			GLFWwindow* handle;
		};

		Window::Window(WindowProperties properties) : props(properties)
		{
			m_WindowData = new WindowDataImpl();
			m_WindowData->handle = nullptr;
			if (!init())
				glfwTerminate();
		}

		Window::~Window() 
		{
			props.m_Closed = true;
			glfwDestroyWindow(m_WindowData->handle);
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
				std::cout << "Failed to initialize window" << std::endl;
			else
				std::cout << "Window initialized" << std::endl;
			props.m_Closed = false;

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			
			m_WindowData->handle = glfwCreateWindow(props.getWidth(), props.getHeight(), props.m_Title.c_str(), NULL, NULL);
			if (!m_WindowData)
			{
				glfwTerminate();
				std::cout << "Failed to create the main window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_WindowData->handle); //Use the window
			glfwSetWindowUserPointer(m_WindowData->handle, this); //Point to the window
			glfwSetWindowSizeCallback(m_WindowData->handle, WindowCallbacks::OnResize); // Window size
			glfwSetKeyCallback(m_WindowData->handle, WindowCallbacks::key_callback); // Keyboard 
			glfwSetMouseButtonCallback(m_WindowData->handle, WindowCallbacks::mouse_buttons_callback); // Mouse button
			glfwSetCursorPosCallback(m_WindowData->handle, WindowCallbacks::cursor_position_callback); // Mouse position

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize glew" << std::endl;
				return false;
			}

			return true;
		}


		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT); //clean back buffer and assign a new color to it
		}

		void Window::update() 
		{
			glfwSwapBuffers(m_WindowData->handle);
			glfwPollEvents();
		}


		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_WindowData->handle);
		}

	}
}