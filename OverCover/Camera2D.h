#pragma once
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>
class Camera2D
{
	glm::vec3 CameraPos;
	glm::vec3 CameraFront;
	glm::vec3 WorldUp;
	glm::vec3 Xaxis;
	glm::vec3 Yaxis;
	glm::vec3 Zaxis;
	GLint ZoomFactor;
	GLfloat CameraSpeed;
public:
	glm::mat4 View;
	Camera2D(void);
	glm::mat4 LookAt();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	GLint GetZoomFactor();
	void Zoom();
	glm::mat4 GetView();
	~Camera2D(void);
};

