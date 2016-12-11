#include "Texture2D.h"


Texture2D::Texture2D(void):Texture_ID(0),Width(0),Height(0),Wrapper_S(GL_REPEAT),Wrapper_T(GL_REPEAT),
	Min_Filter(GL_NEAREST),Mag_Filter(GL_LINEAR),Min_FIlter_Minmap(GL_NEAREST_MIPMAP_NEAREST),
	Internal_Format(GL_RGB),Load_Format(GL_RGB)
{
	glGenTextures(1,&Texture_ID);
}

void Texture2D::Generate()
{
	int n;
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,Wrapper_S);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,Wrapper_T);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,Min_Filter);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,Mag_Filter);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,Min_FIlter_Minmap);
	unsigned char* image=stbi_load("filename",&Width,&Height,&n,0);
	glTexImage2D(GL_TEXTURE_2D,0,Internal_Format,Width,Height,0,Load_Format,GL_UNSIGNED_BYTE,&image);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(image);
	glBindTexture(GL_TEXTURE_2D,0);
	
}
void Texture2D::Bind()
{
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
}
Texture2D::~Texture2D(void)
{

}
