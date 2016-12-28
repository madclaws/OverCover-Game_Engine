// Main Program Contains All GLFW Window Creating and Managing Commands.
//It is Abstracted Because Any One Uses Engine Source Can Write Their On Window(Main)
// Program With Suitable Opengl Toolkit(GLUT,SDL)
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include "Scene.h"
#include<math.h>
using namespace std;

void framebufcallback(GLFWwindow* _window,int _width,int _height)
{
	glViewport(0,0,_width,_height);
}
void clear_function();
int main()
{int ScreenWidth=500,ScreeHeight=500;
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
	glewExperimental=true;
	if(glewInit()!=GLEW_OK)
	{
		cout<<"GLEW INITIALIZATION FAILED................\n";
		exit(0);
	}
	cout<<"GLEW INITIALIZATION SUCESS.............\n";
	//Creating new Scene
	Scene Scene1(ScreenWidth,ScreeHeight);
	//Callback for resizing the window viewport
	glfwSetFramebufferSizeCallback(window,framebufcallback);
	//Setting Default Viewport
	glViewport(0,0,500,500);
	//Loading Shaders and Textures for the Scene
	Scene1.SLoad_Init();
	//Engine Loop repeats unitl window is closed
	while(!glfwWindowShouldClose(window))
	{
		//Poll input Events
		glfwPollEvents();
	clear_function();
		//Clear the Color buffer and Depth buffer each loop
		//Scene1.shad1.SetFloatU("col",(GLfloat)sin(glfwGetTime()*1.5f),0);
	//Scene1.shad1.SetintU("text",
		//Using the Shader for Scene
		Scene1.shad1.use();
		
		//Render GameObjects in Scene
		Scene1.SRender();

		//Swap the Rendering Buffer(Double Buffer)
		glfwSwapBuffers(window);

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
	
	
	}
