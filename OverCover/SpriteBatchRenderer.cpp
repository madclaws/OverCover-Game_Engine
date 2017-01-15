#include "SpriteBatchRenderer.h"

GLboolean SpriteBatchRenderer::SortMemory;
GLboolean SpriteBatchRenderer::GenerateMemory;
SpriteBatchRenderer::SpriteBatchRenderer(void):VAO(0),VBO(0),EBO(0)
{
		index_0=0,index_1=1,index_2=3,index_3=1,index_4=2,index_5=3;
		SortMemory=GL_TRUE;
		GenerateMemory=GL_TRUE;
}

void SpriteBatchRenderer::Init()
{
	CreateVertexArrayObj();
}
void SpriteBatchRenderer::CreateVertexArrayObj()
{

	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	glGenBuffers(1,&EBO);
	
	glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER,VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	//glBindBuffer(GL_ARRAY_BUFFER,VBO);
	//glBufferData(GL_ARRAY_BUFFER,sizeof(vertexdata),vertexdata,GL_STATIC_DRAW);
	
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Element_vertices),Element_vertices,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,position));
	//(void*)offsetof(VertexData,position)
	glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,color));
	glVertexAttribPointer(2,2,GL_FLOAT,GL_TRUE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,uv));
	//glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,color));
	glBindVertexArray(0);
}
void SpriteBatchRenderer::CreateSpriteArray(Sprite* _sprite)
{
	SpriteArray.push_back(_sprite);
}
GLboolean SpriteBatchRenderer:: sortfunc(Sprite*a,Sprite*b)
{if(SortMemory)
	return(a->GetTextureID()>b->GetTextureID());
		
}
void SpriteBatchRenderer::SortSprites()
{
	std::stable_sort(SpriteArray.begin(),SpriteArray.end(),sortfunc);
}
void SpriteBatchRenderer::GenerateBatches()
{
	if(GenerateMemory){
	if(SpriteArray.size()==0)
		return;
	
	GLint count_vert=0;
	GLint count_sprite=0;
	GLint count_elements=0;
	GLint offset=0;
	
	VertexData3* vertex_ptr=SpriteArray[count_sprite]->GetVertexData();
	vertices.resize(SpriteArray.size()*4); 
	//vertices.size();
	ElementIndices.resize(SpriteArray.size()*6);
	Batches.emplace_back(offset,6,SpriteArray[count_sprite]->GetTextureID());
//	vertices[count_vert]=SpriteArray[0]->GetVertexData();
	vertices[count_vert++]=vertex_ptr[0];
	vertices[count_vert++]=vertex_ptr[1];
	vertices[count_vert++]=vertex_ptr[2];
	vertices[count_vert++]=vertex_ptr[3];
	ElementIndices[count_elements++]=index_0;
	ElementIndices[count_elements++]=index_1;
	ElementIndices[count_elements++]=index_2;
	ElementIndices[count_elements++]=index_3;
	ElementIndices[count_elements++]=index_4;
	ElementIndices[count_elements++]=index_5;
	offset=count_elements;
	//cout<<vertices.size()<<endl;
	for(int count_sprite=1;count_sprite<SpriteArray.size();count_sprite++)
	{
		vertex_ptr=SpriteArray[count_sprite]->GetVertexData();
		if(SpriteArray[count_sprite]->GetTextureID()!=SpriteArray[count_sprite-1]->GetTextureID() &&  SpriteArray.size()>1)
		{
			Batches.emplace_back(offset,6,SpriteArray[count_sprite]->GetTextureID());
		}
		else
		{
			Batches.back().numofvert+=6;
		}

		ElementIndices[count_elements++]=index_0+count_vert;
	ElementIndices[count_elements++]=index_1+count_vert;
	ElementIndices[count_elements++]=index_2+count_vert;
	ElementIndices[count_elements++]=index_3+count_vert;
	ElementIndices[count_elements++]=index_4+count_vert;
	ElementIndices[count_elements++]=index_5+count_vert;
		vertices[count_vert++]=vertex_ptr[0];
	vertices[count_vert++]=vertex_ptr[1];
	vertices[count_vert++]=vertex_ptr[2];
	vertices[count_vert++]=vertex_ptr[3];
	
	offset=count_elements;
	}
	GenerateMemory=GL_FALSE;
	
//	cout<<sizeof(ElementIndices)<<endl;
//	cout<<ElementIndices.size()*sizeof(GLint);
	glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER,VBO);
	//Orphaning VBO
	glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(VertexData3),vertices.data(),GL_DYNAMIC_DRAW);
	//glBufferSubData(GL_ARRAY_BUFFER,0,vertices.size()*sizeof(VertexData3),vertices.data());
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,ElementIndices.size()*sizeof(GLint),ElementIndices.data(),GL_DYNAMIC_DRAW);
	//glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0,ElementIndices.size()*sizeof(GLint),ElementIndices.data());
	
	
	
	//glBindBuffer(GL_ARRAY_BUFFER,VBO);
	//glBufferData(GL_ARRAY_BUFFER,sizeof(vertexdata),vertexdata,GL_STATIC_DRAW);
	
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Element_vertices),Element_vertices,GL_STATIC_DRAW);
	/*glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,position));
	//(void*)offsetof(VertexData,position)
	glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,color));
	glVertexAttribPointer(2,2,GL_FLOAT,GL_TRUE,sizeof(VertexData3),(GLvoid*)offsetof(VertexData3,uv));
	*/
	glBindVertexArray(0);
	glActiveTexture(GL_TEXTURE0);
	}
	//glBindBuffer(GL_ARRAY_BUFFER,0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
void SpriteBatchRenderer::End()
{
	SortSprites();
	GenerateBatches();
}
void SpriteBatchRenderer::Begin(SortType _sortype)
{
	//vertices.clear();
	//ElementIndices.clear();
}
void SpriteBatchRenderer::Renderer()
{static int draw_call=0;
		
		glBindVertexArray(VAO);
	for(GLint i=0;i<Batches.size();i++)
	{
		glBindTexture(GL_TEXTURE_2D,Batches[i].textureid);
		
		glDrawElements(GL_TRIANGLES,Batches[i].numofvert,GL_UNSIGNED_INT,(void*)Batches[i].offset);
		cout<<"DRAW CALL: "<<++draw_call<<endl;
		//glBindTexture(GL_TEXTURE_2D,0);
	}
	draw_call=0;
	glBindVertexArray(0);
}
SpriteBatchRenderer::~SpriteBatchRenderer(void)
{
}
