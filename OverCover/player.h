#pragma once
#include<OverCover2D\RigidBody2D.h>
#include<OverCover2D\SpriteBatchRenderer.h>
#include<OverCover2D\Window.h>
class player
{
protected:
	OverCover2D::RigidBody2D* Body;

public:
	player();
	void init(const GLchar*, b2World*, glm::vec2&, glm::vec2&, OverCover2D::SpriteBatchRenderer&,bool,glm::vec4 uvdata=glm::vec4(0.0f,0.0f,1.0f,1.0f));
	void draw();
	void update(OverCover2D::Window*);
	b2Body* getBody() { return Body->getBody(); }
	~player();
};

