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
        virtual void UpdatePosition(double deltaTime) = 0;
        virtual Matrix4d GetView() const = 0;
        virtual void SetWindow(GLFWwindow* mWindow);
        void EnableCursor();
        void DisableCursor();
        const Vector3d& GetPosition() const;

    protected:
        virtual void ProcessMousePosition() =0;
        GLFWwindow* mWindow;
        luna::Vector3d cameraPos = luna::Vector3d(0.0f, 0.0f, -3.0f);
        luna::Vector3d cameraFront = luna::Vector3d(0.0f, 0.0f, -1.0f);
        luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
    };
}

#endif
