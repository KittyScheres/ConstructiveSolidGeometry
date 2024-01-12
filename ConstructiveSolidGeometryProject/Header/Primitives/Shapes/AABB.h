#pragma once
#include "raymath.h"

namespace CSG {
	struct AABB {
		Vector3 m_minimum;
		Vector3 m_maximum;

		AABB() {
			m_minimum = Vector3(-0.5f, -0.5f, -0.5f);
			m_maximum = Vector3(0.5f, 0.5f, 0.5f);
		}

		AABB(Vector3 min, Vector3 max) {
			m_minimum = min;
			m_maximum = max;
		}
	};
}