#include "Mesh/Mesh.h"

namespace CSG {
	Mesh::Mesh(const std::vector<Face>& faces) :
		m_faces(faces)
	{}

	void Mesh::PushFace(const Face& face) {
		m_faces.push_back(face);
	}

	void Mesh::StartNewFace() {
		m_faces.push_back(Face());
	}

	void Mesh::PushVertex(const Vertex& vertex) {
		if (!m_faces.empty())
			(*--m_faces.end()).PushVertex(vertex);
	}

	void Mesh::PushVertex(const Vector3& position) {
		if (!m_faces.empty())
			(*--m_faces.end()).PushVertex(position);
	}

	void Mesh::PushVertex(float x, float y, float z) {
		if (!m_faces.empty())
			(*--m_faces.end()).PushVertex(x, y, z);
	}

	void Mesh::PushTriangle(const Triangle& triangle) {
		if (!m_faces.empty())
			(*--m_faces.end()).PushTriangle(triangle);
	}

	void Mesh::PushTriangle(uint32_t index1, uint32_t index2, uint32_t index3) {
		if (!m_faces.empty())
			(*--m_faces.end()).PushTriangle(Triangle(index1, index2, index3));
	}
}