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
			//std::cout << activeCamera->cameraPosition.x << " y: " << activeCamera->cameraPosition.y << " z: " << activeCamera->cameraPosition.z << std::endl;

			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_W)) activeCamera->MoveForward(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_A)) activeCamera->MoveLeft(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_S)) activeCamera->MoveBackward(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_D)) activeCamera->MoveRight(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_Q)) activeCamera->MoveUp(deltaTime);
			if (coreEngine::GetInputController()->KeyHold(GLFW_KEY_E)) activeCamera->MoveDown(deltaTime);
			OnMouseMove(coreEngine::GetInputController()->deltaX, coreEngine::GetInputController()->deltaY );
		}

		void CameraInput::OnKeyPress(int key, int mods)
		{
		}

		void CameraInput::OnMouseMove(float deltaX, float deltaY)
		{
			activeCamera->RotateOX(-deltaX * 0.01f);
			activeCamera->RotateOY(-deltaY * 0.01f);
		}

		void CameraInput::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
		{

		}

		void CameraInput::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
		{
		}
	}
}
