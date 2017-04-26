#pragma once

#include<GL\glew.h>
#include<OverCover2D\IGameScene.h>
#include<OverCover2D\Camera2D.h>
#include<OverCover2D\ResourceManager.h>
#include<OverCover2D\Shaders.h>
#include"BulletBox.h"
#include<OverCover2D\SpriteBatchRenderer.h>
#include<OverCover2D\Sprite.h>
#include<OverCover2D\InputManager.h>
#include<glm\glm.hpp>
#include<OverCover2D\IMainGame.h>
#include<Box2D\Box2D.h>
#include<OverCover2D\Box.h>
#include<iostream>
#include<memory>
class Scene1:public OverCover2D::IGameScene
{

	
public:
	
	GLint SHeight, SWidth;
	OverCover2D::ResourceManager* resourceMgr = nullptr;
	OverCover2D::Camera2D* cameraMgr = nullptr;
	OverCover2D::InputManager* inputMgr = nullptr;
	BulletBox* bulletbox;
	OverCover2D::SpriteBatchRenderer rendererMgr;
	OverCover2D::Sprite* sprite;
	OverCover2D::Shaders shaderMgr ;
	std::unique_ptr<b2World> phy_world;
	OverCover2D::Box newbox;
	Scene1();
	virtual int getNextSceneIndex() override;
	virtual int getPrevSceneIndex() override;

	virtual  void build() override;
	virtual void destroy() override;

	virtual void enter() override;
	virtual void exit() override;

	virtual void render() override;
	virtual void update() override;
	void phyInit();
	void EventHandler();
	~Scene1();
};

