#include "Primitives/Meshes/AABBMesh.h"
#include "Mesh/Face.h"

AABBMesh::AABBMesh(const AABB& primitiveData) {
	const Vector3& min = primitiveData.m_minimum;
	const Vector3& max = primitiveData.m_maximum;

	// Face 1
	StartNewFace();
	PushVertex(min);
	PushVertex(max.x, min.y, min.z);
	PushVertex(max.x, min.y, max.z);
	PushVertex(min.x, min.y, max.z);
	PushFaceTriangles();

	// Face 2
	StartNewFace();
	PushVertex(min);
	PushVertex(min.x, max.y, min.z);
	PushVertex(min.x, max.y, max.z);
	PushVertex(min.x, min.y, max.z);
	PushFaceTriangles();

	// Face 3
	StartNewFace();
	PushVertex(min);
	PushVertex(max.x, min.y, min.z);
	PushVertex(max.x, max.y, min.z);
	PushVertex(min.x, max.y, min.z);
	PushFaceTriangles();

	// Face 4
	StartNewFace();
	PushVertex(max);
	PushVertex(max.x, min.y, max.z);
	PushVertex(min.x, min.y, max.z);
	PushVertex(min.x, max.y, max.z);
	PushFaceTriangles();

	// Face 5
	StartNewFace();
	PushVertex(max);
	PushVertex(max.x, max.y, min.z);
	PushVertex(max.x, min.y, min.z);
	PushVertex(max.x, min.y, max.z);
	PushFaceTriangles();

	// Face 6
	StartNewFace();
	PushVertex(max);
	PushVertex(min.x, max.y, max.z);
	PushVertex(min.x, max.y, min.z);
	PushVertex(max.x, max.y, min.z);
	PushFaceTriangles();
}

void AABBMesh::PushFaceTriangles() {
	PushTriangle(0, 1, 2);
	PushTriangle(2, 3, 1);
}