#pragma once
#define GLEW_STATIC
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<iostream>
#include<glm\glm.hpp>
#include"InputManager.h"
#include"Camera2D.h"
#include "GUI.h"
namespace OverCover2D {

	class Window
	{
		GLFWwindow* glfwWindow;
		int screenHeight, screenWidth;
		GUI gui;

	public:
		Window();
		InputManager* inputmanager;
		bool WIN_STATE;
		void create(GLchar*, int, int, bool);
		void pollEvents();
		void swapBuffer();
		void swapInterval();
		void Terminate();
		int getScreenWidth();
		int getScreenHeight();
		void GUIinit();
		void GUIdraw();
		bool winState();
		//void eventHandler();
		GLboolean winKeyPressed(GLint);
		glm::vec2 returnScreenCoords();
		glm::vec2 returnWorldCoords();
		
		//friend void windowClosecallback(GLFWwindow*,);
		~Window();
	};
}

