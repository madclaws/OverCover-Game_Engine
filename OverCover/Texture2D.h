#pragma once
#include<GL\glew.h>

#include "ResourceManager.h"
class Texture2D
{
	GLuint Texture_ID;
	GLint Width,Height;
	GLint Wrapper_S,Wrapper_T;
	GLint Min_Filter,Mag_Filter;
	GLint Min_FIlter_Minmap;
	GLint Internal_Format;
	GLint Load_Format;
	unsigned char* image;
public:
	Texture2D(void);
	void Generate(const GLchar*);
	void Bind();
	~Texture2D(void);
};

