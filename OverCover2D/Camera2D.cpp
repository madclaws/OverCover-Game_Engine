#include "Camera2D.h"

namespace OverCover2D {
	Camera2D::Camera2D(GLfloat _screenWidth,GLfloat _screenHeight) :CameraPos(0.0f, 0.0f, 0.0f), CameraFront(0.0f, 0.0f, -1.0f), WorldUp(0.0f, 1.0f, 0.0f), Xaxis(0.0f, 0.0f, 0.0f),
		Yaxis(0.0f, 0.0f, 0.0f), Zaxis(0.0f, 0.0f, 0.0f), CameraSpeed(8.0f), ZoomFactor(0),
		screenWidth(_screenWidth), screenHeight(_screenHeight)
	{
		
		iomanage = InputManager::GetInstance();
	}

	glm::vec2 Camera2D::ScreenToWorld(glm::vec2 screenCoords)
	{
		screenCoords.x -= screenWidth / 2;
		screenCoords.y -= screenHeight / 2;
		if (ZoomFactor != 0)
		{
			screenCoords /= ZoomFactor;
		}
		else
		{
			screenCoords /= 1;
		}
		screenCoords.x += CameraPos.x;
		screenCoords.y += CameraPos.y;
		return screenCoords;
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
		return glm::lookAt(CameraPos, CameraFront + CameraPos, WorldUp);




	}
	void Camera2D::MoveLeft()
	{
		CameraPos -= glm::normalize(glm::cross(WorldUp, CameraFront))*CameraSpeed;

	}
	void Camera2D::MoveRight()
	{
		CameraPos += glm::normalize(glm::cross(WorldUp, CameraFront))*CameraSpeed;
	}
	void Camera2D::MoveUp()
	{
		CameraPos += CameraSpeed*WorldUp;
	}
	void Camera2D::MoveDown()
	{
		CameraPos -= CameraSpeed*WorldUp;
	}

	GLfloat Camera2D::GetZoomFactor()
	{
		ZoomFactor = iomanage->GetYscroll();
		return ZoomFactor;

	}
	glm::mat4 Camera2D::GetView()
	{
		return View;
	}
}