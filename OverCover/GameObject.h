#pragma once
// GameObject Will be an Abstract class for Variety of Game Objects such as Sprites,Fonts
//	Audio etc
#pragma once
#include<GL\glew.h>
class GameObject
{
	GLint Width,Height;
	GameObject_State State;
public:
		//Respective GameObjects Define Dimension and State
		virtual void SetDim_State(GLint=0,GLint=0,GameObject_State=GameObject_State::ACTIVE);
		void SetState(GameObject_State state=GameObject_State::ACTIVE);
		//Respective GameObjects Define Their own Position System
		virtual void SetPosition()=0;
		//Respective GameObjects Define Their Own Init System(Includes Setting State,Width & Height
		virtual void Init()=0;

};
enum class GameObject_State{
	ACTIVE,
	DISABLED
};

