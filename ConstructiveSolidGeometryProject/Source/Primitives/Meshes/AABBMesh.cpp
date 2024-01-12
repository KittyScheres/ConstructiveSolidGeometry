#include "Primitives/Meshes/AABBMesh.h"
#include "Mesh/Face.h"

namespace CSG {
	AABBMesh::AABBMesh(const AABB& primitiveData) {
		const Vector3& min = primitiveData.m_minimum;
		const Vector3& max = primitiveData.m_maximum;

		// bottom face
		StartNewFace();
		PushVertex(min);
		PushVertex(min.x, min.y, max.z);
		PushVertex(max.x, min.y, min.z);
		PushVertex(max.x, min.y, max.z);
		PushTriangle(2, 1, 0);
		PushTriangle(2, 3, 1);

		// left face
		StartNewFace();
		PushVertex(min);
		PushVertex(min.x, max.y, min.z);
		PushVertex(min.x, max.y, max.z);
		PushVertex(min.x, min.y, max.z);
		PushTriangle(2, 1, 0);
		PushTriangle(0, 3, 2);

		// front face
		StartNewFace();
		PushVertex(min);
		PushVertex(min.x, max.y, min.z);
		PushVertex(max.x, min.y, min.z);
		PushVertex(max.x, max.y, min.z);
		PushTriangle(0, 1, 2);
		PushTriangle(1, 3, 2);

		// back face
		StartNewFace();
		PushVertex(min.x, min.y, max.z);
		PushVertex(max.x, min.y, max.z);
		PushVertex(max);
		PushVertex(min.x, max.y, max.z);
		PushTriangle(0, 1, 2);
		PushTriangle(2, 3, 0);

		// right face
		StartNewFace();
		PushVertex(max.x, min.y, min.z);
		PushVertex(max.x, max.y, min.z);
		PushVertex(max);
		PushVertex(max.x, min.y, max.z);
		PushTriangle(0, 1, 2);
		PushTriangle(2, 3, 0);

		// top face
		StartNewFace();
		PushVertex(min.x, max.y, min.z);
		PushVertex(max.x, max.y, min.z);
		PushVertex(max);
		PushVertex(min.x, max.y, max.z);
		PushTriangle(2, 1, 0);
		PushTriangle(0, 3, 2);
	}

	void AABBMesh::PushFaceTriangles() {
		PushTriangle(0, 1, 2);
		PushTriangle(2, 3, 0);
	}
}