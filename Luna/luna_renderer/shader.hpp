#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../luna_math/matrix4d.hpp";
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{

public:
	Shader(const char* vertexPath, const char* fragmentPath)
	{
		try
		{
			std::string vertexCode = ReadShaderSource(vertexPath);
			std::string fragmentCode = ReadShaderSource(fragmentPath);
			const char* vShaderSource = vertexCode.c_str();
			const char* fShaderSource = fragmentCode.c_str();
			GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
			GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(vShader, 1, &vShaderSource, nullptr);
			glShaderSource(fShader, 1, &fShaderSource, nullptr);
			glCompileShader(vShader);
			int success;
			glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << std::endl;
				PrintShaderLog(vShader);
			}

			glCompileShader(fShader);
			glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << std::endl;
				PrintShaderLog(fShader);
			}

			mProgramId = glCreateProgram();
			glAttachShader(mProgramId, vShader);
			glAttachShader(mProgramId, fShader);
			glLinkProgram(mProgramId);
			checkOpenGLError();
			glGetProgramiv(mProgramId, GL_LINK_STATUS, &success);
			if (!success)
			{
				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
				PrintProgramLog(mProgramId);
			}
			glDeleteShader(vShader);
			glDeleteShader(fShader);
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
	}

	void Use() const
	{
		glUseProgram(mProgramId);
	}

	GLuint GetProgramId() const 
	{
		return mProgramId;
	}

	void SetUniform(const std::string& uniformName, float value)
	{
		GLuint uniformLocation = glGetUniformLocation(mProgramId, uniformName.c_str());
		glProgramUniform1f(mProgramId, uniformLocation, value);
	}

	void SetModel(luna::Matrix4d mat)
	{
		GLuint model = glGetUniformLocation(mProgramId, "model");
		glUniformMatrix4fv(model, 1, GL_TRUE, mat.Data());
	}

	void SetView(luna::Matrix4d mat)
	{
		GLuint view = glGetUniformLocation(mProgramId, "view");
		glUniformMatrix4fv(view, 1, GL_FALSE, mat.Data());
	}

	void SetView(glm::mat4 mat)
	{
		GLuint view = glGetUniformLocation(mProgramId, "view");
		glUniformMatrix4fv(view, 1, GL_FALSE, glm::value_ptr(mat));
	}

	void SetProjection(luna::Matrix4d mat)
	{
		GLuint projection = glGetUniformLocation(mProgramId, "projection");
	    glUniformMatrix4fv(projection, 1, GL_FALSE, mat.Data());
	}

private:
	const std::string ReadShaderSource(const char* pathToShader)
	{
		std::ifstream shaderFile;
		shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		shaderFile.open(pathToShader);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		return shaderStream.str();
	}

	void PrintShaderLog(GLuint shader)
	{
		int len = 0;
		int chWrittn = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			char* log = new char[len];
			glGetShaderInfoLog(shader, len, &chWrittn, log);
			std::cout << "Shader Log: " << std::endl;
			std::cout << log << std::endl;
			delete[]log;
		}
	}

	void PrintProgramLog(GLuint program)
	{
		int len = 0;
		int chWrittn = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			char* log = new char[len];
			glGetProgramInfoLog(program, len, &chWrittn, log);
			std::cout << "Program Log: " << std::endl;
			std::cout << log << std::endl;
			delete[]log;
		}
	}

	bool checkOpenGLError()
	{
		bool foundError = false;
		int glErr = glGetError();
		while (glErr != GL_NO_ERROR)
		{
			std::cout << "glError: " << glErr << std::endl;
			foundError = true;
			glErr = glGetError();
		}
		return foundError;
	}

	GLuint mProgramId;
};

#endif