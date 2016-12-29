#include "ResourceManager.h"
//A static member should be declared outside class
ResourceManager* ResourceManager::Instance;
GLint ResourceManager::texture_count;
GLenum ResourceManager::Active_Textures[10];
ResourceManager::ResourceManager(void)
{

}



ResourceManager* ResourceManager::GetInstance()
{
	//Always return same object if try to create one OR create one if there is no object previously
	if(Instance==nullptr)
	{
		Instance=new ResourceManager();
		texture_count=0;
		Start();
	}
	return Instance;
	
}
Shaders ResourceManager::LoadShaders(const GLchar* vertfile,const GLchar* fragfile)
{
	ifstream vertstream,fragstream;
	stringstream Vert_String_Stream,Frag_String_Stream;
	string v_String,f_String;
	const GLchar*final_vert_str,*final_frag_str;
	vertstream.exceptions(ifstream::failbit|ifstream::badbit);
	fragstream.exceptions(ifstream::failbit|ifstream::badbit);
	try{
	vertstream.open(vertfile);
	Vert_String_Stream<<vertstream.rdbuf();
	v_String=Vert_String_Stream.str();
	vertstream.close();
	}
	catch(ifstream::failure e)
	{
		cout<<"Error Reading file\n";
		system("pause");
	}
	cout<<"Vertex shader read Successfully\n";
	try{
	fragstream.open(fragfile);
	Frag_String_Stream<<fragstream.rdbuf();
	f_String=Frag_String_Stream.str();
	fragstream.close();
	}
	catch(ifstream::failure e)
	{
		cout<<"Error Reading file\n";
		system("pause");
	}
	cout<<"Fragment shader read Successfully\n";
	final_vert_str=v_String.c_str();
	final_frag_str=f_String.c_str();
	Shaders newshader(final_vert_str,final_frag_str);
	return newshader;

}
unsigned char* ResourceManager::LoadTexture(const GLchar* textureloc,GLint &width,GLint &height,GLint &n)
{//int T_width,T_height,T_n;
unsigned char* image=stbi_load(textureloc,&width,&height,&n,0);
	if(image!=NULL)
		cout<<"Texture Loaded SUccessfully\n";
	else
		cout<<"Textutre Loading Failed!!!!\n";
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
GLint ResourceManager::Get_Texture_Count()
{
	return texture_count;
}
void ResourceManager::Set_Texture_Count()
{
	++texture_count;
}

void ResourceManager::Start()
{
	Set_ActiveTexture_Map();
}
void ResourceManager:: Set_ActiveTexture_Map()
{
	Active_Textures[0]=GL_TEXTURE0;
	Active_Textures[1]=GL_TEXTURE1;
	Active_Textures[2]=GL_TEXTURE2;
	Active_Textures[3]=GL_TEXTURE3;
	Active_Textures[4]=GL_TEXTURE4;
	Active_Textures[5]=GL_TEXTURE5;
	Active_Textures[6]=GL_TEXTURE6;
	Active_Textures[7]=GL_TEXTURE7;
	Active_Textures[8]=GL_TEXTURE8;
	Active_Textures[9]=GL_TEXTURE9;
	Active_Textures[10]=GL_TEXTURE10;
}
GLenum ResourceManager::Get_ActiveTexture_Map(GLint num)
{
	return Active_Textures[num];
}