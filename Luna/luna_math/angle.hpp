#ifndef ANGLE_H
#define ANGLE_H
#include "trig.hpp"



namespace luna 
{
	namespace math 
	{
		class Angle
		{
		public:
			Angle(float angleInRadians); 
			bool operator==(const Angle& other) const;
			float Degrees() const;
			float Radians() const;
		private:
			float mDegrees;
			float mRadians;
		};

		inline Angle::Angle(float angleInRadians)
		{
			mRadians = angleInRadians;
			mDegrees = RadianToDegree(angleInRadians);
		}

		inline bool Angle::operator==(const Angle& other) const 
		{
			return mRadians == other.mRadians;
		}

		inline float Angle::Radians() const
		{
			return mRadians;
		}

		inline float Angle::Degrees() const
		{
			return mDegrees;
		}

		inline Angle AngleFromRadians(float angle)
		{
			return Angle(angle);
		}

		inline Angle AngleFromDegrees(float angle)
		{
			return Angle(DegreeToRadian(angle));
		}
	}
}
	

#endif