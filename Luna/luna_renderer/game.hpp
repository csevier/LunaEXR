#ifndef GAME_H
#define GAME_H
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "shader.hpp"
#include "../luna_math/matrix4d.hpp";
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
		while (!glfwWindowShouldClose(mWindow))
		{
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
		float vertices[] = {
	   -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
		};
		glClear(GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		luna::Matrix4d model{};
		model = model * luna::Matrix4d::RotateX(luna::AngleFromDegrees(50.0f).Radians()*(float)currentTime);
		model = model * luna::Matrix4d::RotateY(luna::AngleFromDegrees(50.0f).Radians()*(float)currentTime);
		model = model * luna::Matrix4d::RotateZ(luna::AngleFromDegrees(50.0f).Radians()*(float)currentTime);
		luna::Matrix4d view{};
		view = view * luna::Matrix4d::Translate({ cosf(currentTime),cosf(currentTime), 0 });
		luna::Matrix4d projection = luna::Matrix4d::Perspective(luna::AngleFromDegrees(45), 800.0f / 600.0f, 0.1f, 100.0f);
		shader.SetModel(model);
		shader.SetView(view);
		//shader.SetProjection(projection);
		shader.Use();
		glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
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