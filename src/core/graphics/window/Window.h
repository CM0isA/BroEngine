#pragma once

#define MAX_KEYS	1024
#define MAX_MOUSE	384

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "WindowProperties.h"

namespace broEngine {
	namespace graphics {
		struct WindowDataImpl;
		typedef WindowDataImpl* WindowData;

		class Window
		{
			friend class WindowCallbacks;
		private: //members
			WindowProperties props;
			WindowData m_WindowData;
			//GLFWwindow* m_Window;
			
			// Special keys
			int keyMods;

			// 
			static int keys[MAX_KEYS];
			static int mouseButtons[MAX_MOUSE];
			static double mouse_x, mouse_y;
		public:
			explicit Window(WindowProperties properties);
			~Window();
			bool closed() const;
			void update();
			void clear() const;
			int GetKeyMode();

		private: //methods
			bool init();

		protected:
			void key_callback(int key, int scanCode, int action, int mods);
		};
	}
}