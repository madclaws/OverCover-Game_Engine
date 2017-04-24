#pragma once
#include<memory>
#include"SceneList.h"
#include"Window.h"
#include"FPSManager.h"
namespace OverCover2D {

	class IMainGame
	{
	protected:
		std::unique_ptr<SceneList> m_sceneList=nullptr;
		IGameScene* currentScene=nullptr;
		bool isrunning=false;
		
		FPSManager fpsmgr;
	public:
		Window* window = nullptr;
		IMainGame();
		void run();
		void exitgame();
		void Init();
		virtual void customInit() = 0;
		void update();
		void render();
		virtual void addScenes()=0;
		virtual void customExit() = 0;
		void initSystems();
		virtual ~IMainGame();
	}; 
}

