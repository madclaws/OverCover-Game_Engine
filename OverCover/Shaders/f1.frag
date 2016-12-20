#version 400 core
in vec4 colorval;
out vec4 Color;
in vec2 textcords;
uniform sampler2D broco;
vec2 t_cords;
void main()
{
	//Color=colorval;
	t_cords=vec2(textcords.x,1.0-textcords.y);
	Color=texture(broco,t_cords);
	//Color=vec4(1.0f,0.5f,0.2f,1.0f);
}