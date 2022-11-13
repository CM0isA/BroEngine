#pragma once

#include "../graphics/window/window_callbacks.h"
#include <GLFW/glfw3.h>

#define MAX_KEYS	1024
#define MAX_MOUSE	384

namespace broEngine {
	namespace Input_Controller {

		class Input {
			friend class graphics::WindowCallbacks;
			friend class graphics::Window;
		public:
			explicit Input();
		private:
			void Init();
			static int m_keys[MAX_KEYS];
			static int m_mouseButtons[MAX_MOUSE];
			static double mouse_x, mouse_y;

			// Special keys
			static bool keyMods;

		public:
			static bool isKeyPressed(unsigned int keyCode);
			static bool isButtonPressed(unsigned int buttonCode);
			static void getMousePosition(double& x, double& y);
			static bool GetKeyMode();
			static bool KeyHold(int keyCode);
			static bool GetSpecialKeyState();


		protected:
			void key_callback(int key, int scanCode, int action, int mods);
			void mouse_buttons_callback(int button, int action, int mods);
			void cursor_position_callback(double xpos, double ypos);

		protected:
			graphics::Window* window;

		};
	}
}
