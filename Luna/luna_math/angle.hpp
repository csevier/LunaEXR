#ifndef ANGLE_H
#define ANGLE_H
#include "math.hpp"

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
			static float DegreeToRadian(float angleInDegrees);
			static float RadianToDegree(float angleInRadians);

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
			return Angle(Angle::DegreeToRadian(angle));
		}

		inline float Angle::DegreeToRadian(float angleInDegrees)
		{
			return  angleInDegrees * M_PI / 180;
		}

		inline float  Angle::RadianToDegree(float angleInRadians)
		{
			return  angleInRadians * 180 / M_PI;
		}

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