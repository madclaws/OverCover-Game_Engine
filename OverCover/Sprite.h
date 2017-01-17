#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include "gameobject.h"
#include "Texture2D.h"
#include "VertexData3.h"
#include<cstddef>
class Sprite :public GameObject
{
	// Vertex Buffer ID
	
	//Sprite's Texture Instance
	//Texture2D texture;
	Texture2D* _Texture;
	const GLchar* texture_loc;
	
	//ResourceManager* resource;
	//static GLint texture_count;
	//Vertex Attributes
	VertexData3 vertexdata[4];
	//Vertex Indices
	GLuint Element_vertices[6];
public:
	//initialize Width,Height and State
	Sprite(const GLchar*,const GLchar*);
	
	Transform* transform;
	void Generate_VertexData();
	void Generate_Texture();
	void Generate_ElementBuffer();
	void Generate_Buffer();
	//Render Code
	GLboolean DoWantNewTexture;
	void Draw();
	void Create(const GLchar*,GLfloat,GLfloat);
	void Init();
	~Sprite(void);
	Texture2D* ret_texture();
	GLuint GetTextureID();
	VertexData3* GetVertexData();
	const GLchar* getID();
};

#endif