#include "Scene.h"


Scene::Scene(GLint _width,GLint _height):sprite("broco","broco"),sprite1("container","container"),s2("cont","container"),resource(nullptr),renderer(nullptr)
{
	SWidth=_width;
	SHeight=_height;
	MyCamera=new Camera2D();
	
}


void Scene::SRender()
{
	//Create A Ortho-Projection Matrix
	
	//renderer->DrawSprite(sprite,0,glm::vec3(500,100,0),45.0f,glm::vec3(50,50,0));
	//renderer->DrawSprite(sprite1,0,glm::vec3(200, 200,0), 0.0f, glm::vec3(300, 200,0));
	//renderer->DrawSprite(s2,0,glm::vec3(400, 300,0), 0.0f, glm::vec3(800, 600,0));
//	for(int i=0;i<Sprites.size();i++)
	//{
	///renderer->DrawSprite(Sprites[0],0,glm::vec3(10.0f,10.0f,0.0f), 0.0f, glm::vec3(100.0f,100.0f,0.0f));
	///renderer->DrawSprite(Sprites[1],0,glm::vec3(200.0f,10.0f,0.0f), 0.0f, glm::vec3(100.0f,100.0f,0.0f));
		//for(int i=0;i<30;i++)
	///	renderer->DrawSprite(Sprites[1],0,glm::vec3(20*10.0f,300*10,0.0f), 0.0f, glm::vec3(50.0f,50.0f,0.0f));
	
	//glActiveTexture(resource->Get_ActiveTexture_Map(0));

Renderer.Begin();

	Renderer.End();
	Renderer.Renderer();

	//cout<<_resource->Get_Texture_Count();
	
	//_resource->Set_Texture_Count(); 

	//shad1.SetintU(Sprites.back()->getID(),0,0);
		//_Shader.SetMatrix4U("model",model,0);
		//_sprite->Draw();
	
//	Sprites.back()->Draw();
	//Sprites.front()->Draw();
	//renderer->DrawSprite(sprite,0);
	//renderer->DrawSprite(sprite1,1);
	//renderer->DrawSprite(sprite,sprite1);
}
void Scene::SUpdate()
{
	//MyCamera.View=glm::scale(MyCamera.View,glm::vec3(200.0f,200.0f,0.0f));
	glm::mat4 projection=glm::ortho(0.0f+MyCamera->GetZoomFactor()*10.0f,(GLfloat)SWidth-MyCamera->GetZoomFactor()*10.0f,(GLfloat)SHeight-MyCamera->GetZoomFactor()*10.0f,0.0f+MyCamera->GetZoomFactor()*10.0f,-1.0f,1.0f);
		//glm::mat4 projection=glOrtho(0.0f,(GLfloat)ScreenWidth,(GLfloat)ScreeHeight,0.0f,-1.0f,1.0f);
		//glm::mat4 projection=glm::perspective(45.0f,(GLfloat)(ScreenWidth/ScreeHeight),1.0f,1000.0f);
		//(300.0f,300.0f,0.0f);
		shad1.SetMatrix4U("projection",projection,0);
	//glm::mat4 v1;
	//v1=glm::scale(v1,glm::vec3(10.0f,10.0f,0.0f));
	
	MyCamera->View=MyCamera->LookAt();
	//glScalef(200.0f,200.0f,0.0f);
	shad1.SetMatrix4U("view",MyCamera->View,0);
	//shad1.SetMatrix4U("view",v1,0);
	
}
void Scene::SLoad_Init()
{
	 resource=ResourceManager::GetInstance();
	shad1=resource->LoadShaders("Shaders/v1.vert","Shaders/f1.frag");
	renderer=new SpriteRenderer(shad1);
	iomanage=InputManager::GetInstance();
	Sprites.push_back(new Sprite("con","con"));
	//Sprites.push_back(new Sprite("new","new"));
//	Sprite_Tree.push_back(sprite);
	//Sprite_Tree.push_back(sprite1);
	//sprite.Create("W:/papichulo/OverCover/OverCover/Textures/broco.jpg");
	//sprite1.Create("W:/papichulo/OverCover/OverCover/Textures/broco.jpg");
	//s2.Create("W:/papichulo/OverCover/OverCover/Textures/rono.jpg");
	Sprites.back()->Create("W:/papichulo/OverCover/OverCover/Textures/container.jpg");
	//Sprites.front()->Create("W:/papichulo/OverCover/OverCover/Textures/rono.jpg");
for(int i=0;i<Sprites.size();i++)
	{
		Renderer.CreateSpriteArray(Sprites[i]);
	}
	//sprite1.Init();
Renderer.Init();
}
void Scene::Create_sprite()
{
	//Sprite sprite("broco"),sprite1("COntu");
	//Sprite_Tree.push_back(sprite);
//	Spr

}
GLint Scene::SGet_Height()
{
	return SHeight;
}
GLint Scene::SGet_Width()
{
	return SWidth;
}
GLfloat Scene::GetZoomFactor()
{
	return iomanage->GetYscroll();
}
void Scene::Clean()
{
	
}
Scene::~Scene(void)
{
	
}