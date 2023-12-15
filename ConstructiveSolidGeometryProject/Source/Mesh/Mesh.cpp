#include "Mesh/Mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices) :
	m_vertices(vertices) 
{}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<Face> faces) :
	m_vertices(vertices),
	m_faces(faces)
{}

void Mesh::PushVertex(Vertex vertex) {
	m_vertices.push_back(vertex);
}

void Mesh::PushVertex(Vector3 position) {
	m_vertices.push_back(Vertex(position));
}

void Mesh::PushVertex(float x, float y, float z) {
	m_vertices.push_back(Vertex(x, y, z));
}

void Mesh::PushFace(Face face) {
	m_faces.push_back(face);
}

void Mesh::StartNewFace() {
	m_faces.push_back(Face());
}

void Mesh::PushTriangle(Triangle triangle) {
	if (!m_faces.empty())
		(*m_faces.end()).PushTriangle(triangle);
}

void Mesh::PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3) {
	if (!m_faces.empty())
		(*m_faces.end()).PushTriangle(Triangle(index1, index2, index3));
}