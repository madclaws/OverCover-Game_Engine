#pragma once
#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include "Shaders.h"
#include "Sprite.h"
#include "ResourceManager.h"
class SpriteRenderer
{
	Shaders _Shader;
	ResourceManager* _resource;
public:
	SpriteRenderer(Shaders);
	~SpriteRenderer(void);
	
	void DrawSprite(Sprite*,GLint ,glm::vec3 Position=glm::vec3(0,0,0),GLfloat Rotation=0.0f,glm::vec3 Scale=glm::vec3(10,10,0));
	
};
#endif
