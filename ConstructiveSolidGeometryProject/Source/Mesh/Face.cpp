#include "Mesh/Face.h"

Face::Face(Triangle triangle) {
	PushTriangle(triangle);
}

Face::Face(std::vector<Triangle> triangles) :
	m_triangles(triangles)
{}

void Face::PushTriangle(Triangle triangle) {
	m_triangles.push_back(triangle);
}

void Face::PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3) {
	PushTriangle(Triangle(index1, index2, index3));
}