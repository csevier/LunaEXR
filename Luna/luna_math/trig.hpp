#ifndef TRIG_H
#define TRIG_H

#include "math.hpp"

namespace luna
{
	namespace math
	{
		double DegreeToRadian(double angleInDegrees);
		double RadianToDegree(double angleInRadians);
		double ArcLengthRadians(double radius, double angleInRadians);
		double ArcLengthDegrees(double radius, double angleInDegrees);
	}
}
#endif