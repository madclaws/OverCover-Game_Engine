#include "ResourceManager.h"
//A static member should be declared outside class
ResourceManager* ResourceManager::Instance;


ResourceManager::ResourceManager(void)
{

}



ResourceManager* ResourceManager::GetInstance()
{
	//Always return same object if try to create one OR create one if there is no object previously
	if(Instance==nullptr)
	{
		Instance=new ResourceManager();
	}
	return Instance;
	
}
Shaders ResourceManager::LoadShaders(const GLchar* vertfile,const GLchar* fragfile)
{
	ifstream vertstream,fragstream;
	stringstream Vert_String_Stream,Frag_String_Stream;
	string v_String,f_String;
	const GLchar*final_vert_str,*final_frag_str;
	vertstream.open(vertfile);
	Vert_String_Stream<<vertstream.rdbuf();
	v_String=Vert_String_Stream.str();
	vertstream.close();
	fragstream.open(fragfile);
	Frag_String_Stream<<fragstream.rdbuf();
	f_String=Frag_String_Stream.str();
	final_vert_str=v_String.c_str();
	final_frag_str=f_String.c_str();
	Shaders newshader(final_vert_str,final_frag_str);
	return newshader;

}
unsigned char* ResourceManager::LoadTexture(const GLchar* textureloc,GLint &width,GLint &height,GLint &n)
{
	unsigned char* image=stbi_load("filename",&width,&height,&n,0);
	return image;
	//stbi_image_free(image);
}
void ResourceManager::clear(GLuint& v_id,GLuint& f_id)
{
	glDeleteShader(v_id);
	glDeleteShader(f_id);

}
void ResourceManager::clear(unsigned char* image)
{
	stbi_image_free(image);
}
ResourceManager::~ResourceManager(void)
{

}