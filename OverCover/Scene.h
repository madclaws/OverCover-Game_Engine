#pragma once
#include<GL\glew.h>
class Scene
{
	
	GLboolean SKeys[1024];
	GLint SWidth,SHeight;
	
public:
	Scene(GLfloat,GLfloat);
	~Scene(void);
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

