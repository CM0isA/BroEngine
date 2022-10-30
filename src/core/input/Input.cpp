#include "Input.h"

namespace broEngine {
	namespace Input_Controller {
		int Input::m_keys[MAX_KEYS];
		int Input::m_mouseButtons[MAX_MOUSE];
		double Input::mouse_x;
		double Input::mouse_y;
		bool Input::keyMods;

		Input::Input()
		{
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_MOUSE; i++)
			{
				m_mouseButtons[i] = false;
			}
		}

		void Input::Init()
		{
		}


		void Input::mouse_buttons_callback(int button, int action, int mods)
		{
			m_mouseButtons[button] = action != GLFW_RELEASE;
		}

		void Input::cursor_position_callback(double xpos, double ypos)
		{
			mouse_x = xpos;
			mouse_y = ypos;
		}

		bool Input::isKeyPressed(unsigned int keyCode)
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return m_keys[keyCode];
		}

		bool Input::isButtonPressed(unsigned int buttonCode)
		{
			if (buttonCode >= MAX_MOUSE)
				return false;
			return m_mouseButtons[buttonCode];
		}

		void Input::getMousePosition(double& x, double& y)
		{
			x = mouse_x;
			y = mouse_y;
		}

		bool Input::GetKeyMode()
		{
			return false;
		}

		void Input::key_callback(int key, int scanCode, int action, int mods)
		{
			keyMods = mods;
			if (keyMods == false)
			{
				m_keys[key] = action != GLFW_RELEASE;
			}
		}
	}
}
