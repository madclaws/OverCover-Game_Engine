#include "Sprite.h"


Sprite::Sprite(void):VAO(0),VBO(0),texture()
{
	SetDim_State();
	Generate_Buffer();
}
Sprite::Sprite(GLint _width,GLint _height,GameObject_State _state):VAO(0),VBO(0),texture()
{
	SetDim_State(_width,_height,_state);
	Generate_Buffer();
}

void Sprite::Generate_VertexData()
{
	vertexdata[0].position.SetPosition(-0.5f,0.0f,0.0f);
	vertexdata[0].color.SetColor(1.0f,0.0f,0.0f,1.0f);
	vertexdata[0].uv.SetUV(0.0,0.0);
	vertexdata[1].position.SetPosition(0.5f,0.0f,0.0f);
	vertexdata[1].color.SetColor(0.0f,1.0f,0.0f,1.0f);
	vertexdata[1].uv.SetUV(1.0,1.0);
	vertexdata[2].position.SetPosition(-0.5f,0.5f,0.0f);
	vertexdata[2].color.SetColor(0.0f,0.0f,1.0f,1.0f);
	vertexdata[2].uv.SetUV(0.0,1.0);
	vertexdata[3].position.SetPosition(0.5f,0.5f,0.0f);
	vertexdata[3].color.SetColor(0.0f,0.2f,0.0f,1.0f);
	vertexdata[0].uv.SetUV(1.0,1.0);

}
void Sprite::Generate_Texture()
{
	texture.Generate("location");
}
void Sprite::Generate_ElementBuffer()
{
	Element_vertices[0]=2;
	Element_vertices[1]=0;
	Element_vertices[0]=1;
	Element_vertices[0]=2;
	Element_vertices[0]=3;
	Element_vertices[0]=1;

}
void Sprite::Generate_Buffer()
{
	Generate_VertexData();
	Generate_Texture();
	Generate_ElementBuffer();
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexdata),vertexdata,GL_STATIC_DRAW);
	glGenBuffers(1,&EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Element_vertices),Element_vertices,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(vertexdata),(void*)offsetof(VertexData3,position));
	glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(vertexdata),(void*)offsetof(VertexData3,color));
	glVertexAttribPointer(2,2,GL_FLOAT,GL_TRUE,sizeof(vertexdata),(void*)offsetof(VertexData3,uv));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}
void Sprite::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	texture.Bind();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
	glBindVertexArray(0);
}

Sprite::~Sprite(void)
{
	
}
