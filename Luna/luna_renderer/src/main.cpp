#include "Game.hpp"
#include "Cube.hpp"

using namespace luna;

int main() 
{
	Game lunaRender{};
    // Read in scene;
    luna::Cube cube1{ luna::Vector3d(1.0f,  0.0f,  0.0f) };
    luna::Cube cube2{ luna::Vector3d(0.0f,  1.0f,  0.0f) };
    luna::Cube cube3{ luna::Vector3d(0.0f,  0.0f,  1.0f) };
    //cube.GetTransform().Rotation = {0.0f, 0.0f, 45.0f};
    cube1.SetColor({1.0f,0.0, 0.0f});
    cube2.SetColor({0.0f,  1.0f,  0.0f});
    cube3.SetColor({0.0f,  0.0f,  1.0f});
    luna::Cube lamp{ luna::Vector3d(1.0f,  01.5f,  1.5f) };
    lamp.GetTransform().Scale = {0.5f, 0.5f, 0.5f};
    lamp.UseAsLamp(true);
    Scene cubeDemo{};
    //cube.AddChild(&cube1);
    cubeDemo.AddObject(&cube1);
    cubeDemo.AddObject(&cube2);
    cubeDemo.AddObject(&cube3);
    cubeDemo.AddObject(&lamp);
    lunaRender.AddScene(cubeDemo);
	lunaRender.Run();
}
