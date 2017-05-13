#version 400 core

layout (location=0) in vec3 position;
layout (location=1) in vec4 colorvert;
layout (location=2) in vec2 textcoords;

out vec4 colorval;
out vec2 textcords;
uniform float col;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;
void main()
{
	gl_Position=projection*view*vec4(position.x,position.y,position.z,1.0f);
	//colorval=vec4(position.x*col,position.y*(1-col),position.z,1.0f);
	colorval=colorvert;
	textcords=textcoords;
		
}