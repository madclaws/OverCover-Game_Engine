#include "Texture2D.h"


Texture2D::Texture2D(const GLchar* univar):Texture_ID(0),Width(0),Height(0),Wrapper_S(GL_REPEAT),Wrapper_T(GL_REPEAT),
	Min_Filter(GL_LINEAR),Mag_Filter(GL_LINEAR),Min_FIlter_Minmap(GL_NEAREST_MIPMAP_NEAREST),
	Internal_Format(GL_RGB),Load_Format(GL_RGB),uniform_var_string(univar)
{
	ResourceManager::GetInstance()->Set_Texture_Count();
}

void Texture2D::Generate(const GLchar* Filename)
{ResourceManager* inst=ResourceManager::GetInstance();
	int n;
	unsigned char* image;
	glGenTextures(1,&Texture_ID);
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,Wrapper_S);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,Wrapper_T);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,Min_Filter);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,Mag_Filter);
	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,Min_FIlter_Minmap);
	image=inst->LoadTexture(Filename,Width,Height,n);
	glTexImage2D(GL_TEXTURE_2D,0,Internal_Format,Width,Height,0,Load_Format,GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D,0);
	
}
void Texture2D::Bind()
{
	
	glBindTexture(GL_TEXTURE_2D,Texture_ID);
}
const GLchar* Texture2D::uni_var_str()
{
	return uniform_var_string;
}
Texture2D::~Texture2D(void)
{

}
