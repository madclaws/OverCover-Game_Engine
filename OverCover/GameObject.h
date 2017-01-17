#pragma once
// GameObject Will be an Abstract class for Variety of Game Objects such as Sprites,Fonts
//	Audio etc
#pragma once
#include<GL\glew.h>
#include "Draw_Interface.h"
#include "Transform.h"
#include "Texture2D.h"
#include<vector>
enum class GameObject_State{
	ACTIVE,
	DISABLED
};
enum class Render_State{
	DRAWABLE,
	NON_DRAWABLE
};
class GameObject
{
protected:
	const GLchar* ID;
	GameObject_State State;
	Render_State RenderState;
	std::vector<GameObject*> Children;
	GameObject* Parent;
	glm::mat4 LocalTransform;
	glm::mat4 WorldTransform;
	
	
	Transform _Transform;
	Texture2D* _Texture;
public:
	GameObject(void);
	~GameObject();
		//Draw_Interface* D_interface;
		//Respective GameObjects Define Dimension and State
		//virtual void SetDim_State(GLint=0,GLint=0,GameObject_State=GameObject_State::ACTIVE);
		//void SetState(GameObject_State state=GameObject_State::ACTIVE);
		//Respective GameObjects Define Their own Position System
		//virtual void SetPosition()=0;
		//Respective GameObjects Define Their Own Init System(Initializing ,generating VBO etc...
	virtual void AddChild(GameObject*);
	virtual void RemoveChild(GameObject*);
	virtual glm::mat4 GetWorldTransform();
	virtual void Update();
	virtual void Init()=0;
		//Function for Rendering Code;
		virtual void Draw()=0;
//		virtual void Set_Position()=0;

};



