#include "WindowProperties.h"

namespace broEngine {
	namespace graphics {
		WindowProperties::WindowProperties(bool closed, std::string title, int height, int width)
		{
			m_Closed = closed;
			m_Title = title;
			m_Height = height;
			m_Width = width;
		}

		//WindowProperties::SetSize()
	}
}
