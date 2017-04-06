// Main Program Contains All GLFW Window Creating and Managing Commands.
//It is Abstracted Because Any One Uses Engine Source Can Write Their On Window(Main)
// Program With Suitable Opengl Toolkit(GLUT,SDL)
#define GLEW_STATIC
#include<GL\glew.h>

#include<iostream>
#include<Windows.h>
#include "Scene.h"
#include<math.h>
#include <OverCover2D\FPSManager.h>
#include<OverCover2D\Window.h>
using namespace std;
//void CalculateFps(GLint&);
Window curWindow;

FPSManager fpsmanage;

Scene* Scene1;
void EventHandler();
void clear_function();
int main()
{
	curWindow.create("Game",500,500,true);
	Scene1 = new Scene(curWindow.getScreenWidth(),curWindow.getScreenHeight());
	Scene1->SLoad_Init();

	//Engine Loop repeats unitl window is closed
	while(curWindow.winState())
	{
		
		fpsmanage.Begin();
		//glfwPollEvents();
		curWindow.pollEvents();
		clear_function();
		
		EventHandler();
		
			//CalculateFps(count_frame);
		fpsmanage.CalculateFPS();
		Scene1->SUpdate();	
		Scene1->shad1.use();
		
		
		Scene1->SRender();
		//glfwSwapInterval(1);
		curWindow.swapInterval();
		//Swap the Rendering Buffer(Double Buffer)
		
		//glfwSwapBuffers(window);
		curWindow.swapBuffer();
		fpsmanage.LimitFps();
		
	}
	//Releasing Window Resources
	curWindow.Terminate();
	//glfwTerminate();

	return 0;
	
	
}
void clear_function()
	{
		//To clear the window each loop by clearing color buffer and depth buffer
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glEnable(GL_BLEND);
		glDisable(GLU_CULLING);
		//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	}


void EventHandler()
{
	if(curWindow.winKeyPressed(87))
		Scene1->MyCamera->MoveUp();
	if(curWindow.winKeyPressed(83))
			Scene1->MyCamera->MoveDown();
	if(curWindow.winKeyPressed(65))
			Scene1->MyCamera->MoveLeft();
	if(curWindow.winKeyPressed(68))
			Scene1->MyCamera->MoveRight();
	
}
