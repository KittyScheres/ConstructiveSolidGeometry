#include "Mesh/Face.h"

namespace CSG {
	Face::Face(const std::vector<Vertex>& vertices, const Triangle& triangle) :
		m_vertices(vertices)
	{
		PushTriangle(triangle);
	}

	Face::Face(const std::vector<Vertex>& vertices, const std::vector<Triangle>& triangles) :
		m_vertices(vertices),
		m_triangles(triangles)
	{}

	void Face::PushVertex(const Vertex& vertex) {
		m_vertices.push_back(vertex);
	}

	void Face::PushVertex(const Vector3& position) {
		m_vertices.push_back(Vertex(position));
	}

	void Face::PushVertex(float x, float y, float z) {
		m_vertices.push_back(Vertex(Vector3(x, y, z)));
	}

	void Face::PushTriangle(const Triangle& triangle) {
		m_triangles.push_back(triangle);
	}

	void Face::PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3) {
		PushTriangle(Triangle(index1, index2, index3));
	}
}