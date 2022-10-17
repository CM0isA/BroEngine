#include "Window.h"

namespace broEngine {
	namespace graphics {
		struct WindowDataImpl
		{
			GLFWwindow* handle;
		};

		Window::Window(const char* name, int width, int height)
		{
			m_Title = name;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
		}

		Window::~Window() 
		{
			m_Closed = true;
			glfwTerminate();
		}

		void Window::SetSize(int width, int height)
		{
			int frameBufferWidth, frameBufferHeight;
			//glfwGetFramebufferSize(window->handle, &frameBufferWidth, &frameBufferHeight);


		}

		bool Window::init()
		{
			if (!glfwInit())
				std::cout << "Failed to initialize window" << std::endl;
			else
				std::cout << "Window initialized" << std::endl;
			m_Closed = false;
			
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create the main window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window); //Use the window

			return true;
		}

		

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void Window::update() 
		{
			glfwPollEvents();

			glfwSwapBuffers(m_Window);
		}


		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}
	}
}