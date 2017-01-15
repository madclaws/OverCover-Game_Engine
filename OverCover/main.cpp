// Main Program Contains All GLFW Window Creating and Managing Commands.
//It is Abstracted Because Any One Uses Engine Source Can Write Their On Window(Main)
// Program With Suitable Opengl Toolkit(GLUT,SDL)
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<Windows.h>
#include "Scene.h"
#include<math.h>
#include "InputManager.h"
#include "FPSManager.h"
using namespace std;
void CalculateFps(GLint&);
void keycallback(GLFWwindow*,GLint,GLint,GLint,GLint);
void scrollcallback(GLFWwindow*,GLdouble,GLdouble);
void EventHandler();
InputManager* inputmanager;
FPSManager fpsmanage;
int ScreenWidth=500,ScreeHeight=500;
Scene Scene1(ScreenWidth,ScreeHeight);
void framebufcallback(GLFWwindow* _window,int _width,int _height)
{
	glViewport(0,0,_width,_height);
}

void clear_function();
int main()
{

	//Glfw Initializing for creating Window
	if(!glfwInit())
	{
		cout<<"GLFW INITIALIZATION FAILED.............\n";
		exit(0);
	}
	cout<<"GLFW INITIALIZATION SUCESS.............\n";
	//Configuring Window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	

	//Creating Window
	GLFWwindow* window=glfwCreateWindow(ScreenWidth,ScreeHeight,"MAIN",0,0);

	//Making Context to Current Window
	glfwMakeContextCurrent(window);
	//Calls When glclear calls
	//glClearColor(0.0f,0.0f,0.0f,1.0f);
	//Glew initialization for USING OPENGL FUNCTIONS
	glewExperimental=GL_TRUE;
	if(glewInit()!=GLEW_OK)
	{
		cout<<"GLEW INITIALIZATION FAILED................\n";
		exit(0);
	}
	cout<<"GLEW INITIALIZATION SUCESS.............\n";
	//Creating new Scene
	
	//Callback for resizing the window viewport
	glfwSetFramebufferSizeCallback(window,framebufcallback);
	glfwSetKeyCallback(window,keycallback);
	glfwSetScrollCallback(window,scrollcallback);
	inputmanager=InputManager::GetInstance();
	//Setting Default Viewport
	glViewport(0,0,500,500);
	//Loading Shaders and Textures for the Scene
	Scene1.SLoad_Init();

	//Engine Loop repeats unitl window is closed
	while(!glfwWindowShouldClose(window))
	{
		
		fpsmanage.Begin();
		glfwPollEvents();
		clear_function();
		
		EventHandler();
		
			//CalculateFps(count_frame);
		fpsmanage.CalculateFPS();
		Scene1.SUpdate();	
		Scene1.shad1.use();
		
		
		Scene1.SRender();
		glfwSwapInterval(1);
		//Swap the Rendering Buffer(Double Buffer)
		
		glfwSwapBuffers(window);
		fpsmanage.LimitFps();
		
	}
	//Releasing Window Resources
	glfwTerminate();

	return 0;
	
	
}
void clear_function()
	{
		//To clear the window each loop by clearing color buffer and depth buffer
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	}

void keycallback(GLFWwindow* _window,GLint key,GLint scan,GLint action,GLint mode)
	{
		if(action==GLFW_PRESS)
		{
			inputmanager->KeyPress(key);
		}
		else if(action==GLFW_RELEASE)
		{
			inputmanager->KeyRelease(key);
		}
		
	}

void scrollcallback(GLFWwindow* window,GLdouble xscroll,GLdouble yscroll)
{
	
//	cout<<yscroll<<endl<<endl;
	
	inputmanager->SetYscroll(yscroll);
	//cout<<"\n"<<inputmanager->GetYscroll()<<endl;
}

void EventHandler()
{
	if(inputmanager->IsKeyPressed(GLFW_KEY_W))
		Scene1.MyCamera->MoveUp();
	if(inputmanager->IsKeyPressed(GLFW_KEY_S))
			Scene1.MyCamera->MoveDown();
	if(inputmanager->IsKeyPressed(GLFW_KEY_A))
			Scene1.MyCamera->MoveLeft();
	if(inputmanager->IsKeyPressed(GLFW_KEY_D))
			Scene1.MyCamera->MoveRight();
	
}
