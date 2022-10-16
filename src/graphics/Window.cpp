#include "Window.h"

namespace broEngine {
	namespace graphics {
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
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
				std::cout << "Failed to initialize window" << std::endl;
			else
				std::cout << "Window initialized" << std::endl;
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (m_Window == NULL)
			{
				std::cout << "Failed to create the main window" << std::endl;
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(m_Window); //Use the window

			return true;

		}

		void Window::update() const
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose;
		}
	}
}