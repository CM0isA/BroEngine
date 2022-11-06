#include "camera.h"

namespace broEngine {
namespace camera {
void Camera::Init() {
  cameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
  cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
  cameraDirection = glm::normalize(cameraPosition - cameraTarget);
  glm::vec3 cameraRight =
      glm::normalize(glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), cameraDirection));

  glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

//   LookAt = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), 
//   		   glm::vec3(0.0f, 0.0f, 0.0f), 
//   		   glm::vec3(0.0f, 1.0f, 0.0f));
}

} // namespace camera
} // namespace broEngine