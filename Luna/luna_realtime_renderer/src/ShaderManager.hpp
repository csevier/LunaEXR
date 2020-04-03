#ifndef SHADERMANAGER_HPP
#define SHADERMANAGER_HPP

#include "Shader.hpp"
#include "Camera.hpp"
#include "matrix4d.hpp"
#include <unordered_map>

namespace luna
{
    class ShaderManager
    {
        public:
             static void AddShader(const std::string& name, Shader& shader);
             static Shader* GetShader(const std::string& name);
             static void SetView(const Camera& camera);
             static void SetProjection(const Matrix4d& projection);
        private:
            static std::unordered_map<std::string, Shader> mShaders;
    };
}
#endif
