#pragma once
#include <iostream>
#include "graphics/window/Window.h"

namespace broEngine {
	
	class coreEngine {
	public:
		static graphics::Window* Init(graphics::WindowProperties& props);

		static graphics::Window* GetWindow();

	private:
		static graphics::Window* window;
	};
}