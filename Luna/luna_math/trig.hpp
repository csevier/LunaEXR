#ifndef TRIG_H
#define TRIG_H

namespace luna
{
	namespace math
	{
		float DegreeToRadian(float angleInDegrees);
		float RadianToDegree(float angleInRadians);
		float ArcLengthRadians(float radius, float angleInRadians);
		float ArcLengthDegrees(float radius, float angleInDegrees);
	}
}
#endif