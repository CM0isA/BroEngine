#pragma once

#include <glm/glm.hpp>
#include "camera.h"
#include "../input/Input.h"

namespace broEngine {
	namespace camera {

		class MainCamera;

		class CameraInput : Input_Controller::Input
		{
		public:
			CameraInput(MainCamera* activeCamera);
			void OnInputUpdate(float deltaTime, int mods);
			void OnKeyPress(int key, int mods);
			void OnMouseMove(float deltaX, float deltaY);
			void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods);
			void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods);

		public:
			MainCamera* activeCamera;
		};
	} // namespace camera
} // namespace broEngine
