#include "Scene.h"


Scene::Scene(GLint _width,GLint _height):sprite(),sprite1(),s2(),resource(nullptr),renderer(nullptr)
{
	SWidth=_width;
	SHeight=_height;
	MyCamera=new OverCover2D::Camera2D(SWidth,SHeight);
	
}


void Scene::SRender()
{
	

	Renderer.RenderScene();

}
void Scene::SUpdate()
{
	
	//MyCamera.View=glm::scale(MyCamera.View,glm::vec3(200.0f,200.0f,0.0f));
	phy_world->Step(1.0f/60.0f,6,2);
	//bulletbox->update();
	bulletbox->update();
	
	glm::mat4 projection=glm::ortho(0.0f+MyCamera->GetZoomFactor()*10.0f,(GLfloat)SWidth-MyCamera->GetZoomFactor()*10.0f,(GLfloat)SHeight-MyCamera->GetZoomFactor()*10.0f,0.0f+MyCamera->GetZoomFactor()*10.0f,-1.0f,1.0f);

		shad1.SetMatrix4U("projection",projection,0);
	//glm::mat4 v1;
	//v1=glm::scale(v1,glm::vec3(10.0f,10.0f,0.0f));
	
	MyCamera->View=MyCamera->LookAt();
	//glScalef(200.0f,200.0f,0.0f);
	shad1.SetMatrix4U("view",MyCamera->View,0);
	//shad1.SetMatrix4U("view",v1,0);
	gui.draw();
}
void Scene::SLoad_Init()
{
	
	 resource= OverCover2D::ResourceManager::GetInstance();
	shad1=resource->LoadShaders("Shaders/v1.vert","Shaders/f1.frag");
	renderer=new OverCover2D::SpriteRenderer(shad1);
	iomanage= OverCover2D::InputManager::GetInstance();
	PhysixInit();
	bulletbox = new BulletBox(glm::vec2(300, 300), 1, 10,Renderer);
	//bulletbox->drawBullet(Renderer);
	//Sprites.push_back(new OverCover2D::Sprite());
	//Sprites[0]->Create("textures/box1.jpg", 300, 200, 100, 100);
	/*Box b=Boxes[0];
	glm::vec4 dim;
	dim.x=b.getBody()->GetPosition().x;
	dim.y=b.getBody()->GetPosition().y;
	dim.z=b.getDimension().x;
	dim.w=b.getDimension().y;
	Sprites.push_back(new Sprite("con","con"));
	Sprites[0]->Create("W:/papichulo/OverCover/OverCover/Textures/container.jpg",dim.x,dim.y,dim.z,dim.w);*/
/*for(int i=0;i<Sprites.size();i++)
	{
		Renderer.CreateSpriteArray(Sprites[i]);
	}*/
	//sprite1.Init();
Renderer.Init();
/*Renderer.Begin();

	Renderer.End();*/
//temp UI
//CEGUI::OpenGL3Renderer& My_Renderer = CEGUI::OpenGL3Renderer::bootstrapSystem();
try {
	gui.init("GUI");
	gui.loadScheme("TaharezLook.scheme");
	gui.setFont("DejaVuSans-10");
	CEGUI::PushButton* testbtn=static_cast<CEGUI::PushButton*>(gui.createWidget("TaharezLook/Button", "testButton", glm::vec4(0.5f, 0.5f, 0.1f, 0.1f), glm::vec4(0.0f)));
	testbtn->setText("Hello world");
	gui.setMouseCursor("TaharezLook/MouseArrow");
	gui.showCursor();
}
catch (exception e)
{
	std::cout << "not worked";
}

//gui.createWidget("TaharezLook/Button","testButton", glm::vec4(0.5f, 0.5f, 0.1f, 0.1f), glm::vec4(0.0f));
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
void Scene::PhysixInit()
{
	
	b2Vec2 gravity(0.0f,-9.81f);
	phy_world=std::make_shared<b2World>(gravity);

	//making ground
	b2BodyDef groundBodydef;
	groundBodydef.position.Set(0,-20);
	//creating ground
	b2Body* groundBody=phy_world->CreateBody(&groundBodydef);
	//binding shape to rigidbody
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50,10);
	groundBody->CreateFixture(&groundBox,0.0f);
	OverCover2D::Box new_box;
	new_box.init(phy_world.get(),glm::vec2(50.0f,14.0f),glm::vec2(15.0f,15.0f));
	Boxes.push_back(new_box);
}

void Scene::Clean()
{
	
}

Scene::~Scene(void)
{
	
}