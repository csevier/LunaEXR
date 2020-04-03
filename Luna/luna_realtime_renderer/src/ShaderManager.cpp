#include "ShaderManager.hpp"


namespace luna
{
    void ShaderManager::AddShader(const std::string& name, Shader& shader)
    {
        mShaders.insert(std::make_pair(name, shader));
    }

    Shader* ShaderManager::GetShader(const std::string& name)
    {
        //const Shader& shader = mShaders[name];
        std::unordered_map<std::string, Shader>::iterator iter = mShaders.find(name);
        if(iter != mShaders.end())
        {
            return &iter->second;
        }
        return nullptr;
    }

    void ShaderManager::SetView(const Camera& camera)
    {
        for(auto& pair : mShaders)
        {
            pair.second.SetView(camera.GetView());
            pair.second.SetUniform("viewPos", camera.GetPosition());
        }
    }

    void ShaderManager::SetProjection(const Matrix4d& projection)
    {
        for(auto& pair : mShaders)
        {
            pair.second.SetProjection(projection);
        }
    }

    std::unordered_map<std::string, Shader> ShaderManager::mShaders;
}
