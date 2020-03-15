#include "Game.hpp"
#include <string>

namespace luna
{
    void Game::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    Game::Game(float screenWidth, float screenHeight):
        mScreenWidth{ screenWidth }, mScreenHeight{ screenHeight }, mAspectRatio{mScreenWidth/mScreenHeight}
    {
        InitializeGLFW();
    }

    void Game::Run()
    {
        Shader shader{ "vert.glsl","frag.glsl" };
        while (!glfwWindowShouldClose(mWindow))
        {

            mTimeManager.UpdateTime();
            processInput(mWindow);
            glfwGetCursorPos(mWindow, &xpos, &ypos);
            Display(mWindow, shader);
            glfwSwapBuffers(mWindow);
            glfwPollEvents();
            //clear screen
            std::cout << std::string( 100, '\n' );
            std::cout << " Average FPS: " << mTimeManager.GetFPS() <<std::endl;
        }
        glfwDestroyWindow(mWindow);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    void Game::Init(GLFWwindow* window)
    {
        glGenVertexArrays(mNumVAOs, mVao);
        glBindVertexArray(mVao[0]);
    }

    void Game::InitializeGLFW()
    {
        if (!glfwInit())
        {
            exit(EXIT_FAILURE);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        mWindow = glfwCreateWindow(mScreenWidth, mScreenHeight, "Luna", nullptr, nullptr);
        glfwMakeContextCurrent(mWindow);
        glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
        glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        projection = projection * luna::Matrix4d::Perspective(luna::Angle::AngleFromDegrees(fov), mAspectRatio, 0.1f, 100.0f);
        if (glewInit() != GLEW_OK)
        {
            exit(EXIT_FAILURE);
        }
        // this is vsync, meaning it will wait for your monitors
        // refresh rate
        glfwSwapInterval(1);
        Init(mWindow);
    }

    void Game::Display(GLFWwindow* window, Shader shader)
    {
        HandleMouse();
        glClear(GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        luna::Cube cube{ luna::Vector3d(0.0f,  0.0f,  0.0f) };
        luna::Matrix4d view{};
        luna::Vector3d center = cameraPos + cameraFront;
        view = view * luna::Matrix4d::LookAt(cameraPos, center, cameraUp);
        shader.SetView(view);
        shader.SetProjection(projection);
        cube.Update(mTimeManager);
        cube.Draw(shader);

    }

    void Game::processInput(GLFWwindow* window)
    {
        const float cameraSpeed = 25.0f * mTimeManager.GetDeltaTime(); // adjust accordingly
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos -= cameraFront * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos += cameraFront * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos = cameraPos - cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos = cameraPos + cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
    }

    void Game::HandleMouse()
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
