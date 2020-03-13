#ifndef GAME_H
#define GAME_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "matrix4d.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Cube.hpp"

namespace luna
{
    class Game
    {
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        public:
            Game(float screenWidth = 800.0f, float screenHeight = 600.0f);
            void Run();

        private:
            void Init(GLFWwindow* window);
            void InitializeGLFW();
            void Display(GLFWwindow* window, double currentTime, Shader shader);
            void processInput(GLFWwindow* window, double currentTime);
            void HandleMouse();

            // Need TimeManger
            // Need Input Handler
            // Need Camera;
            GLFWwindow* mWindow;
            float mScreenWidth;
            float mScreenHeight;
            float mAspectRatio;
            const static int mNumVAOs = 1;
            GLuint mVao[mNumVAOs];
            double mLastFrameTime = 0;
            double mDeltaTime;
            bool firstMouse = true;
            int mFrameCount =0;
            double mFPS = 0;
            double mTimeStarted;
            double xpos;
            double ypos;
            float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
            float pitch = 0.0f;
            float lastX = 800.0f / 2.0;
            float lastY = 600.0 / 2.0;
            float fov = 45.0f;
            luna::Matrix4d projection{};
            luna::Vector3d cameraPos = luna::Vector3d(0.0f, 0.0f, -3.0f);
            luna::Vector3d cameraFront = luna::Vector3d(0.0f, 0.0f, -1.0f);
            luna::Vector3d cameraUp = luna::Vector3d(0.0f, 1.0f, 0.0f);
    };
}

#endif
