#include "Ray.hpp"


namespace luna
{
    Ray::Ray(const Vector3d& origin, const Vector3d& direction): mOrigin(origin), mDirection(direction)
    {

    }

    Vector3d& Ray::Origin()
    {
        return mOrigin;
    }

    Vector3d& Ray::Direction()
    {
        return mDirection;
    }

    Vector3d Ray::PointAtParameter(float param) const
    {
        return mOrigin + (mDirection * param);
    }
}
