#version 400 core
in vec4 colorval;
out vec4 Color;

void main()
{
	Color=colorval;
	//Color=vec4(1.0f,0.5f,0.2f,1.0f);
}