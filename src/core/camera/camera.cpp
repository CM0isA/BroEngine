#include <iostream>
#include "camera.h"

namespace broEngine {
	namespace camera {
		MainCamera::MainCamera()
		{
			cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
			cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
			cameraRight =
				glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), cameraDirection));
			cameraUp = glm::cross(cameraDirection, cameraRight);
			m_viewMatrix = glm::lookAt(cameraPosition, glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
		}
		MainCamera::~MainCamera()
		{
		}

		const glm::mat4& MainCamera::GetViewMatrix()
		{
			return glm::lookAt(cameraPosition, cameraPosition + cameraDirection, cameraUp);
		}

		void MainCamera::MoveForward(float distance)
		{
			glm::vec3 direction = glm::normalize(cameraDirection);
			cameraPosition += direction * distance;
		}

		void MainCamera::MoveBackward(float distance)
		{
			glm::vec3 direction = glm::normalize(cameraDirection);
			cameraPosition -= direction * distance;
		}

		void MainCamera::MoveRight(float distance)
		{
			glm::vec3 direction = glm::normalize(glm::cross(cameraDirection, cameraUp));
			cameraPosition += direction * distance;

		}

		void MainCamera::MoveLeft(float distance)
		{
			glm::vec3 direction = glm::normalize(glm::cross(cameraDirection, cameraUp));
			cameraPosition -= direction * distance;
		}

		void MainCamera::MoveUp(float distance)
		{
			glm::vec3 dir = glm::normalize(cameraUp);
			cameraPosition += dir * distance;
		}

		void MainCamera::MoveDown(float distance)
		{
			glm::vec3 dir = glm::normalize(cameraUp);
			cameraPosition -= dir * distance;
		}

		void MainCamera::RotateOX(float angle)
		{
			cameraDirection = glm::normalize(glm::vec3(glm::rotate(glm::mat4(1), angle, cameraRight) * glm::vec4(cameraDirection, 1)));
			cameraUp = glm::normalize(glm::cross(cameraRight, cameraDirection));
		}

		void MainCamera::RotateOY(float angle)
		{
			cameraDirection = glm::normalize(glm::vec3(glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0)) * glm::vec4(cameraDirection, 1)));
			cameraRight = glm::normalize(glm::vec3(glm::rotate(glm::mat4(1), angle, glm::vec3(0, 1, 0)) * glm::vec4(cameraRight, 1)));
			cameraUp = glm::normalize(glm::cross(cameraDirection, cameraUp));
		}


	} // namespace camera
} // namespace broEngine