#pragma once
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include<GL\glew.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Shaders.h"
#include<map>
#include<stb-master\stb_image.h>
namespace OverCover2D {
	//forward declaration inorder to avoid circular dependency between ResourceManager and Texture2D
	class Texture2D;

	//#include"Texture2D.h"

	using namespace std;
	//Resource Manager is Singleton class ie only one copy of its object will be in entire program
	class ResourceManager
	{
		//Constructor should be private preventing from creating instant from other classes
		ResourceManager(void);
		~ResourceManager(void);
		static GLint  texture_count;
		static GLenum Active_Textures[10];
		//static std::map<const GLchar*,ImageData> TextureMap;
		static std::map<const GLchar*, Texture2D*> TextObjMap;
	public:
		//The fact we declare the variable as pointer because it is not pre-declared in anywhere
		//members variables should be static for singleton
		static ResourceManager* Instance;
		static ResourceManager*	 GetInstance();
		Shaders LoadShaders(const GLchar*, const GLchar*);
		unsigned char* LoadTexture(const GLchar*, GLint&, GLint&, GLint&);
		//Caching Texture
		unsigned char* GetTextureData(const GLchar*, GLint&, GLint&, GLint&);
		Texture2D* GetTexture(const GLchar*);
		//Setting TextureObj and location;
		void SetTextureMap(Texture2D*, const GLchar*);
		void clear(GLuint&, GLuint&);
		void clear(unsigned char*);
		void Set_Texture_Count();
		GLint Get_Texture_Count();
		static void  Set_ActiveTexture_Map();
		GLenum Get_ActiveTexture_Map(GLint);
		static void Start();
	};
}
#endif
