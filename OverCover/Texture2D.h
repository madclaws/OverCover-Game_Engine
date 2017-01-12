#pragma once
#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include<GL\glew.h>
//class Texture2D;
#include "ResourceManager.h"
//class ResourceManager;
class Texture2D
{
	GLuint Texture_ID;
	GLint Width,Height;
	GLint Wrapper_S,Wrapper_T;
	GLint Min_Filter,Mag_Filter;
	GLint Min_FIlter_Minmap;
	GLint Internal_Format;
	GLint Load_Format;
	//const GLchar* uniform_var_string;
	unsigned char* image;
public:
	Texture2D();
	void Generate(const GLchar*);
	void Bind();
	~Texture2D(void);
	//const GLchar* uni_var_str();
	GLuint GetTextureId();
};
#endif
