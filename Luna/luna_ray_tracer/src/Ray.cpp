#include "Ray.hpp"


namespace luna
{
    Ray::Ray(const Vector3d& origin, const Vector3d& direction): mOrigin(origin), mDirection(direction)
    {

    }

    const Vector3d& Ray::Origin() const
    {
        return mOrigin;
    }

    const Vector3d& Ray::Direction() const
    {
        return mDirection;
    }

    Vector3d Ray::PointAtParameter(float param) const
    {
        return mOrigin + (mDirection * param);
    }
}
