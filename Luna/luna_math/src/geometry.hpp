#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "math.hpp"
#include "angle.hpp"

namespace luna
{
	float CircleCircumference(float radius);
	float AreaOfCircle(float radius);
	float AreaOfRectangle(float length, float width);
	float Sec(Angle angle);
	float Csc(Angle angle);
	float Cot(Angle angle);
	float ArcLengthRadians(float radius, Angle angle);
	float ArcLengthDegrees(float radius, Angle angle);
}
#endif