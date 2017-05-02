#include "RigidBody2D.h"

namespace OverCover2D {
	RigidBody2D::RigidBody2D(const GLchar* filename, b2World* phyworld, glm::vec2& position, glm::vec2& dimension, SpriteBatchRenderer& renderer,bool fixedrotation,glm::vec4 uvData)
	{
		m_dim = dimension;
		m_position = position;
		init(phyworld, position, dimension,fixedrotation);
		drawBody(renderer,filename,uvData);
	}

	void RigidBody2D::drawBody(OverCover2D::SpriteBatchRenderer& _Renderer,const GLchar* _filename,glm::vec4 uvdata)
	{
		Create(_filename, m_position.x, m_position.y, m_dim.x, m_dim.y,uvdata);
		_Renderer.CreateSpriteArray(this);
	}

	void RigidBody2D::init(b2World* _phyWorld, glm::vec2& _position, glm::vec2& _dimension,bool _fixedRot)
	{
		//create definiton for box
		m_dim = _dimension;
		boxesDef.type = b2_dynamicBody;
		boxesDef.position.Set(_position.x, _position.y);
		boxesDef.fixedRotation = _fixedRot;
		//creating rigidbody
		boxesBody = _phyWorld->CreateBody(&boxesDef);
		//creating shape and fixture
		b2PolygonShape boxesShape;
		boxesShape.SetAsBox(_dimension.x / 2, _dimension.y / 2);
		b2FixtureDef boxesFixture;
		boxesFixture.shape = &boxesShape;
		boxesFixture.density = 1.0f;
		boxesFixture.friction = 1.0f;
		fixture = boxesBody->CreateFixture(&boxesFixture);
	}
	void RigidBody2D::Update()
	{
		setPosition(boxesBody->GetPosition().x,boxesBody->GetPosition().y,getDimension().x,getDimension().y);
		
		Generate_VertexData();
	}
	RigidBody2D::~RigidBody2D(void)
	{
	}
}
