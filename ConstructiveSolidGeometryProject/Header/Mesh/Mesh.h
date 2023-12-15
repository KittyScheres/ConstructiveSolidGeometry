#pragma once
#include "Vertex.h"
#include "Face.h"

struct Mesh {
	std::vector<Vertex> m_vertices;
	std::vector<Face> m_faces;
};