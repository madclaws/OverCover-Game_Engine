#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include "Scene.h"
using namespace std;

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
	
	//Creating Scene
	Scene Scene1(ScreenWidth,ScreeHeight);

	//Creating Window
	GLFWwindow* window=glfwCreateWindow(ScreenWidth,ScreeHeight,"MAIN",0,0);

	//Making Context to Current Window
	glfwMakeContextCurrent(window);

	//Glew initialization for USING OPENGL FUNCTIONS
	glewExperimental=true;
	if(glewInit()!=GLEW_OK)
	{
		cout<<"GLEW INITIALIZATION FAILED................\n";
		exit(0);
	}
	cout<<"GLFW INITIALIZATION SUCESS.............\n";
	//Engine Loop repeats unitl window is closed
	while(!glfwWindowShouldClose(window))
	{
		//Poll input Events
		glfwPollEvents();
	
		//Clear the Color buffer and Depth buffer each loop
		clear_function();

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
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	
	}
