#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

namespace broEngine {
	namespace graphics {

		class Window
		{
		private: //members
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;
		public:
			Window(const char* name, int width, int height);
			~Window();
			bool closed() const;
			void update() const;

		private: //methods
			bool init();
		};
	}
}