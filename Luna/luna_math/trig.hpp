#ifndef TRIG_H
#define TRIG_H

#include "math.hpp"

namespace luna
{
	namespace math
	{
		inline double DegreeToRadian(double angleInDegrees)
		{
			return  angleInDegrees * M_PI / 180;
		}

		inline double RadianToDegree(double angleInRadians)
		{
			return  angleInRadians * 180 / M_PI;
		}

		inline double ArcLengthRadians(double radius, double angleInRadians)
		{
			return angleInRadians * radius;
		}

		inline double ArcLengthDegrees(double radius, double angleInDegrees)
		{
			return (angleInDegrees / 360) * 2 * M_PI * radius;
		}
	}
}
#endif