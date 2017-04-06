#include "Box.h"


Box::Box(void)
{

}

void Box::init(b2World* _phyWorld,glm::vec2& _position,glm::vec2& _dimension)
{
	//create definiton for box
	m_dim=_dimension;
	boxesDef.type=b2_dynamicBody;
	boxesDef.position.Set(_position.x,_position.y);
	//creating rigidbody
	boxesBody=_phyWorld->CreateBody(&boxesDef);
	//creating shape and fixture
	b2PolygonShape boxesShape;
	boxesShape.SetAsBox(_dimension.x/2,_dimension.y/2);
	b2FixtureDef boxesFixture;
	boxesFixture.shape=&boxesShape;
	boxesFixture.density=1.0f;
	boxesFixture.friction=0.3f;
	fixture=boxesBody->CreateFixture(&boxesFixture);
}
Box::~Box(void)
{
}
