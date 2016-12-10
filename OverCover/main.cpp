#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
using namespace std;

int main()
{
	if(!glfwInit())
	{
		cout<<"GLFW INITIALISATION FAILED.............\n";
		exit(0);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window=glfwCreateWindow(500,500,"MAIN",0,0);
	glfwMakeContextCurrent(window);
	glewExperimental=true;
	if(glewInit()!=GLEW_OK)
	{
		cout<<"GLEW INITIALIZATION FAILED................\n";
		exit(0);
	}
	
	while(!glfwWindowShouldClose(window))
	{

	}
	glfwTerminate();

	return 0;
}