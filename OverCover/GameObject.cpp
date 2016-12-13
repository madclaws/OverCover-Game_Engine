#include "GameObject.h"

void GameObject::SetDim_State(GLint _Width,GLint _Height,GameObject_State _state)
{
	Width=_Width;
	Height=_Height;
	State=_state;
}
