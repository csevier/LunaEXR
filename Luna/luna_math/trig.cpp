#include "pch.h"
#include "trig.hpp"
#include "math.hpp"


namespace luna
{
	namespace math
	{
		float DegreeToRadian(float angleInDegrees)
		{
			return  angleInDegrees * M_PI / 180;
		}

		float RadianToDegree(float angleInRadians)
		{
			return  angleInRadians * 180 / M_PI;
		}

		float ArcLengthRadians(float radius, float angleInRadians)
		{
			return angleInRadians * radius;
		}

		float ArcLengthDegrees(float radius, float angleInDegrees)
		{
			return (angleInDegrees / 360) * 2 * M_PI * radius;
		}
	}
}