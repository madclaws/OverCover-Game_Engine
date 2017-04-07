#pragma once
#include<GL\glew.h>
#include<glm\glm.hpp>
#include<unordered_map>
namespace OverCover2D {
	class InputManager
	{
		std::unordered_map<GLuint, GLboolean> KeyMap;
		static GLfloat Yscroll;
		glm::vec2 mouseCoords;
		InputManager(void);
		~InputManager(void);
		static InputManager* IOinstance;

	public:
		static InputManager* GetInstance();
		void setMouseCoords(GLdouble, GLdouble);
		glm::vec2 getMouseCoords() { return mouseCoords; }
		void KeyPress(GLuint);
		void KeyRelease(GLuint);
		GLboolean IsKeyPressed(GLuint);
		void SetYscroll(GLfloat);
		GLfloat GetYscroll();

	};
}

