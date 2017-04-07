#include "InputManager.h"
namespace OverCover2D {
	InputManager* InputManager::IOinstance;
	GLfloat InputManager::Yscroll;
	InputManager::InputManager(void)
	{
	}


	InputManager::~InputManager(void)
	{
	}
	InputManager* InputManager::GetInstance()
	{
		if (IOinstance == nullptr)
		{
			IOinstance = new InputManager();
			Yscroll = 0.0f;
		}
		return IOinstance;
	}
	void InputManager::KeyPress(GLuint currentkey)
	{
		KeyMap[currentkey] = GL_TRUE;
	}
	void InputManager::KeyRelease(GLuint currentkey)
	{
		KeyMap[currentkey] = GL_FALSE;
	}
	GLboolean InputManager::IsKeyPressed(GLuint currentkey)
	{
		auto keyiter = KeyMap.find(currentkey);
		if (keyiter == KeyMap.end())
			return GL_FALSE;
		return keyiter->second;
	}
	void InputManager::SetYscroll(GLfloat yscroll)
	{
		if (Yscroll >= 25.0f)
			Yscroll = 24.0f;
		else
			Yscroll += yscroll;
	}
	GLfloat InputManager::GetYscroll()
	{
		return Yscroll;
	}
	void InputManager::setMouseCoords(GLdouble _x, GLdouble _y)
	{
		mouseCoords.x = (GLfloat)_x;
		mouseCoords.y = (GLfloat)_y;
	}
}

