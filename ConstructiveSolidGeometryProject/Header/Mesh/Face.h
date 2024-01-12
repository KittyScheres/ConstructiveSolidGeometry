#pragma once
#include "Vertex.h"
#include "Triangle.h"
#include <vector>

struct Face {
public:
	std::vector<Vertex> m_vertices;
	std::vector<Triangle> m_triangles;

public:
	Face() = default;
	Face(const std::vector<Vertex>& vertices, const Triangle& triangle);
	Face(const std::vector<Vertex>& vertices, const std::vector<Triangle>& triangles);
	void PushVertex(const Vertex& vertex);
	void PushVertex(const Vector3& position);
	void PushVertex(float x, float y, float z);
	void PushTriangle(const Triangle& triangle);
	void PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3);
};