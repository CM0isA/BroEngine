#pragma once

#include <iostream>

namespace broEngine {
	namespace graphics {

		class WindowProperties
		{
			//properties
		public:
			WindowProperties(bool closed, std::string title, int width, int height);
			bool m_Closed;
			std::string m_Title;
		private:
			int m_Width;
			int m_Height;

			//methods
		public:
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

		};

	}
}