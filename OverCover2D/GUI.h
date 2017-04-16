#pragma once

#include<CEGUI\CEGUI.h>
#include<CEGUI\RendererModules\OpenGL\GL3Renderer.h>
#include<glm\glm.hpp>
#include<GLFW\glfw3.h>
#include<iostream>
namespace OverCover2D {

	 enum GlfwEvents {
		MOUSE_MOTION,
		KEYDOWN,
		KEYUP,
		MOUSEBUTTONDWN,
		MOUSEBUTTONUP,
		TEXTINPUT
	};
	class GUI
	{
		static CEGUI::OpenGL3Renderer* renderer;
		CEGUI::GUIContext* context;
		CEGUI::Window* m_Root;
	public:
		GUI();
		//static CEGUI::OpenGL3Renderer* getRenderer{ return renderer; }
		//static CEGUI::GUIContext* getContext{ return context; }
		void loadScheme(const std::string&);
		void setFont(const std::string&);
		void setMouseCursor(const std::string&);
		void showCursor();
		void hideCursor();
		void onGlfwEvents(GLdouble, GLdouble);
		void onGlfwEvents(GlfwEvents, GLint);
		//void onGlfwEvents(GlfwEvents, GLint);
		static void setWidgetRect(CEGUI::Window*, glm::vec4, glm::vec4);
		CEGUI::Window* createWidget(const std::string&, const std::string&,glm::vec4,glm::vec4);
		void init(const std::string&);
		void draw();
		void destroy();
		~GUI();
	};
}

