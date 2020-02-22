#version 430
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
void main(void)
{
	gl_Position = vec4(aPos,1.0);
}