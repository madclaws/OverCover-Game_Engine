#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
using namespace std;

void clear_function();
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
		glfwPollEvents();
	

		clear_function();
		glfwSwapBuffers(window);
	}
	glfwTerminate();

	return 0;
	
}
void clear_function()
	{glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	
	
	}
