#pragma once
#include "Vertex.h"
#include "Face.h"

struct Mesh {
public:
	std::vector<Vertex> m_vertices;
	std::vector<Face> m_faces;

public:
	Mesh() = default;
	Mesh(std::vector<Vertex> vertices);
	Mesh(std::vector<Vertex> vertices, std::vector<Face> faces);
	void PushVertex(Vertex vertex);
	void PushVertex(Vector3 position);
	void PushVertex(float x, float y, float z);
	void PushFace(Face face);
	void StartNewFace();
	void PushTriangle(Triangle triangle);
	void PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3);
};