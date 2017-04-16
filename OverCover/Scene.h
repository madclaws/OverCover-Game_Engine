#pragma once
#ifndef SCENE_H
#define SCENE_H
#include<GL\glew.h>
#include <OverCover2D\ResourceManager.h>
#include <OverCover2D\Shaders.h>
#include <OverCover2D\Sprite.h>
#include<vector>
#include <OverCover2D\SpriteRenderer.h>
#include <OverCover2D\SpriteBatchRenderer.h>
#include <OverCover2D\Camera2D.h>
#include <OverCover2D\GameObject.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<OverCover2D\InputManager.h>
#include<Box2D\Box2D.h>
#include<cstdlib>
#include<OverCover2D\Box.h>		
#include "BulletBox.h"
#include<OverCover2D\GUI.h>
//#include<CEGUI\CEGUI.h>
//#include<CEGUI\RendererModules\OpenGL\GL3Renderer.h>
class Scene
{
	
	
	GLint SWidth,SHeight;
	GLenum Active_Textures[32];
	OverCover2D::ResourceManager* resource;
	OverCover2D::SpriteRenderer* renderer;
	OverCover2D::InputManager* iomanage;
	OverCover2D::GameObject* ROOT;
	std::shared_ptr<b2World> phy_world;
	std::vector<OverCover2D::Box> Boxes;
	//OverCover2D::GUI gui;
	//static GLint ObjectCount;
public:
	
	Scene(GLint,GLint);
	~Scene(void);
	//std::vector<BulletBox> bulletbox;
	BulletBox* bulletbox;
	OverCover2D::Camera2D* MyCamera;
	OverCover2D::SpriteBatchRenderer Renderer;
	//for debugging
	std::vector<OverCover2D::Sprite> Sprite_Tree;
	OverCover2D::Shaders shad1;
	OverCover2D::Sprite sprite,sprite1,s2;
	std::vector<OverCover2D::Sprite*> Sprites;
	//Render Logic
	void SRender();
	//Update movements/physics
	void SUpdate();
	//Load all Shaders/textures/.. for the scene
	void SLoad_Init();
	GLint SGet_Width();
	void Create_sprite();
	GLint SGet_Height();
	GLfloat GetZoomFactor();
	void Clean();
	//void AddGameObject(GameObject*);
	void PhysixInit();

	//void SetObjCount(GLint);
	//GLint GetObjCount();
};
enum SceneState{

	ACTIVE,
	INACTIVE

};

#endif