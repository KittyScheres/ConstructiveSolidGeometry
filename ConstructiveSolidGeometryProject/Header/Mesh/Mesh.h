#pragma once
#include "Face.h"

struct Mesh {
public:
	std::vector<Face> m_faces;

public:
	Mesh() = default;
	Mesh(const std::vector<Face>& faces);
	void PushFace(const Face& face);
	void StartNewFace();
	void PushVertex(const Vertex& vertex);
	void PushVertex(const Vector3& position);
	void PushVertex(float x, float y, float z);
	void PushTriangle(const Triangle& triangle);
	void PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3);
};