#include "geometry.hpp"
#include <math.h>
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
        return 1 / std::cos(angle.Radians());
	}

	float Csc(Angle angle)
	{
        return 1 / std::sin(angle.Radians());
	}

	float Cot(Angle angle)
	{
        return 1 / std::tan(angle.Radians());
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
