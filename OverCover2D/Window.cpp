#include "Window.h"


void keycallback(GLFWwindow*, GLint, GLint, GLint, GLint);
void scrollcallback(GLFWwindow*, GLdouble, GLdouble);
void windowClosecallback(GLFWwindow*);
void framebufcallback(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
}
Window::Window()
{
	
}

void Window::create(GLchar* windowName, int _screenwidth, int _screenheight, bool _state)
{

	if (_state)
	WIN_STATE = true;
	else
	WIN_STATE = false;

	//Window* winUserptr;
	screenHeight = _screenheight;
	screenWidth = _screenwidth;
	if (!glfwInit())
	{
		std::cout << "GLFW INITIALIZATION FAILED.............\n";
		exit(0);
	}
	std::cout << "GLFW INITIALIZATION SUCESS.............\n";
	//Configuring Window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	//Creating Window
	 glfwWindow = glfwCreateWindow(_screenwidth,_screenheight, windowName, 0, 0);

	//Making Context to Current Window
	glfwMakeContextCurrent(glfwWindow);
	//Calls When glclear calls
	//glClearColor(0.0f,0.0f,0.0f,1.0f);
	//Glew initialization for USING OPENGL FUNCTIONS
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW INITIALIZATION FAILED................\n";
		exit(0);
	}
	std::cout << "GLEW INITIALIZATION SUCESS.............\n";
	//Creating new Scene

	//Callback for resizing the window viewport
	glfwSetWindowUserPointer(glfwWindow,this);
	glfwSetFramebufferSizeCallback(glfwWindow, framebufcallback);
	glfwSetKeyCallback(glfwWindow, keycallback);
	glfwSetScrollCallback(glfwWindow, scrollcallback);
	glfwSetWindowCloseCallback(glfwWindow, windowClosecallback);
	//Setting Default Viewport
	glViewport(0, 0,_screenwidth,_screenheight);
	inputmanager = InputManager::GetInstance();
}
void Window::pollEvents()
{
	glfwPollEvents();

}
void Window::swapBuffer()
{
	glfwSwapBuffers(glfwWindow);
}
void Window::swapInterval()
{
	glfwSwapInterval(1);
}
void Window::Terminate()
{
	glfwTerminate();
}
Window::~Window()
{
}
void windowClosecallback(GLFWwindow* _window)
{
	Window* winusrptr = (Window*)glfwGetWindowUserPointer(_window);
	winusrptr->WIN_STATE = false;

}
void keycallback(GLFWwindow* _window, GLint key, GLint scan, GLint action, GLint mode)
{
	Window* winusrptr = (Window*)glfwGetWindowUserPointer(_window);
	if (action == GLFW_PRESS)
	{
		winusrptr->inputmanager->KeyPress(key);
	}
	else if (action == GLFW_RELEASE)
	{
		winusrptr->inputmanager->KeyRelease(key);
	}

}
void scrollcallback(GLFWwindow* window, GLdouble xscroll, GLdouble yscroll)
{
	Window* winusrptr = (Window*)glfwGetWindowUserPointer(window);
	winusrptr->inputmanager->SetYscroll(yscroll);
}
int Window::getScreenHeight()
{
	return screenHeight;
}
int Window::getScreenWidth()
{
	return screenWidth;
}
bool Window::winState()
{
	return WIN_STATE;
}
GLboolean Window::winKeyPressed(GLint key)
{
	if (inputmanager->IsKeyPressed(key))
		return GL_TRUE;
	return GL_FALSE;
}
/*void Window::eventHandler()
{
	std::cout << "KEYHANDLER";
		if (inputmanager->IsKeyPressed(GLFW_KEY_W))
			MyCamera.MoveUp();
		if (inputmanager->IsKeyPressed(GLFW_KEY_S))
			MyCamera.MoveDown();
		if (inputmanager->IsKeyPressed(GLFW_KEY_A))
			MyCamera.MoveLeft();
		if (inputmanager->IsKeyPressed(GLFW_KEY_D))
			MyCamera.MoveRight();

	
}*/
