#pragma once
#include<Box2D\Box2D.h>
#include<glm\glm.hpp>

namespace OverCover2D {
	class Box
	{
		b2Body* boxesBody;
		b2Fixture*fixture;
		b2BodyDef boxesDef;
		glm::vec2 m_dim;
	public:
		Box(void);
		b2Body* getBody() { return boxesBody; }
		b2Fixture*getFixture() { return fixture; }

		glm::vec2& getDimension() { return m_dim; }
		void init(b2World*, glm::vec2&, glm::vec2&);
		~Box(void);
	};
}

