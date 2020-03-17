#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "vector3d.hpp"
#include "matrix4d.hpp"
#include <GLFW/glfw3.h>

namespace luna
{
    class Camera
    {
    public:
        virtual void UpdatePosition(double deltaTime, GLFWwindow* window) = 0;
        virtual Matrix4d GetView() const = 0;

    private:
        virtual void ProcessMousePosition() =0;
    };
}

#endif
