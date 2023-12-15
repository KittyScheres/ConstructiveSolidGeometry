#pragma once
#include "Triangle.h"
#include <vector>

struct Face {
public:
	std::vector<Triangle> m_triangles;

public:
	Face() = default;
	Face(Triangle triangle);
	Face(std::vector<Triangle> triangles);
	void PushTriangle(Triangle triangle);
	void PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3);
};