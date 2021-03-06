#ifndef GAME_H
#define GAME_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "matrix4d.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "TimeManger.hpp"
#include "EditorCamera.hpp"
#include "FlyoverCamera.hpp"
#include <memory>

namespace luna
{
    class Game
    {
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        public:
            Game(float screenWidth = 800.0f, float screenHeight = 600.0f);
            void Run();
            void AddScene(const Scene& scene);

        private:
            void Initialize();
            void Display();
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
