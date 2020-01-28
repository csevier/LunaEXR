#ifndef TRIG_H
#define TRIG_H
#include "pch.h"
#include "trig.hpp"
#include "math.hpp"

namespace luna
{
	namespace math
	{
		float DegreeToRadian(float angleInDegrees);
		float RadianToDegree(float angleInRadians);
		float ArcLengthRadians(float radius, float angleInRadians);
		float ArcLengthDegrees(float radius, float angleInDegrees);
		float Sec(float angleInRadians);
		float Csc(float angleInRadians);
		float Cot(float angleInRadians);

		inline float DegreeToRadian(float angleInDegrees)
		{
			return  angleInDegrees * M_PI / 180;
		}

		inline float RadianToDegree(float angleInRadians)
		{
			return  angleInRadians * 180 / M_PI;
		}

		inline float ArcLengthRadians(float radius, float angleInRadians)
		{
			return angleInRadians * radius;
		}

		inline float ArcLengthDegrees(float radius, float angleInDegrees)
		{
			return (angleInDegrees / 360) * 2 * M_PI * radius;
		}

		inline float Sec(float angleInRadians)
		{
			return 1 / std::cosf(angleInRadians);
		}

		inline float Csc(float angleInRadians)
		{
			return 1 / std::sinf(angleInRadians);
		}

		inline float Cot(float angleInRadians)
		{
			return 1 / std::tanf(angleInRadians);
		}
		
	}
}
#endif