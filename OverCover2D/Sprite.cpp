#include "Sprite.h"

namespace OverCover2D {
	Sprite::Sprite() :texture_loc('\0')
	{

		//ID = _id;
		_Texture = new Texture2D();
		DoWantNewTexture = false;
		//transform=new Transform();
	}

	void Sprite::Create(const GLchar* loc, GLfloat x_pos, GLfloat y_pos, GLfloat _height, GLfloat _width, glm::vec4 uv_Data)
	{
		ResourceManager* R = ResourceManager::GetInstance();
		texture_loc = loc;
		Texture2D* texture_temp = R->GetTexture(texture_loc);
		if (texture_temp == nullptr)
			DoWantNewTexture = true;
		else
			_Texture = texture_temp;
		//transform->SetPosition(_x,_y,0.0f);
		setPosition(x_pos, y_pos, _height, _width);
		setUV(uv_Data);
		Init();
		//delete texture_temp;

	}
	void Sprite::setPosition(GLfloat _x, GLfloat _y, GLfloat _h, GLfloat _w)
	{
		spritePos[0].position.SetPosition(_x, _y, 0.0f);
		spritePos[1].position.SetPosition(_x, _y + _h, 0.0f);
		spritePos[2].position.SetPosition(_x + _w, _y + _h, 0.0f);
		spritePos[3].position.SetPosition(_x + _w, _y, 0.0f);

	}

	void Sprite::setUV(glm::vec4 uv_data)
	{
		uv_x = uv_data.x;
		uv_y = uv_data.y;
		uv_w = uv_data.w;
		uv_h = uv_data.z;
	}

	void Sprite::Init()
	{

		Generate_Buffer();
	}
	void Sprite::Generate_VertexData()
	{
		//VertexData* curpos=transform->GetVertexPointer();

		//vertexdata[0].position.SetPosition(0.5f, 0.5f, 0.0f);
		vertexdata[0].position.SetPosition(spritePos[0].position.x, spritePos[0].position.y, 0.0f);
		//vertexdata[0].position.SetPosition(curpos[0]._x,curpos[0]._y, 0.0f);
		vertexdata[0].color.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
		vertexdata[0].uv.SetUV(uv_x+uv_w, uv_y);
		//vertexdata[1].position.SetPosition(curpos[1]._x,curpos[1]._y, 0.0f);
		vertexdata[1].position.SetPosition(spritePos[1].position.x, spritePos[1].position.y, 0.0f);
		//vertexdata[1].position.SetPosition(0.5f, 0.0f, 0.0f);
		vertexdata[1].color.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
		vertexdata[1].uv.SetUV(uv_x + uv_w, uv_y+uv_h);
		
		vertexdata[2].position.SetPosition(spritePos[2].position.x, spritePos[2].position.y, 0.0f);
		vertexdata[2].color.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
		vertexdata[2].uv.SetUV(uv_x, uv_y + uv_h);
		//vertexdata[3].position.SetPosition(curpos[3]._x,curpos[3]._y, 0.0f );
		//vertexdata[3].position.SetPosition(1.0f, 0.5f, 0.0f);
		vertexdata[3].position.SetPosition(spritePos[3].position.x, spritePos[3].position.y, 0.0f);
		vertexdata[3].color.SetColor(0.0f, 0.0f, 0.0f, 1.0f);
		vertexdata[3].uv.SetUV(uv_x,uv_y);

	}
	void Sprite::Generate_Texture()
	{
		if (DoWantNewTexture)
			_Texture->Generate(texture_loc);
	}
	void Sprite::Generate_ElementBuffer()
	{
		Element_vertices[0] = 0;
		Element_vertices[1] = 1;
		Element_vertices[2] = 3;
		Element_vertices[3] = 1;
		Element_vertices[4] = 2;
		Element_vertices[5] = 3;

		//Element_vertices[]={0,1,3,1,2,3};
	}
	void Sprite::Generate_Buffer()
	{
		Generate_VertexData();
		Generate_Texture();
	}
	VertexData3* Sprite::GetVertexData()
	{
		return vertexdata;
	}
	// This is The Draw Call
	void Sprite::Draw()
	{


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
	glm::vec2 Sprite::returnCurrentPos()
	{
		glm::vec2 temp_pos;
		temp_pos.x = spritePos[0].position.x;
		temp_pos.y = spritePos[0].position.y;
		return temp_pos;
	}
	Sprite::~Sprite(void)
	{
		delete _Texture;
		delete texture_loc;
	}
}
