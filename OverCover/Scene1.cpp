
	#include "Scene1.h"



	Scene1::Scene1()
{
	//SWidth = _width;
	//SHeight = _height;
	cameraMgr = new OverCover2D::Camera2D(1366, 768);
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
	sprite = new OverCover2D::Sprite();
	leftground.push_back(1);
	leftground.push_back(2);
	leftground.push_back(3);

	/*for (int i = 0; i < 80; i = i + 3)
	{
		bodies.push_back(new OverCover2D::RigidBody2D("textures/box2.jpg", phy_world.get(), glm::vec2(i, i), glm::vec2(50, 50), rendererMgr, false));
	}*/
	//m_player.init("textures/Mario2.png", phy_world.get(), glm::vec2(200, 10), glm::vec2(50, 50), rendererMgr, false);

	//Drawing Left ground***************************************************************************************
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(0, 700), glm::vec2(100, 100), rendererMgr, false,false));
	
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(100, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(200, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(0, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(100, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(200, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(300, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(300, 600), glm::vec2(100, 100), rendererMgr, false, false));
	
	//Drawing Right ground
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(900, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1000, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1100, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1200, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1300, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(900, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1000, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1100, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1200, 600), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1300, 600), glm::vec2(100, 100), rendererMgr, false, false));
	//////////////// River Drawing/////////////////////////////////////////////////////////////////////////////////
	bodies.push_back(new OverCover2D::RigidBody2D("textures/water.png", phy_world.get(), glm::vec2(400, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/water.png", phy_world.get(), glm::vec2(500, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/water.png", phy_world.get(), glm::vec2(600, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/water.png", phy_world.get(), glm::vec2(700, 700), glm::vec2(100, 100), rendererMgr, false, false));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/water.png", phy_world.get(), glm::vec2(800, 700), glm::vec2(100, 100), rendererMgr, false, false));
	//***********************GOAT**********************************
	bodies.push_back(new OverCover2D::RigidBody2D("textures/goat.png", phy_world.get(), glm::vec2(200, 500), glm::vec2(100, 100), rendererMgr, false,true));
	m_avatars.push_back(new Avatars(bodies[23], 1));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/cabbage1.png", phy_world.get(), glm::vec2(300, 500), glm::vec2(100, 100), rendererMgr, false,true));
	m_avatars.push_back(new Avatars(bodies[24], 2));
	bodies.push_back(new OverCover2D::RigidBody2D("textures/wolfy1.png", phy_world.get(), glm::vec2(100, 500), glm::vec2(100, 100), rendererMgr, false,true));
	m_avatars.push_back(new Avatars(bodies[25], 3));
	m_player.init("textures/boat1.png", phy_world.get(), glm::vec2(400, 600), glm::vec2(100, 100), rendererMgr, false);
	//bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1000, 600), glm::vec2(100, 100), rendererMgr, false, false));
	//bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1100, 600), glm::vec2(100, 100), rendererMgr, false, false));
//	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1200, 600), glm::vec2(100, 100), rendererMgr, false, false));
//	bodies.push_back(new OverCover2D::RigidBody2D("textures/gnd1.png", phy_world.get(), glm::vec2(1300, 600), glm::vec2(100, 100), rendererMgr, false, false));
	

	sprite->Create("textures/f.png", 0.0f, 0.0f, 768, 1366);
	rendererMgr.CreateSpriteArray(sprite);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shaderMgr.use();
	rendererMgr.RenderScene();

}

void Scene1::update()
{

	//	std::cout << "Updating.............\n";
	EventHandler();
	phy_world->Step(1.0f / 60.0f, 6, 2);
	//newbox->Update();
	for (int i = 0; i < bodies.size(); i++)
	{
		bodies[i]->Update();
	}
	m_player.update(parent->window);

	glm::mat4 projection = glm::ortho(0.0f + cameraMgr->GetZoomFactor()*10.0f, (GLfloat)SWidth - cameraMgr->GetZoomFactor()*10.0f, (GLfloat)SHeight - cameraMgr->GetZoomFactor()*10.0f, 0.0f + cameraMgr->GetZoomFactor()*10.0f, -1.0f, 1.0f);

	shaderMgr.SetMatrix4U("projection", projection, 0);
	cameraMgr->View = cameraMgr->LookAt();
	shaderMgr.SetMatrix4U("view", cameraMgr->View, 0);
}

void Scene1::checkGame()
{
	
	
	auto it_left_1 = std::find(leftground.begin(), leftground.end(), 1);
	auto it_left_2= std::find(leftground.begin(), leftground.end(), 2);
	auto it_left_3 = std::find(leftground.begin(), leftground.end(), 3);
	auto it_right_1 = std::find(rightground.begin(), rightground.end(), 1);
	auto it_right_2 = std::find(rightground.begin(), rightground.end(), 2);
	auto it_right_3 = std::find(rightground.begin(), rightground.end(), 3);

		if (it_left_1 != leftground.end() && it_left_2 != leftground.end() && leftground.size() < 3)
			std::cout << "YOU LOSE";
		else if (it_left_1 != leftground.end() && it_left_3 != leftground.end() && leftground.size() < 3)
			std::cout << "YOU LOSE";
		else if (it_right_1 != rightground.end() && it_right_2 != rightground.end() && rightground.size() < 3)
			std::cout << "YOU LOSE";
		else if (it_right_1 != rightground.end() && it_right_3 != rightground.end() && rightground.size() < 3)
			std::cout << "YOU LOSE";
		else if (leftground.size() == 0 && rightground.size() == 3)
			std::cout << "You WIN";
	/*	if (std::find(leftground.begin(), leftground.end(), 1) != leftground.end() && leftground.size()<3)
			if (std::find(leftground.begin(), leftground.end(), 2) != leftground.end())
				std::cout << "you lose";

		else if (std::find(leftground.begin(), leftground.end(), 1) != leftground.end() && leftground.size()<3 && )
			if (std::find(leftground.begin(), leftground.end(), 3) != leftground.end())
				std::cout << "you lose";
	
	
		else if (std::find(rightground.begin(), rightground.end(), 1) != rightground.end())
			if (std::find(rightground.begin(), rightground.end(), 2) != rightground.end())
				std::cout << "you lose";

		else if (std::find(rightground.begin(), rightground.end(), 1) != rightground.end() && rightground.size() != 3)
			if (std::find(rightground.begin(), rightground.end(), 3) != rightground.end() && rightground.size() != 3)
				std::cout << "you lose";
	*/

}

bool Scene1::checkBoatRight()
{
	if(m_player.getBody()->GetPosition().x>450 && m_player.getBody()->GetPosition().x < 500)
	return true;
return false;

}

bool Scene1::checkBoatLeft()
{
	if (m_player.getBody()->GetPosition().x<850 && m_player.getBody()->GetPosition().x > 700)
		return true;
	return false;
	
}

void Scene1::EventHandler()
{
	
	//Avatars* t_avatar=new Avatars();
	if (parent->window->winKeyPressed(87))
		cameraMgr->MoveUp();
	if (parent->window->winKeyPressed(83))
		cameraMgr->MoveDown();
	if (parent->window->winKeyPressed(65))
		cameraMgr->MoveLeft();
	if (parent->window->winKeyPressed(68))
		cameraMgr->MoveRight();
	if (parent->window->winKeyPressed(262))
		if (checkBoatRight())
			checkGame();
	if (parent->window->winKeyPressed(263))
		if (checkBoatLeft())
			checkGame();
	if (parent->window->winKeyPressed(0))
	{
		std::cout << leftground.size()<<"\n";
		std::cout << rightground.size() << "\n";
		glm::vec2 coords;
		coords = parent->window->returnScreenCoords();
		/*coords = cameraMgr->ScreenToWorld(coords);
		cout << "\n" << coords.x << "\t" << coords.y << "\n";*/
	
		for (int i = 0; i < m_avatars.size(); i++)
		{
			float _x= m_avatars[i]->m_avatar->getBody()->GetPosition().x;
			float _y = m_avatars[i]->m_avatar->getBody()->GetPosition().y;
			if(coords.x >= _x && coords.x <=_x+100 && coords.y >= _y && coords.y <= _y + 100)
				{
					
					if (!isinboat || temp_ID == m_avatars[i]->ID)
						{
						//Code to throw object to ground
						if (_x >= 700 && _x < 900 && temp_ID == 1)
						{
							isinboat = false;
							b2Vec2 position(900, 500);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							auto it = std::find(leftground.begin(), leftground.end(), m_avatars[i]->ID);
							if (it != leftground.end())
								leftground.erase(it);
							rightground.push_back(m_avatars[i]->ID);
							isinboat = false;
							break;
						}
						else if (_x >= 400 && _x < 500 && temp_ID == 1)
						{
							isinboat = false;
							b2Vec2 position(200, 500);
							auto it = std::find(rightground.begin(), rightground.end(), m_avatars[i]->ID);
							if (it != rightground.end())
								rightground.erase(it);
							leftground.push_back(m_avatars[i]->ID);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							isinboat = false;
							break;
						}
						else if (_x >= 700 && _x < 900 && temp_ID == 2)
						{
							isinboat = false;
							b2Vec2 position(1000, 500);
							auto it = std::find(leftground.begin(), leftground.end(), m_avatars[i]->ID);
							if (it != leftground.end())
								leftground.erase(it);
							rightground.push_back(m_avatars[i]->ID);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							isinboat = false;
							break;

						}
						else if (_x >= 400 && _x < 500 && temp_ID == 2)
						{
							isinboat = false;
							b2Vec2 position(300, 500);
							auto it = std::find(rightground.begin(), rightground.end(), m_avatars[i]->ID);
							if (it != rightground.end())
								rightground.erase(it);
							leftground.push_back(m_avatars[i]->ID);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							isinboat = false;
							break;

						}
						else if (_x >= 700 && _x < 900 && temp_ID == 3)
						{
							isinboat = false;
							b2Vec2 position(1100, 500);
							auto it = std::find(leftground.begin(), leftground.end(), m_avatars[i]->ID);
							if (it != leftground.end())
								leftground.erase(it);
							rightground.push_back(m_avatars[i]->ID);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							isinboat = false;
							break;

						}
						else if (_x >= 400 && _x < 500 && temp_ID == 3)
						{
							isinboat = false;
							b2Vec2 position(100, 500);
							auto it = std::find(rightground.begin(), rightground.end(), m_avatars[i]->ID);
							if (it != rightground.end())
								rightground.erase(it);
							leftground.push_back(m_avatars[i]->ID);
							m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
							isinboat = false;
							break;

						}
					
					
					temp_ID = m_avatars[i]->ID;
					//Code to put objects in boat
					if (_x < 400 && m_player.getBody()->GetPosition().x < 420)
					{
						auto it = std::find(leftground.begin(), leftground.end(), m_avatars[i]->ID);
						if (it != leftground.end())
							leftground.erase(it);
						b2Vec2 position(m_player.getBody()->GetPosition().x, m_player.getBody()->GetPosition().y - 50);
						m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
						isinboat = true;
						break;
					}
					else if (_x > 850 &&  m_player.getBody()->GetPosition().x > 750)
					{
						auto it = std::find(rightground.begin(), rightground.end(), m_avatars[i]->ID);
						if (it != rightground.end())
							rightground.erase(it);
						b2Vec2 position(m_player.getBody()->GetPosition().x, m_player.getBody()->GetPosition().y - 50);
						m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
						isinboat = true;
						break;
					}
					
				}

			}
		}

	}
	//Code to update the position of avatars to the boats position
	if (isinboat)
	{
		for (int i = 0; i < m_avatars.size(); i++)
		{
			if(m_avatars[i]->ID==temp_ID)
			{
				b2Vec2 position(m_player.getBody()->GetPosition().x, m_player.getBody()->GetPosition().y - 50);
				m_avatars[i]->m_avatar->getBody()->SetTransform(position, 0);
			}
		}
	}
//	if (m_player.getBody()->GetPosition().x > 450 && m_player.getBody()->GetPosition().x < 750)
	//{
		//checkGame();
	//}
}
void Scene1::phyInit()
{
	b2Vec2 gravity(0.0f, 1000.81f);
	phy_world = std::make_unique<b2World>(gravity);
	//ground
	b2BodyDef groundDef;
	groundDef.position.Set(300.0f, 800.0f);
	b2Body* ground;
	ground = phy_world->CreateBody(&groundDef);

	b2PolygonShape groundshape;
	groundshape.SetAsBox(500.0f, 50.0f);

	ground->CreateFixture(&groundshape, 0.0f);
	//newbox.init(phy_world.get(), glm::vec2(300.0f, 200.0f), glm::vec2(100.0f, 100.0f));

}


Scene1::~Scene1()
{
}


