#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include "shader.hpp"

namespace luna
{
	class Drawable {
	public:
		virtual void Draw(Shader shader) = 0;
	};
}
#endif // !DRAWABLE_HPP
