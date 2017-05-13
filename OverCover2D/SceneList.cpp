#include "SceneList.h"


namespace OverCover2D {
	SceneList::SceneList(IMainGame* _mainGame)
	{
		Parent = _mainGame;
	}

	IGameScene* SceneList::nextScene()
	{
		IGameScene* curScene = getCurrentScene();
		if (curScene->getNextSceneIndex() != -1)
		{
			currentSceneIndex = curScene->getNextSceneIndex();
		}
		return curScene;
	}

	IGameScene* SceneList::prevScene()
	{
		IGameScene* curScene = getCurrentScene();
		if (curScene->getPrevSceneIndex() != -1)
		{
			currentSceneIndex = curScene->getPrevSceneIndex();
		}
		return curScene;
	}

	IGameScene* SceneList::getCurrentScene()
	{
		if (currentSceneIndex == -1)return nullptr;
		return sceneList[currentSceneIndex];
	}

	void SceneList::addScene(IGameScene* newScene)
	{

		newScene->sceneIndexNo = sceneList.size();
		sceneList.push_back(newScene);
		
	
		
		newScene->setParent(Parent);
		newScene->build();
	}

	void SceneList::destroy()
	{
		for (int i = 0; i < sceneList.size(); i++)
		{
			sceneList[i]->destroy();
			//delete sceneList[i];
		}
		sceneList.resize(0);
		currentSceneIndex = -1;
	}

	void SceneList::setScene(int sceneIndex)
	{
		currentSceneIndex = sceneIndex;
	}


	SceneList::~SceneList()
	{
	}
}
