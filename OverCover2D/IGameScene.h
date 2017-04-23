#pragma once

namespace OverCover2D {

	class IMainGame;
	class SceneList;
enum class sceneState {
	NONE,
	RUNNING,
	EXITING,
	NEXT,
	PREVIOUS

};
class IGameScene
{ 
	

protected:
	int sceneIndexNo=-1;
	IMainGame* parent=nullptr;
	sceneState currentState = sceneState::NONE;
public:
	friend class SceneList;
	IGameScene()
	{

	}

	virtual int getNextSceneIndex() = 0;
	virtual int getPrevSceneIndex() = 0;
	 int getSceneIndex() { return sceneIndexNo; }
	virtual  void build() = 0;
	virtual void destroy() = 0;

	virtual void enter() = 0;
	virtual void exit() = 0;

	virtual void render() = 0;
	virtual void update() = 0;

	void setRunning() { currentState = sceneState::RUNNING; }
	sceneState getState() { return currentState; }
	void setParent(IMainGame* _parent) { parent = _parent; }
	~IGameScene() {

	}
	};
}

