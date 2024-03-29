#pragma once
#include "raymath.h"

namespace CSG {
	struct Vertex {
	public:
		Vector3 m_position;

	public:
		Vertex();
		Vertex(float x, float y, float z);
		Vertex(const Vector3& position);
	};
}