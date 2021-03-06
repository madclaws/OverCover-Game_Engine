#pragma once
#ifndef SPRITE_H
#define SPRITE_H
#include "Gameobject.h"
#include "Texture2D.h"
#include "VertexData3.h"
#include<cstddef>

namespace OverCover2D {
	class Sprite :public GameObject
	{
		// Vertex Buffer ID

		//Sprite's Texture Instance
		//Texture2D texture;
	protected:
		Texture2D* _Texture;
		const GLchar* texture_loc;

		//ResourceManager* resource;
		//static GLint texture_count;
		//Vertex Attributes
	
		VertexData3 vertexdata[4];
		VertexData spritePos[4];
		//Vertex Indices
		GLuint Element_vertices[6];
		GLfloat uv_x, uv_y, uv_w, uv_h;
		glm::vec4 colorData;
	public:
		//initialize Width,Height and State
		Sprite();

		Transform* transform;
		void Generate_VertexData();
		void Generate_Texture();
		void Generate_ElementBuffer();
		void Generate_Buffer();
		//Render Code
		GLboolean DoWantNewTexture;
		void Draw();
		void Create(const GLchar*, GLfloat, GLfloat, GLfloat, GLfloat, glm::vec4 uv_Data = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		void Init();
		~Sprite(void);
		Texture2D* ret_texture();
		GLuint GetTextureID();
		VertexData3* GetVertexData();
		const GLchar* getID();
		void setPosition(GLfloat, GLfloat, GLfloat, GLfloat);
		void setUV(glm::vec4);
	//	void setColor(glm::vec4);
		//void setColor(glm::vec4 _rgbVal = glm::vec4(0.0f, 0.0f.0.0f, 0.0f);
		glm::vec2 returnCurrentPos();
	};
}
#endif