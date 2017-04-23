#pragma once
#include<OverCover2D\IMainGame.h>
#include"Scene1.h"
#include<OverCover2D\SceneList.h>
class App:public OverCover2D::IMainGame
{

private:
	std::unique_ptr<Scene1> m_Scene1 = nullptr;
public:
	App();
	virtual void customInit() override;
	virtual void addScenes() override;
	virtual void customExit() override;
	~App();
};

