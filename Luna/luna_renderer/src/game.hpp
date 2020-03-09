#ifndef GAME_H
#define GAME_H
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "shader.hpp"
#include "../../../luna_math/src/matrix4d.hpp"
#include "Mesh.hpp"
#include "Scene.hpp"
#include "Cube.hpp"


class Game
{
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

public:
	Game(float screenWidth = 1920.0f, float screenHeight = 1080.0f):
		mScreenWidth{ screenWidth }, mScreenHeight{ screenHeight }, mAspectRatio{mScreenWidth/mScreenHeight}
	{
		InitializeGLFW();
	}

	void Run()
	{
		Shader shader{ "./Debug/vert.glsl","./Debug/frag.glsl" };
		while (!glfwWindowShouldClose(mWindow))
		{
			double currentTime = glfwGetTime();
			processInput(mWindow, currentTime);
			glfwGetCursorPos(mWindow, &xpos, &ypos);
			Display(mWindow, currentTime, shader);
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

	void Display(GLFWwindow* window, double currentTime, Shader shader)
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
		cube.Update(currentTime);
		cube.Draw(shader);
		
	}

	void processInput(GLFWwindow* window, double currentTime)
	{
		mDeltaTime = currentTime - mLastFrameTime;
		mLastFrameTime = currentTime;
		const float cameraSpeed = 25.0f * mDeltaTime; // adjust accordingly
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPos -= cameraFront * cameraSpeed;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPos += cameraFront * cameraSpeed;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPos = cameraPos - cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPos = cameraPos + cameraFront.CrossProduct(cameraUp).Normalize() * cameraSpeed;
	}

	void HandleMouse() 
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

	GLFWwindow* mWindow;
	float mScreenWidth;
	float mScreenHeight;
	float mAspectRatio;
	const static int mNumVAOs = 1;
	GLuint mVao[mNumVAOs];
	double mLastFrameTime = 0;
	double mDeltaTime;
	bool firstMouse = true;
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
#endif