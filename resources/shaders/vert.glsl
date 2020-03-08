#version 430
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec4 vcolor;

void main(void)
{
	gl_Position = projection * view * model * vec4(aPos,1.0);
	if(gl_VertexID < 6)
	{
		vcolor = vec4(1.0, 0.0, 0.0, 1.0);
	}
	else if( gl_VertexID >=6 && gl_VertexID < 12)
	{
		vcolor = vec4(0.0, 1.0, 0.0, 1.0);
	}
	else if(gl_VertexID >=12 && gl_VertexID < 18)
	{
		vcolor = vec4( 0.0, 0.0, 1.0, 1.0);
	}
	else if(gl_VertexID >=18 && gl_VertexID < 24)
	{
		vcolor = vec4( 1.0, 1.0, 0.0, 1.0);
	}
	else if(gl_VertexID >=24 && gl_VertexID < 30)
	{
		vcolor = vec4( 1.0, 0.0, 1.0, 1.0);
	}
	else if(gl_VertexID >=30 && gl_VertexID < 36)
	{
		vcolor = vec4( 0.0, 1.0, 1.0, 1.0);
	}
	else
	{
		vcolor = vec4(1.0,1.0, 1.0, 1.0);
	}
}