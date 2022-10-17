#include "WindowProperties.h"

namespace broEngine {
	namespace graphics {
		WindowProperties::WindowProperties(bool closed, std::string title, int width, int height)
		{
			m_Closed = closed;
			m_Title = title;
			m_Width = width;
			m_Height = height;
		}
	}
}
