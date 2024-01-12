#pragma once
#include "raymath.h"

struct AABB {
	Vector3 m_minimum;
	Vector3 m_maximum;

	AABB() {
		m_minimum = Vector3(-0.5f, -0.5f, -0.5f);
		m_maximum = Vector3(0.5f, 0.5f, 0.5f);
	}
};