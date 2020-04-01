#include "Game.hpp"
#include "Cube.hpp"

using namespace luna;

int main() 
{
	Game lunaRender{};
    // Read in scene;
    luna::Cube cube{ luna::Vector3d(0.0f,  0.0f,  0.0f) };
    luna::Cube cube1{ luna::Vector3d(2.0f,  1.0f,  0.0f) };
    cube1.GetTransform().Scale = {0.5f, 0.5f, 0.5f};
    Scene cubeDemo{};
    cubeDemo.AddObject(&cube);
    cubeDemo.AddObject(&cube1);
    lunaRender.AddScene(cubeDemo);
	lunaRender.Run();
}
