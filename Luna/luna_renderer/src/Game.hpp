#ifndef GAME_H
#define GAME_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "matrix4d.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Cube.hpp"
#include "TimeManger.hpp"
#include "FirstPersonCamera.hpp"
#include "BoardGameCamera.hpp"
#include <memory>

namespace luna
{
    class Game
    {
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        public:
            Game(float screenWidth = 800.0f, float screenHeight = 600.0f);
            void Run();

        private:
            void Initialize();
            void Display(GLFWwindow* window, Shader shader);
            void processInput(GLFWwindow* window);
            void HandleMouse();

            TimeManager mTimeManager;
            // Need Input Handler
            std::unique_ptr<Camera> mCamera;
            GLFWwindow* mWindow;
            float mScreenWidth;
            float mScreenHeight;
            float mAspectRatio;
            float fov = 45.0f;
            luna::Matrix4d projection{};
            Scene mSceneGraph;
    };
}

#endif
