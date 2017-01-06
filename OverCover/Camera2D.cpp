#include "Camera2D.h"


Camera2D::Camera2D(void):CameraPos(0.0f,0.0f,0.0f),CameraFront(0.0f,0.0f,-1.0f),WorldUp(0.0f,1.0f,0.0f),Xaxis(0.0f,0.0f,0.0f),
	Yaxis(0.0f,0.0f,0.0f),Zaxis(0.0f,0.0f,0.0f),CameraSpeed(1.0f),ZoomFactor(0)
{

}


Camera2D::~Camera2D(void)
{
}
glm::mat4 Camera2D::LookAt()
{
	//CameraFront=CameraPos+CameraFront;
	/*Zaxis=glm::normalize(CameraPos-CameraFront);
	Xaxis=glm::normalize(glm::cross(WorldUp,Zaxis));
	Yaxis=glm::normalize(glm::cross(Zaxis,Xaxis));
	 GLfloat alignmatrix[16]={
		Xaxis.x,Xaxis.y,Xaxis.z,0.0f,
		Yaxis.x,Yaxis.y,Yaxis.z,0.0f,
		Zaxis.x,Zaxis.y,Zaxis.z,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	GLfloat positionmatrix[16]={
		0.0f,0.0f,0.0f,-CameraPos.x,
		0.0f,0.0f,0.0f,-CameraPos.y,
		0.0f,0.0f,0.0f,-CameraPos.z,
		0.0f,0.0f,0.0f,1.0f
	};
	glm::mat4 alignmat=glm::make_mat4(alignmatrix);
	alignmat=glm::transpose(alignmat);
	glm::mat4 positionmat=glm::make_mat4(positionmatrix);
	positionmat=glm::transpose(positionmat);*/
	//return alignmat*positionmat;
	return glm::lookAt(CameraPos,CameraFront+CameraPos,WorldUp);




}
void Camera2D::MoveLeft()
{
	CameraPos-=glm::normalize(glm::cross(WorldUp,CameraFront))*CameraSpeed;

}
void Camera2D::MoveRight()
{
	CameraPos+=glm::normalize(glm::cross(WorldUp,CameraFront))*CameraSpeed;
}
void Camera2D::MoveUp()
{
	CameraPos+=CameraSpeed*WorldUp;
}
void Camera2D::MoveDown()
{
	CameraPos-=CameraSpeed*WorldUp;
}
void Camera2D::Zoom()
{
	//0CameraPos-=CameraSpeed*CameraFront;
	++ZoomFactor;

}
GLint Camera2D::GetZoomFactor()
{
	return ZoomFactor;
}
glm::mat4 Camera2D::GetView()
{
	return View;
}
