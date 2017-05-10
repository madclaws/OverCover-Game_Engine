#include "Avatars.h"


Avatars::Avatars()
{
	m_avatar = nullptr;
	ID = NULL;
}


Avatars::Avatars(OverCover2D::RigidBody2D* _sprite,int _ID)
{
	m_avatar = _sprite;
	ID = _ID;
}


Avatars::~Avatars()
{
}
