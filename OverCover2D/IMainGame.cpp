#include "IMainGame.h"

namespace OverCover2D {

	IMainGame::IMainGame()
	{
		m_sceneList = std::make_unique<SceneList>(this);
	}
	void IMainGame::run()
	{
		Init();
		while (window->winState())
		{
			fpsmgr.Begin();
			window->pollEvents();

			fpsmgr.CalculateFPS();
			
			render();
			update();
			window->swapInterval();
			window->swapBuffer();
			fpsmgr.LimitFps();

		}
		window->Terminate();

	}
	void IMainGame::exitgame()
	{
		currentScene->exit();
		if (m_sceneList)
		{
			m_sceneList->destroy();
			m_sceneList.reset();

		}
		isrunning = false;
		window->WIN_STATE = false;
	}
	void IMainGame::update()
	{
		if (currentScene)
		{
			switch (currentScene->getState())
			{
			case sceneState::RUNNING:currentScene->update();
				break;
			case sceneState::NEXT:
				currentScene->destroy();
				currentScene = m_sceneList->nextScene();
				if (currentScene)
				{
					currentScene->setRunning();
					currentScene->enter();
				}
				break;
			case sceneState::PREVIOUS:
				currentScene->destroy();
				currentScene = m_sceneList->prevScene();
				if (currentScene)
				{
					currentScene->setRunning();
					currentScene->enter();
				}
				break;
			case sceneState::EXITING:
				exitgame();
				break;
			default:
				break;
			}
		}
		else
			exitgame();
	}
	void IMainGame::render()
	{
		if (currentScene && currentScene->getState() == sceneState::RUNNING)
		{
			currentScene->render();
		}
	}
	void IMainGame::Init()
	{
		initSystems();
		addScenes();
		currentScene = m_sceneList->getCurrentScene();
		currentScene->enter();
		currentScene->setRunning();
	}

	

	void IMainGame::initSystems()
	{
		window = new Window();
		window->create("Scene1",1366,768, true);
	}

	IMainGame::~IMainGame() 
	{
	}
}
