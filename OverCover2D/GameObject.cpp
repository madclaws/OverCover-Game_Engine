#include "GameObject.h"
namespace OverCover2D {
	/*void GameObject::SetDim_State(GLint _Width,GLint _Height,GameObject_State _state)
	{
		Width=_Width;
		Height=_Height;
		State=_state;
	}*/
	GameObject::GameObject(void) :RenderState(Render_State::DRAWABLE), State(GameObject_State::ACTIVE)

	{
		_Texture = NULL;
	}
	/*void GameObject::AddChild(GameObject* _child)
	{
		_child->Parent=this;
		Children.push_back(_child);


	}
	void GameObject::RemoveChild(GameObject* _child)
	{
		//Children.erase(_child,);
		auto iter=find(Children.begin(),Children.end(),_child);
		Children.erase(iter);
	}
	glm::mat4 GameObject::GetWorldTransform()
	{
		return _Transform.GetWorldTransform();
	}
	void GameObject::Update()
	{
		if(Parent)
		{
			_Transform.GetWorldTransform()=_Transform.GetLocalTransform()*Parent->_Transform.GetWorldTransform();
		}
		else
		{
			_Transform.GetWorldTransform()=_Transform.GetLocalTransform();
		}
		for(int i=0;i<this->Children.size();i++)
		{
			Children[i]->Update();
		}

	}*/
	GameObject::~GameObject(void)
	{
		delete _Texture;
		/*for(int i=0;i<Children.size();i++)
		{
			delete Children[i];
		}*/
	}
}
