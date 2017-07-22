#pragma once

#include <vector>
#include "Vec3.h"

struct IndexedLineList
{
	std::vector<Vec3> vertices;
	std::vector<unsigned int> indices;
	//std::vector<size_t> indices;
};
