#pragma once
#include "raymath.h"

struct Vertex {
public:
	Vector3 m_position;

public:
	Vertex();
	Vertex(float x, float y, float z);
	Vertex(Vector3 position);
};