#include "pch.h"
#include "trig.hpp"

namespace luna
{
	namespace math
	{
		double DegreeToRadian(double angleInDegrees)
		{
			return  angleInDegrees * M_PI / 180;
		}

		double RadianToDegree(double angleInRadians)
		{
			return  angleInRadians * 180 / M_PI;
		}

		double ArcLengthRadians(double radius, double angleInRadians)
		{
			return angleInRadians * radius;
		}

		double ArcLengthDegrees(double radius, double angleInDegrees)
		{
			return (angleInDegrees / 360) * 2 * M_PI * radius;
		}
	}
}