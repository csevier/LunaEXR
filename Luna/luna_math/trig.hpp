#ifndef TRIG_H
#define TRIG_H
#include "pch.h"
#include "trig.hpp"
#include "math.hpp"
#include "angle.hpp"

namespace luna
{
	namespace math
	{
		inline float ArcLengthRadians(float radius, Angle angle)
		{
			return angle.Radians() * radius;
		}

		inline float ArcLengthDegrees(float radius, Angle angle)
		{
			return (angle.Degrees() / 360) * 2 * M_PI * radius;
		}

		inline float Sec(Angle angle)
		{
			return 1 / std::cosf(angle.Radians());
		}

		inline float Csc(Angle angle)
		{
			return 1 / std::sinf(angle.Radians());
		}

		inline float Cot(Angle angle)
		{
			return 1 / std::tanf(angle.Radians());
		}
	}
}
#endif