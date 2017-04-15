#pragma once
#include<CEGUI\CEGUI.h>
#include<CEGUI\RendererModules\OpenGL\GL3Renderer.h>
#include<glm\glm.hpp>
namespace OverCover2D {

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
		static void setWidgetRect(CEGUI::Window*, glm::vec4, glm::vec4);
		CEGUI::Window* createWidget(const std::string&, const std::string&,glm::vec4,glm::vec4);
		void init(const std::string&);
		void draw();
		void destroy();
		~GUI();
	};
}

