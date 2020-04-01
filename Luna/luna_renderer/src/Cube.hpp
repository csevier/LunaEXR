#ifndef CUBE_HPP
#define CUBE_HPP

#include "GameObject.hpp"
#include "vector3d.hpp"
#include "Mesh.hpp"
#include "Drawable.hpp"
#include "TimeManger.hpp"

namespace luna 
{
	class Cube : public GameObject
	{
        public:
            Cube(const Vector3d& transform);
            void Update(const TimeManager& tm) override;
            void Draw(Shader shader) override;
            void SetColor(const Vector3d& color);
            void SetLight(const Vector3d& light);
            void UseAsLamp(bool isLightSource);

        private:
            Mesh mMesh;
            Vector3d objectColor{1.0f, 1.0f, 1.0f}; //white
            Vector3d lightColor{1.0f, 1.0f, 1.0f}; //white
            bool isLightSource = false;
	};
}

#endif
