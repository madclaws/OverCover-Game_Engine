#include "Sprite.h"


Sprite::Sprite(const GLchar* _id,const GLchar* univar):VAO(0),VBO(0),texture_loc('\0')
{
	//SetDim_State();
	//Generate_Buffer();
	ID=_id;
	_Texture=new Texture2D();
	DoWantNewTexture=false;
}

void Sprite::Create(const GLchar* loc)
{
	ResourceManager* R=ResourceManager::GetInstance();
texture_loc=loc;
Texture2D* texture_temp=R->GetTexture(texture_loc);
if(texture_temp==nullptr)
	DoWantNewTexture=true;
else
_Texture=texture_temp;
Init();
delete texture_temp;
}
void Sprite::Init()
{
	
	Generate_Buffer();
}
void Sprite::Generate_VertexData()
{
	//vertexdata[0].position.SetPosition(0.5f, 0.5f, 0.0f);
	vertexdata[0].position.SetPosition(300.0f, 300.0f, 0.0f);
	vertexdata[0].color.SetColor(0.0f,0.0f,1.0f,0.0f);
	vertexdata[0].uv.SetUV(1.0f,0.0f);
	//vertexdata[1].position.SetPosition(0.5f, -0.5f, 0.0f);
	vertexdata[1].position.SetPosition(300.0f, 500.0f, 0.0f);
	vertexdata[1].color.SetColor(0.0f,0.0f,0.0f,0.0f);
	vertexdata[1].uv.SetUV(1.0f,1.0f);
	//vertexdata[2].position.SetPosition(-0.5f, -0.5f, 0.0f);
	vertexdata[2].position.SetPosition(100.0f,500.0f, 0.0f);
	vertexdata[2].color.SetColor(0.0f,0.0f,0.0f,0.0f);
	vertexdata[2].uv.SetUV(0.0f,1.0f);
	//vertexdata[3].position.SetPosition(-0.5f, 0.5f, 0.0f );
	vertexdata[3].position.SetPosition(100.0f, 300.0f, 0.0f);
	vertexdata[3].color.SetColor(0.0f,0.0f,0.0f,0.0f);
	vertexdata[3].uv.SetUV(0.0f,0.0f);

}
void Sprite::Generate_Texture()
{if(DoWantNewTexture)
	_Texture->Generate(texture_loc);
}
void Sprite::Generate_ElementBuffer()
{
	Element_vertices[0]=0;
	Element_vertices[1]=1;
	Element_vertices[2]=3;
	Element_vertices[3]=1;
	Element_vertices[4]=2;
	Element_vertices[5]=3;
	
	//Element_vertices[]={0,1,3,1,2,3};
}
void Sprite::Generate_Buffer()
{
	Generate_VertexData();
	Generate_Texture();
	Generate_ElementBuffer();
	//sizeof(VAO);
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexdata),vertexdata,GL_STATIC_DRAW);
	glGenBuffers(1,&EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Element_vertices),Element_vertices,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,position));
	//(void*)offsetof(VertexData,position)
	glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,color));
	glVertexAttribPointer(2,2,GL_FLOAT,GL_TRUE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,uv));
	//glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,color));
	
	//glEnableVertexAttribArray(2);
	glBindVertexArray(0);
		glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
}
VertexData3* Sprite::GetVertexData()
{
	return vertexdata;
}
// This is The Draw Call
void Sprite::Draw()
{
	//glActiveTexture(GL_TEXTURE0);
	_Texture->Bind();
	//glBindVertexArray(VAO);
	
	//glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

	//glBindVertexArray(0);
	
}


Texture2D* Sprite::ret_texture()
{
	return _Texture;
}
const GLchar* Sprite::getID()
{
	return ID;
}
GLuint Sprite::GetTextureID()
{
	return _Texture->GetTextureId();
}
Sprite::~Sprite(void)
{
	delete _Texture;
	delete texture_loc;
}
