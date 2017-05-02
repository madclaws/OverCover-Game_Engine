#include "player.h"



player::player()
{
}

void player::init(const GLchar* _filename, b2World* _phyWorld, glm::vec2& _pos, glm::vec2& _dim, OverCover2D::SpriteBatchRenderer& _renderer, bool fixedrot,glm::vec4 uvdata)
{
	Body = new OverCover2D::RigidBody2D(_filename, _phyWorld, _pos, _dim, _renderer, fixedrot,uvdata);
}

void player::draw()
{
}

void player::update(OverCover2D::Window* _window)
{
	Body->Update();
	if (_window->winKeyPressed(262))
	{
	
		//getBody()->ApplyForceToCenter(b2Vec2(100.0, 0.0), true);
		Body->getBody()->ApplyForceToCenter(b2Vec2(10000000.0f, 0.0f), true);
		
	}
	 if (_window->winKeyPressed(263))
	{
		
		//getBody()->ApplyForceToCenter(b2Vec2(-100.0, 0.0), true);
		Body->getBody()->ApplyForceToCenter(b2Vec2(-10000000.0f, 0.0f), true);
		
	}
	 if (_window->winKeyPressed(265))
	 {
		 Body->getBody()->ApplyForceToCenter(b2Vec2(0.0f, -100000000000000.0f), true);
		 
	 }
	
	
}


player::~player()
{
}
