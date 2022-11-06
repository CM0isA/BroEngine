#pragma once

#include "camera_input.h"
#include <glm/glm.hpp>

namespace broEngine {
namespace camera {
class Camera {
	friend class camera_input;

public:
  Camera();
  ~Camera();

  void Init();
  virtual void update();

public:
  glm::vec3 cameraPosition;
  glm::vec3 cameraTarget;
  glm::vec3 cameraDirection;
  glm::vec3 cameraUp;
  glm::vec3 cameraRight;

  glm::mat4 LookAt;

};
} // namespace camera
} // namespace broEngine
