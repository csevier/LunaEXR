#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"
#include "matrix4d.hpp"

class Game
{
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

public:
	Game(float screenWidth = 640.0f, float screenHeight = 480.0f):
		mScreenWidth{ screenWidth }, mScreenHeight{ screenHeight }, mAspectRatio{mScreenWidth/mScreenHeight}
	{
		InitializeGLFW();
	}

	void Run()
	{
		Shader shader("resources/shaders/vert.glsl", "resources/shaders/frag.glsl");
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
		projection = projection * luna::Matrix4d::Perspective(luna::AngleFromDegrees(fov), mAspectRatio, 0.1f, 100.0f);
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
		float vertices[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

	luna::Vector3d cubePositions[] = {
	 luna::Vector3d(0.0f,  0.0f,  0.0f),
	  luna::Vector3d(2.0f,  5.0f, -15.0f),
	luna::Vector3d(-1.5f, -2.2f, -2.5f),
	  luna::Vector3d(-3.8f, -2.0f, -12.3f),
	  luna::Vector3d(2.4f, -0.4f, -3.5f),
	  luna::Vector3d(-1.7f,  3.0f, -7.5f),
	  luna::Vector3d(1.3f, -2.0f, -2.5f),
	  luna::Vector3d(1.5f,  2.0f, -2.5f),
	  luna::Vector3d(1.5f,  0.2f, -1.5f),
	 luna::Vector3d(-1.3f,  1.0f, -1.5f)
	};
		
		glClear(GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnable(GL_DEPTH_TEST);
		glEnableVertexAttribArray(0);
		luna::Matrix4d model{};
		for (unsigned int i = 0; i < 10; i++)
		{
			luna::Matrix4d view{};
		    model = model * luna::Matrix4d::Translate(cubePositions[i]);
		    model = model * luna::Matrix4d::RotateY(luna::AngleFromDegrees(50.0f).Radians() * (float)currentTime);
			luna::Vector3d center = cameraPos + cameraFront;
			view = view * luna::Matrix4d::LookAt(cameraPos, center, cameraUp);
			shader.SetModel(model);
			shader.SetView(view);
			shader.SetProjection(projection);
			shader.Use();
			glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices));
		}
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

		luna::Angle aPitch = luna::AngleFromDegrees(pitch);
		luna::Angle aYaw = luna::AngleFromDegrees(yaw);

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
