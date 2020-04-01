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
        mCamera = std::make_unique<FirstPersonCamera>();
        Initialize();
    }

    void Game::Run()
    {
        Shader shader{ "vert.glsl","frag.glsl" };
        // Read in scene;
        luna::Cube cube{ luna::Vector3d(0.0f,  0.0f,  0.0f) };
        mSceneGraph.AddObject(&cube);
        while (!glfwWindowShouldClose(mWindow))
        {
            mTimeManager.UpdateTime();
            mCamera->UpdatePosition(mTimeManager.GetDeltaTime());
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

    void Game::Initialize()
    {
        if (!glfwInit())
        {
            exit(EXIT_FAILURE);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        mWindow = glfwCreateWindow(mScreenWidth, mScreenHeight, "Luna", nullptr, nullptr);
        mCamera->SetWindow(mWindow);
        glfwMakeContextCurrent(mWindow);
        glfwSetFramebufferSizeCallback(mWindow, framebuffer_size_callback);
        if (glewInit() != GLEW_OK)
        {
            exit(EXIT_FAILURE);
        }
         projection = projection * luna::Matrix4d::Perspective(luna::Angle::AngleFromDegrees(fov), mAspectRatio, 0.1f, 100.0f);
        // this is vsync, meaning it will wait for your monitors
        // refresh rate
        glfwSwapInterval(1);
        glEnable(GL_DEPTH_TEST);
    }

    void Game::Display(GLFWwindow* window, Shader shader)
    {
        glClear(GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader.SetView(mCamera->GetView());
        shader.SetProjection(projection);
        mSceneGraph.UpdateScene(mTimeManager);
        mSceneGraph.DrawScene(shader);
    }
}
