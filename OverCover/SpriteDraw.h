#pragma once
#include "draw_interface.h"
#include <cstddef>
#include "Texture2D.h"
#include<GL\glew.h>
class SpriteDraw :public Draw_Interface
{
public:
	void Draw(GLuint&,Texture2D&);
};

