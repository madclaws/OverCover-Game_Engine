#pragma once
#include<OverCover2D\RigidBody2D.h>

class Avatars
{
	
public:
	OverCover2D::RigidBody2D* m_avatar;
	int ID;
	Avatars();
	Avatars(OverCover2D::RigidBody2D* ,int);
	~Avatars();
};

