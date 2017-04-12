#pragma once
#include<OverCover2D\Sprite.h>
#include<glm\glm.hpp>
#include<OverCover2D\SpriteBatchRenderer.h>
class BulletBox:OverCover2D::Sprite
{
protected:
	glm::vec2 direction;
	GLfloat speed;
	GLint lifeTime;
	glm::vec2 position;
	
public:
	BulletBox(glm::vec2,GLfloat,GLint,OverCover2D::SpriteBatchRenderer&);
	void drawBullet(OverCover2D::SpriteBatchRenderer&);
	void update();
	~BulletBox(); 
};
