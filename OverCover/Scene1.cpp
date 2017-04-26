#include "Scene1.h"



Scene1::Scene1()
{
	//SWidth = _width;
	//SHeight = _height;
	cameraMgr = new OverCover2D::Camera2D(1366,768);
	SWidth = 1366;
	SHeight = 768;
}

int Scene1::getNextSceneIndex()
{
	return 0;
}

int Scene1::getPrevSceneIndex()
{
	return 0;
}

void Scene1::build()
{
	resourceMgr = OverCover2D::ResourceManager::GetInstance();
	shaderMgr = resourceMgr->LoadShaders("Shaders/v1.vert", "Shaders/f1.frag");
	inputMgr = OverCover2D::InputManager::GetInstance();
	phyInit();
	bulletbox = new BulletBox(glm::vec2(300, 0), 1, 10, rendererMgr);
	//sprite = new OverCover2D::Sprite();
	//sprite->Create("textures/box1.jpg", 300, 200, 100, 100);
	//rendererMgr.CreateSpriteArray(sprite);
	rendererMgr.Init();
	std::cout << "Scene Build Successfully..........................................";
	
}

void Scene1::destroy()
{
}

void Scene1::enter()
{
}

void Scene1::exit()
{
}

void Scene1::render()
{
	
	//std::cout << "Rendering................\n";
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	shaderMgr.use();
	rendererMgr.RenderScene();

}

void Scene1::update()
{
	
//	std::cout << "Updating.............\n";
	EventHandler();
	phy_world->Step(1.0f / 60.0f, 6, 2);
	bulletbox->update(newbox.getBody()->GetPosition().x,newbox.getBody()->GetPosition().y);
	glm::mat4 projection = glm::ortho(0.0f + cameraMgr->GetZoomFactor()*10.0f, (GLfloat)SWidth - cameraMgr->GetZoomFactor()*10.0f, (GLfloat)SHeight - cameraMgr->GetZoomFactor()*10.0f, 0.0f + cameraMgr->GetZoomFactor()*10.0f, -1.0f, 1.0f);

	shaderMgr.SetMatrix4U("projection", projection, 0);
	cameraMgr->View = cameraMgr->LookAt();
	shaderMgr.SetMatrix4U("view", cameraMgr->View, 0);
}

void Scene1::EventHandler()
{
	
	
	if (parent->window->winKeyPressed(87))
		cameraMgr->MoveUp();
	if (parent->window->winKeyPressed(83))
		cameraMgr->MoveDown();
	if (parent->window->winKeyPressed(65))
		cameraMgr->MoveLeft();
	if (parent->window->winKeyPressed(68))
		cameraMgr->MoveRight();
	if (parent->window->winKeyPressed(0))
	{
		glm::vec2 coords;
		coords = parent->window->returnScreenCoords();
		coords = cameraMgr->ScreenToWorld(coords);
		cout << "\n" << coords.x << "\t" << coords.y << "\n";
	}
}
void Scene1::phyInit()
{
	b2Vec2 gravity(0.0f, 9.81f);
	phy_world = std::make_unique<b2World>(gravity);
	//ground
	b2BodyDef groundDef;
	groundDef.position.Set(300.0f, 700.0f);
	b2Body* ground;
	ground = phy_world->CreateBody(&groundDef);

	b2PolygonShape groundshape;
	groundshape.SetAsBox(500.0f, 50.0f);

	ground->CreateFixture(&groundshape, 0.0f);
	newbox.init(phy_world.get(), glm::vec2(300.0f, 200.0f), glm::vec2(100.0f, 100.0f));
	
}

	
Scene1::~Scene1()
{
}


