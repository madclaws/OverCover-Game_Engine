#version 400 core
in vec4 colorval;
out vec4 Color;
in vec2 textcords;
uniform sampler2D broco;
uniform sampler2D container;
vec2 t_cords;
void main()
{
	//Color=colorval;
	t_cords=vec2(1-textcords.x,textcords.y);
	//Color=mix(texture(broco,t_cords),texture(container,t_cords),0.8);
	Color=texture(broco,t_cords);
	//Color=vec4(1.0f,0.5f,0.2f,1.0f);
}