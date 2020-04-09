#ifndef RAY_HPP
#define RAY_HPP
#include "vector3d.hpp"
#include "Point3d.hpp"

namespace luna
{
    class Ray
    {
        public:
            Ray() = default;
            Ray(const Vector3d& origin, const Vector3d& dir);
            ~Ray() = default;

            Vector3d& Origin();
            Vector3d& Direction();
            Vector3d PointAtParameter(float param) const;

        private:
            Vector3d mOrigin;
            Vector3d mDirection;
    };
}

#endif
