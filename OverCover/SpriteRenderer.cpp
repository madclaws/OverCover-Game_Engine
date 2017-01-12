#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(Shaders _shader)
{
	_resource=ResourceManager::GetInstance();
	_Shader=_shader;
}


SpriteRenderer::~SpriteRenderer(void)
{
}
void SpriteRenderer::DrawSprite(Sprite* _sprite,GLint num ,glm::vec3 _position,GLfloat _angle,glm::vec3 _scale)
{
	//_Shader.use();
	/*glm::mat4 model;
	//model=glm::translate(model,glm::vec3(-0.5f,0.5f,0.0f));
	model=glm::translate(model,_position);
	//model=glm::translate(model,glm::vec3(0.5f*_scale.x,0.5f*_scale.y,0.0f));
	model=glm::rotate(model,_angle,glm::vec3(0.0f,0.0f,1.0f));
	//model=glm::translate(model,glm::vec3(-0.5f*_scale.x,-0.5f*_scale.y,0.0f));
	model=glm::scale(model,_scale);
	glActiveTexture(_resource->Get_ActiveTexture_Map(num));
	//cout<<_resource->Get_Texture_Count();
	
	//_resource->Set_Texture_Count(); 

	_Shader.SetintU(_sprite->getID(),num,0);
		_Shader.SetMatrix4U("model",model,0);
		_sprite->Draw();
	
	
	//cout<<_sprite.getID()<<" Rendered\n";
	//system("pause"); */
}

