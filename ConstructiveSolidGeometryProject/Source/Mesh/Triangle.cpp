#include "Mesh/Triangle.h"

Triangle::Triangle() {
	for (uint32_t index = 0; index < 3; index++)
		m_indices[index] = 0;
}

Triangle::Triangle(uint32_t index1, uint32_t index2, uint32_t index3) {
	m_indices[0] = index1;
	m_indices[1] = index2;
	m_indices[2] = index3;
}