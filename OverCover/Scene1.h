#pragma once
#include<OverCover2D\IGameScene.h>
#include<iostream>
class Scene1:public OverCover2D::IGameScene
{
public:
	Scene1();
	virtual int getNextSceneIndex() override;
	virtual int getPrevSceneIndex() override;

	virtual  void build() override;
	virtual void destroy() override;

	virtual void enter() override;
	virtual void exit() override;

	virtual void render() override;
	virtual void update() override;
	~Scene1();
};

