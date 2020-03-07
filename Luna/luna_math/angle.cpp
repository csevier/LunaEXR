#include "angle.hpp"

namespace luna 
{
	Angle::Angle(float angleInRadians)
	{
		mRadians = angleInRadians;
		mDegrees = Angle::RadianToDegree(angleInRadians);
	}

	bool Angle::operator==(const Angle& other) const
	{
		return mRadians == other.mRadians;
	}

	float Angle::Radians() const
	{
		return mRadians;
	}

	float Angle::Degrees() const
	{
		return mDegrees;
	}

	Angle Angle::AngleFromRadians(float angle)
	{
		return Angle(angle);
	}

	Angle Angle::AngleFromDegrees(float angle)
	{
		return Angle(Angle::DegreeToRadian(angle));
	}

	float Angle::DegreeToRadian(float angleInDegrees)
	{
		return  angleInDegrees * M_PI / 180;
	}

	float Angle::RadianToDegree(float angleInRadians)
	{
		return  angleInRadians * 180 / M_PI;
	}

	

}