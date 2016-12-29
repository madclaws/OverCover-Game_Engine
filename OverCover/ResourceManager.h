#pragma once
#include<GL\glew.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Shaders.h"
#include<stb-master\stb_image.h>
using namespace std;
//Resource Manager is Singleton class ie only one copy of its object will be in entire program
class ResourceManager
{
	//Constructor should be private preventing from creating instant from other classes
	ResourceManager(void);
	~ResourceManager(void);
	static GLint  texture_count;
	static GLenum Active_Textures[10];
public:
	//The fact we declare the variable as pointer because it is not pre-declared in anywhere
	//members variables should be static for singleton
	static ResourceManager* Instance;
	static ResourceManager*	 GetInstance();
	Shaders LoadShaders(const GLchar*,const GLchar*);
	unsigned char* LoadTexture(const GLchar*,GLint&,GLint&,GLint&);
	void clear(GLuint&,GLuint&);
	void clear(unsigned char*);
	void Set_Texture_Count();
	GLint Get_Texture_Count();
	static void  Set_ActiveTexture_Map();
	GLenum Get_ActiveTexture_Map(GLint);
	static void Start();
};

