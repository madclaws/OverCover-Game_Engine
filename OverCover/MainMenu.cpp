#include "MainMenu.h"



MainMenu::MainMenu()
{
	cameraMgr = new OverCover2D::Camera2D(1366, 768);
	SWidth = 1366;
	SHeight = 768;
}

int MainMenu::getNextSceneIndex()
{
	return 0;
}

int MainMenu::getPrevSceneIndex()
{
	return 0;
}

void MainMenu::build()
{
	resourceMgr = OverCover2D::ResourceManager::GetInstance();
	shaderMgr = resourceMgr->LoadShaders("Shaders/v1.vert", "Shaders/f1.frag");
	inputMgr = OverCover2D::InputManager::GetInstance();
}

void MainMenu::destroy()
{
}

void MainMenu::enter()
{
}

void MainMenu::exit()
{
}

void MainMenu::render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MainMenu::update()
{
}


MainMenu::~MainMenu()
{
}
