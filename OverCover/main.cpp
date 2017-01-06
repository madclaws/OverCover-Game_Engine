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
using namespace std;
void CalculateFps(GLint&);
void keycallback(GLFWwindow*,int,int,int,int);
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
	glewExperimental=true;
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
	//Setting Default Viewport
	glViewport(0,0,500,500);
	//Loading Shaders and Textures for the Scene
	Scene1.SLoad_Init();

	//Engine Loop repeats unitl window is closed
	while(!glfwWindowShouldClose(window))
	{
		GLfloat starttime=glfwGetTime();
		static GLint count_frame=0;
		static GLfloat maxfps=60.0f;
		//Poll input Events
		//cout<<starttime<<endl;
		//outer_Frame+=adder_timer;
		glfwPollEvents();
		clear_function();
		
		{
			CalculateFps(count_frame);
			//outer_Frame+=0.05f;
		}
		//Using the Shader for Scene
		
		//glm::mat4 projection=glm::ortho(0.0f,(GLfloat)ScreenWidth-400.0f,(GLfloat)ScreeHeight-400.0f,0.0f,-1.0f,1.0f);
		//glm::mat4 projection=glOrtho(0.0f,(GLfloat)ScreenWidth,(GLfloat)ScreeHeight,0.0f,-1.0f,1.0f);
		//glm::mat4 projection=glm::perspective(45.0f,(GLfloat)(ScreenWidth/ScreeHeight),1.0f,1000.0f);
		//(300.0f,300.0f,0.0f);
		//Scene1.shad1.SetMatrix4U("projection",projection,0);
		Scene1.SUpdate();	
		Scene1.shad1.use();
		
		//Render GameObjects in Scene
		Scene1.SRender();
		glfwSwapInterval(0);
		//Swap the Rendering Buffer(Double Buffer)
		glfwSwapBuffers(window);
		++count_frame;
		GLfloat endtime=glfwGetTime()-starttime;
		endtime=endtime*1000;
		//cout<<endtime<<endl;
		if(((1000.0f/maxfps))>endtime)
		{
			Sleep((1000.0f/maxfps)-(endtime));
		}
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
void CalculateFps(GLint& c_frame)
{
	static GLdouble previous_time=glfwGetTime();
	GLdouble curr_time=glfwGetTime();
	static const GLint SAMPLE=5;
	static GLint sample_count=0;
	GLint avg_count=0;
	GLdouble frame_avg_time=0;
	static GLdouble frame_array[SAMPLE];
	GLdouble frametime=curr_time-previous_time;
	frame_array[sample_count++ % SAMPLE]=frametime;
	
	previous_time=curr_time;
	if(sample_count<SAMPLE)
		avg_count=sample_count;
	else
		avg_count=SAMPLE;
	for(GLint i=0;i<avg_count;i++)
	{
		frame_avg_time+=frame_array[i];
	}
	frame_avg_time/=avg_count;
	frame_avg_time*=1000;
	if(c_frame==10){
	cout<<(1000/frame_avg_time)<<endl;
	c_frame=0;
	}
}
void keycallback(GLFWwindow* _window,int key,int scan,int action,int mode)
	{
		if(key==GLFW_KEY_W)
			Scene1.MyCamera.MoveUp();
		if(key==GLFW_KEY_S)
			Scene1.MyCamera.MoveDown();
		if(key==GLFW_KEY_A)
			Scene1.MyCamera.MoveLeft();
		if(key==GLFW_KEY_D)
			Scene1.MyCamera.MoveRight();
		if(key==GLFW_KEY_Z)
			Scene1.MyCamera.Zoom();
	}