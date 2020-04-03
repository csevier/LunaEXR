#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include "Shader.hpp"

namespace luna
{
	class Drawable {
	public:
        virtual void Draw() = 0;
	};
}
#endif // !DRAWABLE_HPP
