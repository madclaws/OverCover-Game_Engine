#include "Transform.h"

namespace OverCover2D {
	/*Transform::Transform(void):Width(50.0f),Height(50.0f),LocalTransform(1),WorldTransform(1)
	{
		Position=glm::vec3(0.0f,0.0f,0.0f);
		Rotation=0.0f;
		Scale=glm::vec3(0.0f,0.0f,0.0f);
		UpdateLocalTransform(glm::vec3(0.0),0.0f,glm::vec3(Width,Height,0.0f));
	}
	Transform::Transform(glm::vec3 _position,GLfloat _rotation,glm::vec3 _scale)
	{
		Position=_position;
		Rotation=_rotation;
		Scale=_scale;
		UpdateLocalTransform(Position);
	}
	void Transform::SetPosition(GLfloat _x=0.0f,GLfloat _y=0.0f,GLfloat _z=0.0f)
	{
		Position.x=_x;
		Position.y=_y;
		Position.z=_z;
		UpdateLocalTransform(Position);
	}
	void Transform::SetPosition(glm::vec3 _position)
	{
		Position=_position;
			UpdateLocalTransform(Position);
	}
	void Transform::SetRotation(GLfloat _rotation)
	{
		Rotation=_rotation;
		UpdateLocalTransform(glm::vec3(0.0f,0.0f,0.0f),_rotation);
	}
	void Transform::SetScale(GLfloat _x=0.0f,GLfloat _y=0.0f,GLfloat _z=0.0f)
	{
		Scale.x=_x;
		Scale.y=_y;
		Scale.z=_z;
		UpdateLocalTransform(glm::vec3(0),0.0f,Scale);
	}
	void Transform::SetScale(glm::vec3 _scale)
	{
		Scale=_scale;
		UpdateLocalTransform(glm::vec3(0),0.0f,Scale);
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
	/*void Transform :: Update()
	{glm::mat4 m;
	glm::vec4 ver,res;
		for(int i=0;i<4;i++)
		{
			ver=glm::vec4(VecPostition[i].position.x,VecPostition[i].position.y,VecPostition[i].position.z,1.0f);
			res=m*ver;
		}
	}*/
	/*void Transform::UpdateLocalTransform(glm::vec3 _position,GLfloat angles,glm::vec3 _scale)
	{
		LocalTransform=glm::translate(LocalTransform,_position);
		LocalTransform=glm::rotate(LocalTransform,angles,glm::vec3(0.0f,0.0f,1.0f));
		LocalTransform=glm::scale(LocalTransform,_scale);
		/*VecPostition[0].position.SetPosition(Position.x,Position.y,Position.z);
		VecPostition[1].position.SetPosition(Position.x,Position.y+Height,Position.z);
		VecPostition[2].position.SetPosition(Position.x+Width,Position.y+Height,Position.z);
		VecPostition[3].position.SetPosition(Position.x+Width,Position.y,Position.z);
	}
	VertexData*  Transform::GetVertexPointer()
	{
		return VecPostition;
	}*/
	Transform::~Transform(void)
	{

	}
}
