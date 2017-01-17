#include "GameObject.h"

/*void GameObject::SetDim_State(GLint _Width,GLint _Height,GameObject_State _state)
{
	Width=_Width;
	Height=_Height;
	State=_state;
}*/
GameObject::GameObject(void):Parent(nullptr),RenderState(Render_State::DRAWABLE),State(GameObject_State::ACTIVE),
	LocalTransform(1),WorldTransform(1)
{
	_Texture=NULL;
}
void GameObject::AddChild(GameObject* _child)
{
	_child->Parent=this;
	Children.push_back(_child);


}
void GameObject::RemoveChild(GameObject* _child)
{
	//Children.erase(_child,);
	find(Children.begin(),Children.end(),_child);
}
glm::mat4 GameObject::GetWorldTransform()
{
	return WorldTransform;
}
void GameObject::Update()
{
	if(Parent)
	{
		WorldTransform=LocalTransform*Parent->WorldTransform;
	}
	else
	{
		WorldTransform=LocalTransform;
	}
	//for(int i=0;i<Children.size;i++)
	//{
	//	Children[i]->Update();
	//}

}
GameObject::~GameObject(void)
{
	delete _Texture;
	for(int i=0;i<Children.size();i++)
	{
		delete Children[i];
	}
}
