#pragma once
#include<GL\glew.h>
#include<iostream>
using namespace std;
class Shaders
{GLuint ProgramID;
public:
	Shaders(const GLchar*,const GLchar*);
	void use();
	~Shaders(void);
};

