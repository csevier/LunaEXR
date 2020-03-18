#ifndef BOARDGAMECAMERA_HPP
#define BOARDGAMECAMERA_HPP
#include "vector3d.hpp"
#include "matrix4d.hpp"
#include <GLFW/glfw3.h>
#include "Camera.hpp"

namespace luna
{
    //TODO, this is not right, i clearly dont understand camera math yet.
    class BoardGameCamera : public Camera
    {
    public:
        BoardGameCamera()= default;
        void UpdatePosition(double deltaTime) override;
        Matrix4d GetView() const override;
        void SetWindow(GLFWwindow *mWindow) override;
    private:
        void ProcessMousePosition() override;
        bool firstMouse = true;
        double xpos;
        double ypos;
        float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
        float pitch = -45.0f;
        float lastX = 800.0f / 2.0;
        float lastY = 600.0 / 2.0;
        const luna::Vector4d inititalStart{0.0f, 0.0f, 3.0f, 0};
        const luna::Vector4d rotatedPos =  luna::Matrix4d::RotateX(luna::Angle::AngleFromDegrees(pitch)) * inititalStart;
        luna::Vector3d cameraPos = luna::Vector3d(rotatedPos.x(), rotatedPos.y(), rotatedPos.z());
        luna::Vector3d cameraFront = luna::Vector3d(0.0f, 0.0f, -1.0f);
        luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
    };
}

#endif
