#pragma once
#include<GL\glew.h>
#include "ResourceManager.h"
#include "Shaders.h"
#include "Sprite.h"
#include<vector>
#include "SpriteRenderer.h"
class Scene
{
	
	GLboolean SKeys[1024];
	GLint SWidth,SHeight;
	GLenum Active_Textures[32];
	ResourceManager* resource;
	SpriteRenderer* renderer;
public:
	Scene(GLint,GLint);
	~Scene(void);
	
	//for debugging
	std::vector<Sprite> Sprite_Tree;
	Shaders shad1;
	Sprite sprite,sprite1,s2;
	//Render Logic
	void SRender();
	//Update movements/physics
	void SUpdate();
	//Load all Shaders/textures/.. for the scene
	void SLoad_Init();
	GLint SGet_Width();
	void Create_sprite();
	GLint SGet_Height();
	
};
enum SceneState{

	ACTIVE,
	INACTIVE

};

