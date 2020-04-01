#ifndef FIRSTPERSONMCAMERA_HPP
#define FIRSTPERSONMCAMERA_HPP
#include "vector3d.hpp"
#include "matrix4d.hpp"
#include <GLFW/glfw3.h>
#include "Camera.hpp"

namespace luna
{
    class FirstPersonCamera : public Camera
    {
    public:
        FirstPersonCamera()= default;
        void UpdatePosition(double deltaTime) override;
        Matrix4d GetView() const override;
        void SetWindow(GLFWwindow *mWindow) override;
    private:
        void ProcessMousePosition() override;
        bool firstMouse = true;
        double xpos;
        double ypos;
        float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
        float pitch = 0.0f;
        float lastX = 800.0f / 2.0;
        float lastY = 600.0 / 2.0;
        luna::Vector3d cameraPos = luna::Vector3d(0.0f, 0.0f, -3.0f);
        luna::Vector3d cameraFront = luna::Vector3d(0.0f, 0.0f, -1.0f);
        luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
    };
}

#endif