#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "pch.h"
#include "math.hpp"

namespace luna
{
	inline float CircleCircumference(float radius)
	{
		return 2 * M_PI * radius;
	}

	inline float AreaOfCircle(float radius)
	{
		return M_PI * std::pow(radius, 2);
	}

	inline float AreaOfRectangle(float length, float width)
	{
		return length * width;
	}
}
#endif