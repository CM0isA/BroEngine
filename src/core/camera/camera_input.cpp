#include "camera_input.h"
#include "../Engine.h"


namespace broEngine {
	namespace camera {
		CameraInput::CameraInput(MainCamera* activeCamera)
		{
			this->activeCamera = activeCamera;
		}

		void CameraInput::OnInputUpdate(float deltaTime, int mods)
		{
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_W)) activeCamera->MoveForward(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_A)) activeCamera->MoveLeft(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_S)) activeCamera->MoveBackward(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_D)) activeCamera->MoveRight(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_Q)) activeCamera->MoveUp(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_E)) activeCamera->MoveDown(deltaTime);
		}

		void CameraInput::OnKeyPress(int key, int mods)
		{
		}

		void CameraInput::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
		{
			activeCamera->RotateOX(-(float)deltaX);
			activeCamera->RotateOY(-(float)deltaY);
		}

		void CameraInput::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
		{

		}

		void CameraInput::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
		{
		}
	}
}
