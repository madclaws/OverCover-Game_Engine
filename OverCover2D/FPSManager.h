#pragma once
#include<GLFW\glfw3.h>
#include<Windows.h>
#include<iostream>
using namespace std;
namespace OverCover2D {
	class FPSManager
	{
		GLfloat StartTime;
		static GLint FrameCount;
		static GLfloat MaxFps;
		GLfloat EndTime;
		GLfloat Required_ms;

	public:
		FPSManager(void);
		~FPSManager(void);
		void Begin();
		void LimitFps();
		void CalculateFPS();
	};
}

