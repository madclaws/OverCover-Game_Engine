#include "Scene.h"


Scene::Scene(GLint _width,GLint _height)
{
	SWidth=_width;
	SHeight=_height;
}


Scene::~Scene(void)
{

}
void Scene::SRender()
{
	sprite.Draw();
}
void Scene::SUpdate()
{

}
void Scene::SLoad_Init()
{
	ResourceManager* resource=ResourceManager::GetInstance();
	shad1=resource->LoadShaders("Shaders/v1.vert","Shaders/f1.frag");
	sprite.Init();
}
GLint Scene::SGet_Height()
{
	return SHeight;
}
GLint Scene::SGet_Width()
{
	return SWidth;
}