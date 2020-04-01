#include "EditorCamera.hpp"

namespace luna
{
    void EditorCamera::UpdatePosition(double deltaTime)
    {
        glfwGetCursorPos(mWindow, &xpos, &ypos);

        if(glfwGetMouseButton(mWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        {
            CursorMode = false;
            DisableCursor();

        }
        else
        {
           CursorMode = true;
           EnableCursor();
        }

        if(!CursorMode)
        {
            // This should prolly not be here.
            const float cameraSpeed = 15.0f * deltaTime;
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
    }

    Matrix4d EditorCamera::GetView() const
    {
        luna::Matrix4d view{};
        luna::Vector3d center = cameraPos + cameraFront;
        return view * luna::Matrix4d::LookAt(cameraPos, center, cameraUp);
    }

    void EditorCamera::SetWindow(GLFWwindow *mWindow)
    {
        Camera::SetWindow(mWindow);
        DisableCursor();
    }

    void EditorCamera::ProcessMousePosition()
    {
        if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.05;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw -= xoffset;
        pitch -= yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        luna::Angle aPitch = luna::Angle::AngleFromDegrees(pitch);
        luna::Angle aYaw = luna::Angle::AngleFromDegrees(yaw);

        float x = cos(aYaw.Radians()) * cos(aPitch.Radians());
        float y = sin(aPitch.Radians());
        float z = sin(aYaw.Radians()) * cos(aPitch.Radians());
        const luna::Vector3d direction{ x, y, z };
        cameraFront = direction.Normalize();
    }
}
