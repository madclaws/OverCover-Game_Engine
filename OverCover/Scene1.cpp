#include "Scene1.h"



Scene1::Scene1()
{
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
	std::cout << "Render\n";
}

void Scene1::update()
{
	std::cout << "Update\n";
}


Scene1::~Scene1()
{
}
