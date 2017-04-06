#pragma once
//Stores Texture Location,Width,Height for Texture Caching.
//We need this because when trying to load the previously stored image data we forget to chaange ,
//textures width and height

#include<GL\glew.h>
namespace OverCover2D {
	struct ImageData
	{
		unsigned char* FILELOC;
		GLint WIDTH;
		GLint HEIGHT;
		void FillData(unsigned char*, GLint, GLint);

	};
}
