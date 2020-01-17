#include "pch.h"
#include "geometry.hpp"
#include "math.hpp"


namespace luna
{
	namespace math
	{
		double CircleCircumference(double radius)
		{
			return 2 * M_PI * radius;
		}

		double AreaOfCircle(double radius)
		{
			return M_PI * std::pow(radius, 2);
		}

		double AreaOfRectangle(double length, double width)
		{
			return length * width;
		}
	}
}