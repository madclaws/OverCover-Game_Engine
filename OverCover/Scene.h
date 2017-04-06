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
class Scene
{
	
	
	GLint SWidth,SHeight;
	GLenum Active_Textures[32];
	ResourceManager* resource;
	SpriteRenderer* renderer;
	InputManager* iomanage;
	GameObject* ROOT;
	std::shared_ptr<b2World> phy_world;
	std::vector<Box> Boxes;
	//static GLint ObjectCount;
public:
	
	Scene(GLint,GLint);
	~Scene(void);
	Camera2D* MyCamera;
	SpriteBatchRenderer Renderer;
	//for debugging
	std::vector<Sprite> Sprite_Tree;
	Shaders shad1;
	Sprite sprite,sprite1,s2;
	std::vector<Sprite*> Sprites;
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