#include "GUI.h"

namespace OverCover2D {
	CEGUI::OpenGL3Renderer* GUI::renderer = nullptr;

	GUI::GUI()
	{

	}

	void GUI::init(const std::string& UI_folderName)
	{
		if (renderer == nullptr)
		{
			renderer = &CEGUI::OpenGL3Renderer::bootstrapSystem();
	CEGUI::DefaultResourceProvider*res_prov =static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
	res_prov->setResourceGroupDirectory("imagesets", UI_folderName + "/imagesets/");
	res_prov->setResourceGroupDirectory("schemes", UI_folderName + "/schemes/");
	res_prov->setResourceGroupDirectory("fonts", UI_folderName + "/fonts/");
	res_prov->setResourceGroupDirectory("looknfeel", UI_folderName + "/looknfeel/");
	res_prov->setResourceGroupDirectory("layouts", UI_folderName + "/layouts/");
	res_prov->setResourceGroupDirectory("lua_scripts", UI_folderName + "/lua_scripts/");
			
	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	CEGUI::Scheme::setDefaultResourceGroup("schemes");
	CEGUI::Font::setDefaultResourceGroup("fonts");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeel");
	CEGUI::WindowManager::setDefaultResourceGroup("layouts");
	CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");
		}
		context = &CEGUI::System::getSingleton().createGUIContext(renderer->getDefaultRenderTarget());
		m_Root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "ROOT");
		context->setRootWindow(m_Root);
	}

	void GUI::draw()
	{
		renderer->beginRendering();
		context->draw();
		renderer->endRendering();
		glDisable(GL_SCISSOR_TEST);
	}
	void GUI::loadScheme(const std::string& file)
	{
		CEGUI::SchemeManager::getSingleton().createFromFile(file);
	}
	void GUI::setFont(const std::string& font)
	{
		CEGUI::FontManager::getSingleton().createFromFile(font+".font");
		context->setDefaultFont(font);
	}
	
	CEGUI::Window* GUI::createWidget(const std::string& type, const std::string& name,glm::vec4 perc,glm::vec4 pix)
	{
		CEGUI::Window* temp_window = CEGUI::WindowManager::getSingleton().createWindow(type, name);
		m_Root->addChild(temp_window);

		setWidgetRect(temp_window, perc, pix);
		return temp_window;
	}
	void GUI::setWidgetRect(CEGUI::Window* _window, glm::vec4 _perc, glm::vec4 _pix)
	{
		_window->setPosition(CEGUI::UVector2(CEGUI::UDim(_perc.x, _pix.x), CEGUI::UDim(_perc.x, _pix.y)));
		_window->setSize(CEGUI::USize(CEGUI::UDim(_perc.z, _pix.z), CEGUI::UDim(_perc.w, _pix.w)));

	}
	void GUI::setMouseCursor(const std::string& m_type)
	{
		context->getMouseCursor().setDefaultImage(m_type);
	}
	void GUI::showCursor()
	{
		context->getMouseCursor().show();

	}
	void GUI::hideCursor()
	{
		context->getMouseCursor().hide();
	}
	void GUI::destroy()
	{
		CEGUI::System::getSingleton().destroyGUIContext(*context);
	}

	GUI::~GUI()
	{

	}
}
