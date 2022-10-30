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
		private: //members
			WindowProperties props;
			WindowData m_WindowData;
		public:
			explicit Window(WindowProperties properties);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

		private: //methods
			bool init();
		};
	}
}