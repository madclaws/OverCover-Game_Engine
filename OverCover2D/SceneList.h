#pragma once
#include"IGameScene.h"
#include<vector>
namespace OverCover2D {
	class IMainGame;
	class SceneList
	{
		
		
	protected:
		IMainGame* Parent = nullptr;
		std::vector<IGameScene*> sceneList;
		int currentSceneIndex = -1;

	public:
		SceneList(IMainGame*);
		IGameScene* nextScene();
		IGameScene* prevScene();
		IGameScene* getCurrentScene();
		void addScene(IGameScene*);
		void destroy();
		void setScene(int);
		~SceneList();
	};
}

