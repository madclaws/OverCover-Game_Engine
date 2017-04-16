#include "Window.h"

namespace OverCover2D {
	Window* winusrs;
	GUI* gui_amp;
	void keycallback(GLFWwindow*, GLint, GLint, GLint, GLint);
	void scrollcallback(GLFWwindow*, GLdouble, GLdouble);
	void windowClosecallback(GLFWwindow*);
	void cursorposcallback(GLFWwindow*, GLdouble, GLdouble);
	void mousebuttoncallback(GLFWwindow*, int, int, int);
	void charcallback(GLFWwindow*, unsigned int);
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
		glfwWindow = glfwCreateWindow(_screenwidth, _screenheight, windowName, 0, 0);

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
		glfwSetWindowUserPointer(glfwWindow, this);
		glfwSetFramebufferSizeCallback(glfwWindow, framebufcallback);
		glfwSetKeyCallback(glfwWindow, keycallback);
		glfwSetScrollCallback(glfwWindow, scrollcallback);
		glfwSetWindowCloseCallback(glfwWindow, windowClosecallback);
		glfwSetCursorPosCallback(glfwWindow, cursorposcallback);
		glfwSetMouseButtonCallback(glfwWindow, mousebuttoncallback);
		glfwSetCharCallback(glfwWindow, charcallback);
		glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		//Setting Default Viewport
		glViewport(0, 0, _screenwidth, _screenheight);
		inputmanager = InputManager::GetInstance();
		//Initializing GUI
		GUIinit();
	}
	void Window::pollEvents()
	{
		glfwPollEvents();

	}
	void Window::GUIdraw()
	{
		gui.draw();
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
	void Window::GUIinit()
	{
		try {
			gui.init("GUI");
			gui.loadScheme("TaharezLook.scheme");
			gui.setFont("DejaVuSans-10");
			//pointer to the gui variable
			//can't use friend function as callback
			gui_amp = &gui;
			CEGUI::PushButton* testbtn = static_cast<CEGUI::PushButton*>(gui.createWidget("TaharezLook/Button", "testButton", glm::vec4(0.5f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f)));
			testbtn->setText("Hello world");
			CEGUI::Combobox* combobtn = static_cast<CEGUI::Combobox*>(gui.createWidget("TaharezLook/Combobox", "combobtn", glm::vec4(0.2f, 0.2f, 0.1f, 0.05f), glm::vec4(0.0f)));
			gui.setMouseCursor("TaharezLook/MouseArrow");
			gui.showCursor();
		}
		catch(std::exception e)
		{
			std::cout << "not worked";
		}
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
			gui_amp->onGlfwEvents(GlfwEvents::KEYDOWN, key);
		}
		else if (action == GLFW_RELEASE)
		{
			winusrptr->inputmanager->KeyRelease(key);
			gui_amp->onGlfwEvents(GlfwEvents::KEYUP, key);
		}

	}
	void scrollcallback(GLFWwindow* window, GLdouble xscroll, GLdouble yscroll)
	{
		Window* winusrptr = (Window*)glfwGetWindowUserPointer(window);
		winusrptr->inputmanager->SetYscroll(yscroll);
	}
	void cursorposcallback(GLFWwindow* _window, GLdouble _x, GLdouble _y)
	{
		winusrs= (Window*)glfwGetWindowUserPointer(_window);
		winusrs->inputmanager->setMouseCoords(_x, _y);
		//std::cout << "\n" << _x << "\t" << _y;
		gui_amp->onGlfwEvents(_x, _y);
		

	}
	void mousebuttoncallback(GLFWwindow* _window, int button, int action, int mods)
	{
		winusrs = (Window*)glfwGetWindowUserPointer(_window);
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			winusrs->inputmanager->KeyPress(button);
			gui_amp->onGlfwEvents(GlfwEvents::MOUSEBUTTONDWN, button);
		}
		else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		{
			winusrs->inputmanager->KeyRelease(button);
			gui_amp->onGlfwEvents(GlfwEvents::MOUSEBUTTONUP, button);
		}
	}
	void charcallback(GLFWwindow* _window, unsigned int codepoint)
	{
		gui_amp->onGlfwEvents(GlfwEvents::TEXTINPUT, codepoint);
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
	glm::vec2 Window::returnScreenCoords()
	{
		return inputmanager->getMouseCoords();
	}
	glm::vec2 Window::returnWorldCoords()
	{
		glm::vec2 temp_coords= inputmanager->getMouseCoords();
		temp_coords.x -= (GLfloat)screenWidth / 2;
		temp_coords.y -= (GLfloat)screenHeight / 2;
		return temp_coords;
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
}

