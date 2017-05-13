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
		//glDisable(GL_SCISSOR_TEST);
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
	void GUI::onGlfwEvents(GLdouble _x, GLdouble _y)
	{
		context->injectMousePosition(_x, _y);
		
	}
	CEGUI::Key::Scan GlfwToCeguiKey(int glfwKey)
	{
		switch (glfwKey)
		{
		case GLFW_KEY_UNKNOWN: return CEGUI::Key::Unknown;
		case GLFW_KEY_ESCAPE: return CEGUI::Key::Escape;
		case GLFW_KEY_F1: return CEGUI::Key::F1;
		case GLFW_KEY_F2: return CEGUI::Key::F2;
		case GLFW_KEY_F3: return CEGUI::Key::F3;
		case GLFW_KEY_F4: return CEGUI::Key::F4;
		case GLFW_KEY_F5: return CEGUI::Key::F5;
		case GLFW_KEY_F6: return CEGUI::Key::F6;
		case GLFW_KEY_F7: return CEGUI::Key::F7;
		case GLFW_KEY_F8: return CEGUI::Key::F8;
		case GLFW_KEY_F9: return CEGUI::Key::F9;
		case GLFW_KEY_F10: return CEGUI::Key::F10;
		case GLFW_KEY_F11: return CEGUI::Key::F11;
		case GLFW_KEY_F12: return CEGUI::Key::F12;
		case GLFW_KEY_F13: return CEGUI::Key::F13;
		case GLFW_KEY_F14: return CEGUI::Key::F14;
		case GLFW_KEY_F15: return CEGUI::Key::F15;
		case GLFW_KEY_UP: return CEGUI::Key::ArrowUp;
		case GLFW_KEY_DOWN: return CEGUI::Key::ArrowDown;
		case GLFW_KEY_LEFT: return CEGUI::Key::ArrowLeft;
		case GLFW_KEY_RIGHT: return CEGUI::Key::ArrowRight;
		case GLFW_KEY_LEFT_SHIFT: return CEGUI::Key::LeftShift;
		case GLFW_KEY_RIGHT_SHIFT: return CEGUI::Key::RightShift;
		case GLFW_KEY_LEFT_CONTROL: return CEGUI::Key::LeftControl;
		case GLFW_KEY_RIGHT_CONTROL: return CEGUI::Key::RightControl;
		case GLFW_KEY_LEFT_ALT: return CEGUI::Key::LeftAlt;
		case GLFW_KEY_RIGHT_ALT: return CEGUI::Key::RightAlt;
		case GLFW_KEY_TAB: return CEGUI::Key::Tab;
		case GLFW_KEY_ENTER: return CEGUI::Key::Return;
		case GLFW_KEY_BACKSPACE: return CEGUI::Key::Backspace;
		case GLFW_KEY_INSERT: return CEGUI::Key::Insert;
		case GLFW_KEY_DELETE: return CEGUI::Key::Delete;
		case GLFW_KEY_PAGE_UP: return CEGUI::Key::PageUp;
		case GLFW_KEY_PAGE_DOWN: return CEGUI::Key::PageDown;
		case GLFW_KEY_HOME: return CEGUI::Key::Home;
		case GLFW_KEY_END: return CEGUI::Key::End;
		case GLFW_KEY_NUM_LOCK: return CEGUI::Key::NumLock;
		case GLFW_KEY_KP_ENTER: return CEGUI::Key::NumpadEnter;

		default: return CEGUI::Key::Unknown;
		}
	}

	CEGUI::Key::Scan GlfwToCeguiKeyScan(int glfwKey) {
		switch (glfwKey) {
		case GLFW_KEY_UNKNOWN: return CEGUI::Key::Unknown;
		case GLFW_KEY_A: return CEGUI::Key::A;
		case GLFW_KEY_B: return CEGUI::Key::B;
		case GLFW_KEY_C: return CEGUI::Key::C;
		case GLFW_KEY_D: return CEGUI::Key::D;
		case GLFW_KEY_E: return CEGUI::Key::E;
		case GLFW_KEY_F: return CEGUI::Key::F;
		case GLFW_KEY_G: return CEGUI::Key::G;
		case GLFW_KEY_H: return CEGUI::Key::H;
		case GLFW_KEY_I: return CEGUI::Key::I;
		case GLFW_KEY_J: return CEGUI::Key::J;
		case GLFW_KEY_K: return CEGUI::Key::K;
		case GLFW_KEY_L: return CEGUI::Key::L;
		case GLFW_KEY_M: return CEGUI::Key::M;
			/* Char Ñ in Spanish-Keyboard */
		case GLFW_KEY_SEMICOLON: return CEGUI::Key::Semicolon;
		case GLFW_KEY_N: return CEGUI::Key::N;
		case GLFW_KEY_O: return CEGUI::Key::O;
		case GLFW_KEY_P: return CEGUI::Key::P;
		case GLFW_KEY_Q: return CEGUI::Key::Q;
		case GLFW_KEY_R: return CEGUI::Key::R;
		case GLFW_KEY_S: return CEGUI::Key::S;
		case GLFW_KEY_T: return CEGUI::Key::T;
		case GLFW_KEY_U: return CEGUI::Key::U;
		case GLFW_KEY_V: return CEGUI::Key::V;
		case GLFW_KEY_W: return CEGUI::Key::W;
		case GLFW_KEY_X: return CEGUI::Key::X;
		case GLFW_KEY_Y: return CEGUI::Key::Y;
		case GLFW_KEY_Z: return CEGUI::Key::Z;
		case GLFW_KEY_0: return CEGUI::Key::Zero;
		case GLFW_KEY_1: return CEGUI::Key::One;
		case GLFW_KEY_2: return CEGUI::Key::Two;
		case GLFW_KEY_3: return CEGUI::Key::Three;
		case GLFW_KEY_4: return CEGUI::Key::Four;
		case GLFW_KEY_5: return CEGUI::Key::Five;
		case GLFW_KEY_6: return CEGUI::Key::Six;
		case GLFW_KEY_7: return CEGUI::Key::Seven;
		case GLFW_KEY_8: return CEGUI::Key::Eight;
		case GLFW_KEY_9: return CEGUI::Key::Nine;
		case GLFW_KEY_KP_0: return CEGUI::Key::Zero;
		case GLFW_KEY_KP_1: return CEGUI::Key::One;
		case GLFW_KEY_KP_2: return CEGUI::Key::Two;
		case GLFW_KEY_KP_3: return CEGUI::Key::Three;
		case GLFW_KEY_KP_4: return CEGUI::Key::Four;
		case GLFW_KEY_KP_5: return CEGUI::Key::Five;
		case GLFW_KEY_KP_6: return CEGUI::Key::Six;
		case GLFW_KEY_KP_7: return CEGUI::Key::Seven;
		case GLFW_KEY_KP_8: return CEGUI::Key::Eight;
		case GLFW_KEY_KP_9: return CEGUI::Key::Nine;
		case GLFW_KEY_KP_ADD: return CEGUI::Key::Add;
		case GLFW_KEY_KP_DECIMAL: return CEGUI::Key::Decimal;
		case GLFW_KEY_KP_DIVIDE: return CEGUI::Key::Divide;
		case GLFW_KEY_KP_EQUAL: return CEGUI::Key::NumpadEquals;
		case GLFW_KEY_KP_MULTIPLY: return CEGUI::Key::Multiply;
		case GLFW_KEY_KP_SUBTRACT: return CEGUI::Key::Subtract;
		case GLFW_KEY_APOSTROPHE: return CEGUI::Key::Apostrophe;
		case GLFW_KEY_COMMA: return CEGUI::Key::Comma;
		case GLFW_KEY_EQUAL: return CEGUI::Key::Equals;
		case GLFW_KEY_PERIOD: return CEGUI::Key::Period;
		case GLFW_KEY_GRAVE_ACCENT: return CEGUI::Key::Grave;
		case GLFW_KEY_LEFT_BRACKET: return CEGUI::Key::LeftBracket;
		case GLFW_KEY_BACKSLASH: return CEGUI::Key::Backslash;
		case GLFW_KEY_RIGHT_BRACKET: return CEGUI::Key::RightBracket;
		case GLFW_KEY_MINUS: return CEGUI::Key::Minus;
		case GLFW_KEY_SLASH: return CEGUI::Key::Slash;
		case GLFW_KEY_SPACE: return CEGUI::Key::Space;
		case GLFW_KEY_WORLD_1: return CEGUI::Key::Unknown;
		case GLFW_KEY_WORLD_2: return CEGUI::Key::Unknown;

		default: return CEGUI::Key::Unknown;
		}
	}

	CEGUI::MouseButton GlfwToCeguiButton(int glfwButton)
	{
		switch (glfwButton)
		{
		case GLFW_MOUSE_BUTTON_LEFT: return CEGUI::LeftButton;
		case GLFW_MOUSE_BUTTON_RIGHT: return CEGUI::RightButton;
		case GLFW_MOUSE_BUTTON_MIDDLE: return CEGUI::MiddleButton;
		default: return CEGUI::NoButton;
		}
	}
	CEGUI::utf32 keycodeToUTF32(unsigned int scanCode)
	{
		CEGUI::utf32 utf = 0;

		BYTE keyboardState[256];
		unsigned char ucBuffer[3];
		static WCHAR deadKey = '\0';

		// Retrieve the keyboard layout in order to perform the necessary convertions
		HKL hklKeyboardLayout = GetKeyboardLayout(0); // 0 means current thread 
													  // This seemingly cannot fail 
													  // If this value is cached then the application must respond to WM_INPUTLANGCHANGE 

													  // Retrieve the keyboard state
													  // Handles CAPS-lock and SHIFT states
		if (GetKeyboardState(keyboardState) == FALSE)
			return utf;

		UINT virtualKey = MapVirtualKeyEx(scanCode, 3, hklKeyboardLayout);
		if (virtualKey == 0) // No translation possible
			return utf;

		int ascii = ToAsciiEx(virtualKey, scanCode, keyboardState, (LPWORD)ucBuffer, 0, hklKeyboardLayout);
		if (deadKey != '\0' && ascii == 1)
		{
			// A dead key is stored and we have just converted a character key
			// Combine the two into a single character
			WCHAR wcBuffer[3];
			WCHAR out[3];
			wcBuffer[0] = ucBuffer[0];
			wcBuffer[1] = deadKey;
			wcBuffer[2] = '\0';
			if (FoldStringW(MAP_PRECOMPOSED, (LPWSTR)wcBuffer, 3, (LPWSTR)out, 3))
				utf = out[0];
			else
			{
				// FoldStringW failed
				DWORD dw = GetLastError();
				switch (dw)
				{
				case ERROR_INSUFFICIENT_BUFFER:
				case ERROR_INVALID_FLAGS:
				case ERROR_INVALID_PARAMETER:
					break;
				}
			}
			deadKey = '\0';
		}
		else if (ascii == 1)
		{
			// We have a single character
			utf = ucBuffer[0];
			deadKey = '\0';
		}
		else
		{
			// Convert a non-combining diacritical mark into a combining diacritical mark
			switch (ucBuffer[0])
			{
			case 0x5E: // Circumflex accent: â
				deadKey = 0x302;
				break;
			case 0x60: // Grave accent: à
				deadKey = 0x300;
				break;
			case 0xA8: // Diaeresis: ü
				deadKey = 0x308;
				break;
			case 0xB4: // Acute accent: é
				deadKey = 0x301;
				break;
			case 0xB8: // Cedilla: ç
				deadKey = 0x327;
				break;
			default:
				deadKey = ucBuffer[0];
			}
		}

		return utf;
	}
	void GUI::onGlfwEvents(GlfwEvents eventstate, GLint keycode)
	{
		
		switch (eventstate)
		{
		case GlfwEvents::KEYUP:context->injectKeyUp(GlfwToCeguiKey(keycode));
			break;
		case GlfwEvents::KEYDOWN:context->injectKeyDown(GlfwToCeguiKey(keycode));
			break;
		case GlfwEvents::MOUSEBUTTONDWN:context->injectMouseButtonDown(GlfwToCeguiButton(keycode));
			break;
		case GlfwEvents::MOUSEBUTTONUP:context->injectMouseButtonUp(GlfwToCeguiButton(keycode));
			break;
		case GlfwEvents::TEXTINPUT:context->injectChar(keycodeToUTF32(GlfwToCeguiKeyScan(keycode)));
			break;
		default:printf("default");
			break;
		}
	}
	void GUI::destroy()
	{
		CEGUI::System::getSingleton().destroyGUIContext(*context);
	}

	GUI::~GUI()
	{

	}
}
