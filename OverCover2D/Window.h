#pragma once
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include"InputManager.h"
#include"Camera2D.h"
class Window
{
	GLFWwindow* glfwWindow;
	int screenHeight, screenWidth;
	
	
public:
	Window();
	InputManager* inputmanager;
	bool WIN_STATE;
	void create(GLchar*,int,int,bool);
	void pollEvents();
	void swapBuffer();
	void swapInterval();
	void Terminate();
	int getScreenWidth();
	int getScreenHeight();
	bool winState();
	//void eventHandler();
	GLboolean winKeyPressed(GLint);
	//friend void windowClosecallback(GLFWwindow*,);
	~Window();
};
