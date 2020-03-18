#include "BoardGameCamera.hpp"
namespace luna
{
    void BoardGameCamera::UpdatePosition(double deltaTime)
    {
        glfwGetCursorPos(mWindow, &xpos, &ypos);

        // This should prolly not be here.
        const float cameraSpeed = 25.0f * deltaTime;
        if (glfwGetKey(mWindow, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos -= cameraFront * cameraSpeed;
        if (glfwGetKey(mWindow, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos += cameraFront * cameraSpeed;
        if (glfwGetKey(mWindow, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos = cameraPos - cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
        if (glfwGetKey(mWindow, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos = cameraPos + cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;

        ProcessMousePosition();
    }

    Matrix4d BoardGameCamera::GetView() const
    {
        luna::Matrix4d view{};
        luna::Vector3d center = cameraPos + cameraFront;
        return view * luna::Matrix4d::LookAt(cameraPos, center, cameraUp);
    }

    void BoardGameCamera::SetWindow(GLFWwindow *mWindow)
    {
        Camera::SetWindow(mWindow);
        EnableCursor();
    }

    void BoardGameCamera::ProcessMousePosition()
    {
        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        lastX = xpos;
        lastY = ypos;
    }
}
