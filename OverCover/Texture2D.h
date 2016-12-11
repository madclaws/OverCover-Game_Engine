#pragma once
#include<GL\glew.h>
#include<stb-master\stb_image.h>
class Texture2D
{
	GLuint Texture_ID;
	GLint Width,Height;
	GLint Wrapper_S,Wrapper_T;
	GLint Min_Filter,Mag_Filter;
	GLint Min_FIlter_Minmap;
	GLint Internal_Format;
	GLint Load_Format;
public:
	Texture2D(void);
	void Generate();
	void Bind();
	~Texture2D(void);
};

