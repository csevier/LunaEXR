#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "matrix4d.hpp"
#include <GL/glew.h>
namespace luna
{
    class Shader
    {

        public:
            Shader(const char* vertexPath, const char* fragmentPath);
            void Use() const;
            GLuint GetProgramId() const;
            void SetUniform(const std::string& uniformName, float value);
            void SetModel(luna::Matrix4d mat);
            void SetView(luna::Matrix4d mat);
            void SetProjection(luna::Matrix4d mat);

        private:
            const std::string ReadShaderSource(const char* pathToShader);
            void PrintShaderLog(GLuint shader);
            void PrintProgramLog(GLuint program);
            bool checkOpenGLError();
            GLuint mProgramId;
    };
}


#endif
