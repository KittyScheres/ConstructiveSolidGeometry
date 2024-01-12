#pragma once
#include <cstdint>

namespace CSG {
	struct Triangle {
	public:
		uint32_t m_indices[3];

	public:
		Triangle();
		Triangle(uint32_t index1, uint32_t index2, uint32_t index3);
	};
}