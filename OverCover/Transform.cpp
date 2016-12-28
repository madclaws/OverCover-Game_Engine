#include "Transform.h"


Transform::Transform(void)
{
	Position=glm::vec3(0.0f,0.0f,0.0f);
	Rotation=0.0f;
	Scale=glm::vec3(0.0f,0.0f,0.0f);
}
Transform::Transform(glm::vec3 _position,GLfloat _rotation,glm::vec3 _scale)
{
	Position=_position;
	Rotation=_rotation;
	Scale=_scale;
}
void Transform::SetPosition(GLfloat _x=0.0f,GLfloat _y=0.0f,GLfloat _z=0.0f)
{
	Position.x+=_x;
	Position.y+=_y;
	Position.z+=_z;
}
void Transform::SetPosition(glm::vec3 _position)
{
	Position+=_position;
}
void Transform::SetRotation(GLfloat _rotation)
{
	Rotation=_rotation;
}
void Transform::SetScale(GLfloat _x=0.0f,GLfloat _y=0.0f,GLfloat _z=0.0f)
{
	Scale.x+=_x;
	Scale.y+=_y;
	Scale.z+=_z;
}
void Transform::SetScale(glm::vec3 _scale)
{
	Scale+=_scale;
}
Transform::~Transform(void)
{
}
