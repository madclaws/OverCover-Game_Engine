#pragma once
#include<Box2D\Box2D.h>
#include"Sprite.h"
#include"SpriteBatchRenderer.h"
#include<glm\glm.hpp>

namespace OverCover2D {
	class RigidBody2D:OverCover2D::Sprite
	{
	protected:
		glm::vec2 m_position;
		b2Body* boxesBody;
		b2Fixture*fixture;
		b2BodyDef boxesDef;
		glm::vec2 m_dim;
	public:
		RigidBody2D(const GLchar*, b2World*, glm::vec2&, glm::vec2&,SpriteBatchRenderer&,bool,glm::vec4 uvData=glm::vec4(0.0f,0.0f,1.0f,1.0f));
		b2Body* getBody() { return boxesBody; }
		b2Fixture*getFixture() { return fixture; }
		void drawBody(OverCover2D::SpriteBatchRenderer&, const GLchar*, glm::vec4 uvData = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		glm::vec2& getDimension() { return m_dim; }
		void init(b2World*, glm::vec2&, glm::vec2&,bool);
		void Update();
		~RigidBody2D(void);
	};
}

