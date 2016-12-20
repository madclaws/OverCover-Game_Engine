#include "Scene.h"


Scene::Scene(GLint _width,GLint _height)
{
	SWidth=_width;
	SHeight=_height;
	Set_ActiveTex_map();
}


Scene::~Scene(void)
{

}
void Scene::SRender()
{
	glActiveTexture(Active_Textures[0]);
	shad1.SetintU("broco",0,0);
	sprite.Draw();
	
	glActiveTexture(Active_Textures[1]);
	shad1.SetintU("container",1,0);
	sprite1.Draw();
	
}
void Scene::SUpdate()
{

}
void Scene::SLoad_Init()
{
	ResourceManager* resource=ResourceManager::GetInstance();
	shad1=resource->LoadShaders("Shaders/v1.vert","Shaders/f1.frag");
	sprite.Create("W:/papichulo/OverCover/OverCover/Textures/broco.jpg");
	sprite1.Create("W:/papichulo/OverCover/OverCover/Textures/container.jpg");
	//sprite1.Init();
}
GLint Scene::SGet_Height()
{
	return SHeight;
}
GLint Scene::SGet_Width()
{
	return SWidth;
}
void Scene::Set_ActiveTex_map()
{
	Active_Textures[0]=GL_TEXTURE0;
	Active_Textures[1]=GL_TEXTURE1;
	Active_Textures[2]=GL_TEXTURE2;
	Active_Textures[3]=GL_TEXTURE3;
	Active_Textures[4]=GL_TEXTURE4;
	Active_Textures[5]=GL_TEXTURE5;
	Active_Textures[6]=GL_TEXTURE6;
	Active_Textures[7]=GL_TEXTURE7;
	Active_Textures[8]=GL_TEXTURE8;
	Active_Textures[9]=GL_TEXTURE9;
	Active_Textures[10]=GL_TEXTURE10;
}