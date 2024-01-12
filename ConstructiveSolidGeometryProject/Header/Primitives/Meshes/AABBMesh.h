#pragma once
#include "../../Mesh/Mesh.h"
#include "../Shapes/AABB.h"

class AABBMesh : public Mesh {
public:
	AABBMesh(const AABB& primitiveData = AABB());

private:
	void PushFaceTriangles();
};