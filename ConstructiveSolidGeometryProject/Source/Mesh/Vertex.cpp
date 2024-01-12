#include "Mesh/Vertex.h"

Vertex::Vertex() :
	m_position(Vector3())
{}

Vertex::Vertex(float x, float y, float z) {
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

Vertex::Vertex(const Vector3& position) :
	m_position(position)
{}