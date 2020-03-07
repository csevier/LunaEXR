#ifndef ANGLE_H
#define ANGLE_H
#include "math.hpp"

namespace luna 
{
	class Angle
	{
	public:
		Angle(float angleInRadians); 
		bool operator==(const Angle& other) const;
		float Degrees() const;
		float Radians() const;
		static Angle AngleFromRadians(float angle);
		static Angle AngleFromDegrees(float angle);
		static float DegreeToRadian(float angleInDegrees);
		static float RadianToDegree(float angleInRadians);

	private:
		float mDegrees;
		float mRadians;
	};

	
}

#endif