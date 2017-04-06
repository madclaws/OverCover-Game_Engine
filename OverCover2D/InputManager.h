#pragma once
#include<GL\glew.h>
#include<unordered_map>
namespace OverCover2D {
	class InputManager
	{
		std::unordered_map<GLuint, GLboolean> KeyMap;
		static GLfloat Yscroll;
		InputManager(void);
		~InputManager(void);
		static InputManager* IOinstance;

	public:
		static InputManager* GetInstance();
		void KeyPress(GLuint);
		void KeyRelease(GLuint);
		GLboolean IsKeyPressed(GLuint);
		void SetYscroll(GLfloat);
		GLfloat GetYscroll();

	};
}

