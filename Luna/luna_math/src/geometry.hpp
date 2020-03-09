#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "math.hpp"
#include "angle.hpp"

namespace luna
{
	float CircleCircumference(float radius)
	{
		return 2 * cPI * radius;
	}

	float AreaOfCircle(float radius)
	{
		return cPI * std::pow(radius, 2);
	}

	float AreaOfRectangle(float length, float width)
	{
		return length * width;
	}


	float Sec(Angle angle)
	{
		return 1 / std::cosf(angle.Radians());
	}

	float Csc(Angle angle)
	{
		return 1 / std::sinf(angle.Radians());
	}

	float Cot(Angle angle)
	{
		return 1 / std::tanf(angle.Radians());
	}

	float ArcLengthRadians(float radius, Angle angle)
	{
		return angle.Radians() * radius;
	}

	float ArcLengthDegrees(float radius, Angle angle)
	{
		return (angle.Degrees() / 360) * 2 * cPI * radius;
	}
}
#endif