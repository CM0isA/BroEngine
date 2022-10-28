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
			
			m_WindowData->handle = glfwCreateWindow(props.getWidth(), props.getHeight(), props.m_Title.c_str(), NULL, NULL);
			if (!m_WindowData)
			{
				glfwTerminate();
				std::cout << "Failed to create the main window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_WindowData->handle); //Use the window
			glfwSetWindowUserPointer(m_WindowData->handle, this);	
			glfwSetWindowSizeCallback(m_WindowData->handle, WindowCallbacks::OnResize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize glew" << std::endl;
				return false;
			}

			return true;
		}



		void Window::key_callback(int key, int scanCode, int action, int mods)
		{
			keyMods = mods;
			if (keyMods == false)
			{
				keys[key] = action ? true : false;

			}
		}
	

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		int Window::GetKeyMode()
		{
			return keyMods;
		}

		void Window::update() 
		{
			glfwPollEvents();

			glfwSwapBuffers(m_WindowData->handle);
		}


		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_WindowData->handle);
		}
	}
}