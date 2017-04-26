#include "BulletBox.h"



BulletBox::BulletBox(glm::vec2 _direction,GLfloat _speed,GLint _lifeTime, OverCover2D::SpriteBatchRenderer& _Renderer)
{
	direction = _direction;
	speed = _speed;
	lifeTime = _lifeTime;
	Create("textures/Mario2.png", 300, 200, 100, 100);
	drawBullet(_Renderer);
}
void BulletBox::drawBullet(OverCover2D::SpriteBatchRenderer& _Renderer)
{
	_Renderer.CreateSpriteArray(this);
	//Generate_VertexData();
}
void BulletBox::update(GLfloat _w,GLfloat _h)
{
	GLfloat w, h;
		//position = returnCurrentPos();
		//direction = glm::normalize(direction);
		//position += direction*speed;
		//setPosition(position.x, position.y, 100, 100);
	setPosition(_w,_h, 100, 100);
		Generate_VertexData();

}
BulletBox::~BulletBox()
{
}
