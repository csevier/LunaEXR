#include "Camera.hpp"

namespace  luna
{
    void Camera::SetWindow(GLFWwindow* window)
    {
        mWindow = window;
    }

    void Camera::EnableCursor()
    {
        if(mWindow)
        {
            glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
    }

    void Camera::DisableCursor()
    {
        if(mWindow)
        {
            glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
    }

    const Vector3d& Camera::GetPosition() const
    {
        return cameraPos;
    }
}
