#include "Transform.h"


Transform::Transform(void):Width(100.0f),Height(100.0f)
{
	Position=glm::vec3(0.0f,0.0f,0.0f);
	Rotation=0.0f;
	Scale=glm::vec3(0.0f,0.0f,0.0f);
	UpdatePositionVector();
}
Transform::Transform(glm::vec3 _position,GLfloat _rotation,glm::vec3 _scale)
{
	Position=_position;
	Rotation=_rotation;
	Scale=_scale;
	UpdatePositionVector();
}
void Transform::SetPosition(GLfloat _x=0.0f,GLfloat _y=0.0f,GLfloat _z=0.0f)
{
	Position.x+=_x;
	Position.y+=_y;
	Position.z+=_z;
	UpdatePositionVector();
}
void Transform::SetPosition(glm::vec3 _position)
{
	Position+=_position;
		UpdatePositionVector();
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
void Transform::SetWidth(GLfloat _width)
{
	Width+=_width;
}
void Transform::SetHeight(GLfloat _height)
{
	Height+=_height;
}
glm::mat4 Transform::GetLocalTransform()
{
	return LocalTransform;
}
glm::mat4 Transform::GetWorldTransform()
{
	return WorldTransform;
}
void Transform :: Update()
{glm::mat4 m;
glm::vec4 ver,res;
	for(int i=0;i<4;i++)
	{
		ver=glm::vec4(VecPostition[i].position.x,VecPostition[i].position.y,VecPostition[i].position.z,1.0f);
		res=m*ver;
	}
}
void Transform::UpdatePositionVector()
{
	VecPostition[0].position.SetPosition(Position.x,Position.y,Position.z);
	VecPostition[1].position.SetPosition(Position.x,Position.y+Height,Position.z);
	VecPostition[2].position.SetPosition(Position.x+Width,Position.y+Height,Position.z);
	VecPostition[3].position.SetPosition(Position.x+Width,Position.y,Position.z);
}
VertexData*  Transform::GetVertexPointer()
{
	return VecPostition;
}
Transform::~Transform(void)
{

}
