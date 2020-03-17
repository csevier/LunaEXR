#include "FirstPersonCamera.hpp"
namespace luna
{
    void FirstPersonCamera::UpdatePosition(double deltaTime, GLFWwindow* window)
    {
        glfwGetCursorPos(window, &xpos, &ypos);

        // This should prolly not be here.
        const float cameraSpeed = 25.0f * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos -= cameraFront * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos += cameraFront * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos = cameraPos - cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos = cameraPos + cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;

        ProcessMousePosition();
    }

    Matrix4d FirstPersonCamera::GetView() const
    {
        luna::Matrix4d view{};
        luna::Vector3d center = cameraPos + cameraFront;
        return view * luna::Matrix4d::LookAt(cameraPos, center, cameraUp);
    }

    void FirstPersonCamera::ProcessMousePosition()
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
