#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "math.hpp"

namespace luna
{
	namespace math
	{
		inline double CircleCircumference(double radius)
		{
			return 2 * M_PI * radius;
		}

		inline double AreaOfCircle(double radius)
		{
			return M_PI * std::pow(radius, 2);
		}

		inline double AreaOfRectangle(double length, double width)
		{
			return length * width;
		}
	}
}
#endif