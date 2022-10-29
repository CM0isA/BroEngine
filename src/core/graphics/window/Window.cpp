#include "Window.h"
#include "window_callbacks.h"

namespace broEngine {
	namespace graphics {
		int Window::m_keys[MAX_KEYS];
		int Window::m_mouseButtons[MAX_MOUSE];
		double Window::mouse_x;
		double Window::mouse_y;


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

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_MOUSE; i++)
			{
				m_mouseButtons[i] = false;
			}
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
			glfwSetWindowUserPointer(m_WindowData->handle, this); //Point to the window
			glfwSetWindowSizeCallback(m_WindowData->handle, WindowCallbacks::OnResize); // Window size
			glfwSetKeyCallback(m_WindowData->handle, WindowCallbacks::key_callback); // Keyboard 
			glfwSetMouseButtonCallback(m_WindowData->handle, WindowCallbacks::mouse_callback); // Mouse button
			glfwSetCursorPosCallback(m_WindowData->handle, WindowCallbacks::cursor_position_callback); // Mouse position

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
				m_keys[key] = action != GLFW_RELEASE;
			}
		}

		void Window::mouse_buttons_callback(int button, int action, int mods)
		{
			m_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void Window::cursor_position_callback(double xpos, double ypos)
		{
			mouse_x = xpos;
			mouse_y = ypos;
			//return mouse_x, mouse_y;
		}
	

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		int Window::GetKeyMode()
		{
			return keyMods;
		}

		bool Window::isKeyPressed(unsigned int keyCode)
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return m_keys[keyCode];
		}

		bool Window::isButtonPressed(unsigned int buttonCode)
		{
			if (buttonCode >= MAX_MOUSE)
				return false;
			return m_mouseButtons[buttonCode];
		}

		void Window::getMousePosition(double& x, double& y)
		{
			x = mouse_x;
			y = mouse_y;
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