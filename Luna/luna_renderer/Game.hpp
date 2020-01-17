#ifndef GAME_H
#define GAME_H
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "shader.hpp"

class Game
{

public:
	Game(unsigned screenWidth = 800, unsigned screenHeight = 600):
		mScreenWidth{ screenWidth }, mScreenHeight{screenHeight}
	{
		InitializeGLFW();
	}
	void Run()
	{
		Shader shader{ "vert.glsl","frag.glsl" };
		float x = 0.0f;
		float inc = 0.01f;
		mLastFrameTime = glfwGetTime();
		while (!glfwWindowShouldClose(mWindow))
		{
			x += inc;
			if (x > 1.0f) inc = -0.1f;
			if (x < -1.0f) inc = 0.1f;
			shader.SetUniform("offset", x);
			Display(mWindow, glfwGetTime(), shader);
			glfwSwapBuffers(mWindow);
			glfwPollEvents();
		}
		glfwDestroyWindow(mWindow);
		glfwTerminate();
		exit(EXIT_SUCCESS);
	}

private:

	void Init(GLFWwindow* window)
	{
		glGenVertexArrays(mNumVAOs, mVao);
		glBindVertexArray(mVao[0]);
	}

	void InitializeGLFW()
	{
		if (!glfwInit())
		{
			exit(EXIT_FAILURE);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		mWindow = glfwCreateWindow(mScreenWidth, mScreenHeight, "On Existence", nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		if (glewInit() != GLEW_OK)
		{
			exit(EXIT_FAILURE);
		}
		// this is vsync, meaning it will wait for your monitors
		// refresh rate
		glfwSwapInterval(1);
		Init(mWindow);
	}

	void Display(GLFWwindow* window, double currentTime, Shader shader)
	{
		mFrameCount++;
		if (currentTime - mLastFrameTime >= 1.0)
		{
			std::cout << "FPS: " << std::to_string(mFrameCount) << std::endl;
			mLastFrameTime = currentTime;
			mFrameCount = 0;
		}

		glClear(GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader.Use();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	GLFWwindow* mWindow;
	unsigned mScreenWidth;
	unsigned mScreenHeight;
	const static int mNumVAOs = 1;
	GLuint mVao[mNumVAOs];
	double mLastFrameTime = 0;
	double mFrameCount = 0;
};
#endif