#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "pch.h"
#include "geometry.hpp"
#include "math.hpp"

namespace luna
{
	namespace math
	{
		float CircleCircumference(float radius);
		float AreaOfCircle(float radius);
		float AreaOfRectangle(float length, float width);

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
}
#endif