#include "pch.h"
#include "geometry.hpp"
#include "math.hpp"


namespace luna
{
	namespace math
	{
		float CircleCircumference(float radius)
		{
			return 2 * M_PI * radius;
		}

		float AreaOfCircle(float radius)
		{
			return M_PI * std::pow(radius, 2);
		}

		float AreaOfRectangle(float length, float width)
		{
			return length * width;
		}
	}
}