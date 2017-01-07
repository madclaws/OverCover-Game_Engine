#pragma once
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>
#include"InputManager.h"
class Camera2D
{
	glm::vec3 CameraPos;
	glm::vec3 CameraFront;
	glm::vec3 WorldUp;
	glm::vec3 Xaxis;
	glm::vec3 Yaxis;
	glm::vec3 Zaxis;
	GLfloat ZoomFactor;
	GLfloat CameraSpeed;
	InputManager* iomanage;

public:
	glm::mat4 View;
	Camera2D(void);
	glm::mat4 LookAt();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	GLfloat GetZoomFactor();
	glm::mat4 GetView();
	~Camera2D(void);
};

