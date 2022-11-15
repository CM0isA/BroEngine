#pragma once

#include "camera_input.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"
#include <vector>

namespace broEngine {
	namespace camera {

		class Transform;

		struct ProjectionInfo {
			float FieldOfView;
			float zNear;
			float zFar;
			float aspectRatio;
			float width;
			float height;
			bool isPerpective;
		};

		class MainCamera {
			friend class CameraInput;

		public:
			MainCamera();
			~MainCamera();

			const glm::mat4& GetViewMatrix();

			//camera movement
			void MoveForward(float distance);
			void MoveBackward(float distance);
			void MoveRight(float distance);
			void MoveLeft(float distance);
			void MoveUp(float distance);
			void MoveDown(float distance);

			//camera rotations
			void RotateOX(float angle);
			void RotateOY(float angle);

		public:
			glm::vec3 cameraPosition;
			glm::vec3 cameraDirection;
			glm::vec3 cameraUp;
			glm::vec3 cameraRight;

		protected:
			glm::mat4 m_viewMatrix;

		};
	} // namespace camera
} // namespace broEngine
