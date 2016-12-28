#pragma once
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>

class Transform
{
	glm::vec3 Position;
	GLfloat Rotation;
	glm::vec3 Scale;
public:
	Transform(void);
	Transform(glm::vec3,GLfloat,glm::vec3);
	void SetPosition(GLfloat,GLfloat,GLfloat);
	void SetRotation(GLfloat);
	void SetScale(GLfloat,GLfloat,GLfloat);
	void SetPosition(glm::vec3);
	void SetScale(glm::vec3);
	~Transform(void);
};

