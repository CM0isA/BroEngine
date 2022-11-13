#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"


namespace broEngine {
	namespace operations {
		class Transform {
		public:
			//Transform();
			////Transform(const Transform &transform);
			//virtual ~Transform();


		protected:
			// speeds
			float m_rotationSpeed;
			float m_tranlationSpeed;
			float m_scalingSpeed;

			bool m_isInMotion;

		};
	}
}
