#include "App.h"



App::App()
{
}

void App::addScenes()
{
	m_Scene1 = std::make_unique<Scene1>();
	m_sceneList->addScene(m_Scene1.get());
	m_sceneList->setScene(m_Scene1->getSceneIndex());

}
void App::customInit()
{
	//setDebug(true);
}
void App::customExit()
{

}

App::~App()
{
}
