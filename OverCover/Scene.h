#pragma once
#include<GL\glew.h>
#include "ResourceManager.h"
#include "Shaders.h"
#include "Sprite.h"
class Scene
{
	
	GLboolean SKeys[1024];
	GLint SWidth,SHeight;
	
public:
	Scene(GLint,GLint);
	~Scene(void);
	//for debugging

	Shaders shad1;
	Sprite sprite;
	//Render Logic
	void SRender();
	//Update movements/physics
	void SUpdate();
	//Load all Shaders/textures/.. for the scene
	void SLoad_Init();
	GLint SGet_Width();
	GLint SGet_Height();
};
enum SceneState{

	ACTIVE,
	INACTIVE

};

