#pragma once
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include"Component.h"
#include"VertexData.h"
class Transform
{
	glm::vec3 Position;
	GLfloat Rotation;
	glm::vec3 Scale;
	GLfloat Width,Height;
	glm::mat4 LocalTransform;
	glm::mat4 WorldTransform;
	VertexData VecPostition[4];
public:
	Transform(void);
	Transform(glm::vec3,GLfloat,glm::vec3);
	void SetPosition(GLfloat,GLfloat,GLfloat);
	void SetRotation(GLfloat);
	void SetScale(GLfloat,GLfloat,GLfloat);
	void SetPosition(glm::vec3);
	void SetScale(glm::vec3);
	void SetWidth(GLfloat);
	void SetHeight(GLfloat);
	void UpdatePositionVector();
	glm::mat4 GetLocalTransform();
	glm::mat4 GetWorldTransform();
	VertexData* GetVertexPointer();
	void Update();
	~Transform(void);
};

