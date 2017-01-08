#pragma once
#include<GL\glew.h>
struct ImageData
{
	unsigned char* FILELOC;
	GLint WIDTH;
	GLint HEIGHT;
	void FillData(unsigned char*,GLint,GLint);
	
};

