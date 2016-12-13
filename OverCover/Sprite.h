#pragma once
#include "gameobject.h"
#include "Texture2D.h"
#include "VertexData3.h"
#include<cstddef>
class Sprite :public GameObject
{
	// Vertex Buffer ID
	GLuint VBO;
	//Vertex Array ID
	GLuint VAO;
	//Element Buffer ID
	GLuint EBO;
	//Sprite's Texture Instance
	Texture2D texture;
	//Vertex Attributes
	VertexData3 vertexdata[4];
	//Vertex Indices
	GLfloat Element_vertices[6];
public:
	//initialize Width,Height and State
	Sprite(void);
	Sprite(GLint,GLint,GameObject_State);
	void Generate_VertexData();
	void Generate_Texture();
	void Generate_ElementBuffer();
	void Generate_Buffer();
	//Render Code
	void Draw();
	~Sprite(void);
};

