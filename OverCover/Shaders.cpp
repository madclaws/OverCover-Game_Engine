#include "Shaders.h"


Shaders::Shaders(const GLchar* vert_source,const GLchar* frag_source)
{
	//...........Initializing variables....................................................
	GLuint VertexID,FragmentID;				
	GLint sucess;							
	GLchar infolog[512];					
	//............ COMPILING FRAGMENT SHADER ....................................................										
	VertexID=glCreateShader(GL_VERTEX_SHADER);	
	glShaderSource(VertexID,1,&vert_source,0);	
	glCompileShader(VertexID);					
	glGetShaderiv(VertexID,GL_COMPILE_STATUS,&sucess);	
	if(!sucess)
	{
		glGetShaderInfoLog(VertexID,512,0,infolog);			
		cout<<"FAILED COMPILING VERTEX SHADER ID::"<<VertexID<<endl;
		cout<<infolog<<endl;
		//_sleep(2);
		exit(0);								
	}
	cout<<"SUCCESS COMPILING VERTEX SHADER ID::"<<VertexID<<endl;
	//............ COMPILING FRAGMENT SHADER ....................................................
	FragmentID=glCreateShader(GL_FRAGMENT_SHADER);		
	glShaderSource(FragmentID,1,&frag_source,0);			
	glCompileShader(FragmentID);							
	glGetShaderiv(FragmentID,GL_COMPILE_STATUS,&sucess);	//Retreiving Compile status
	if(!sucess)
	{
		glGetShaderInfoLog(FragmentID,512,0,infolog);
		cout<<"FAILED COMPILING FRAGMENT SHADER ID::"<<FragmentID<<endl;
		cout<<infolog<<endl;
		//_sleep(2);
		exit(0);
	}
	cout<<"SUCCESS COMPILING FRAGMENT SHADER ID::"<<FragmentID<<endl;

	//.......... LINKING VERTEX AND FRAGMENT SHADERS .........................................
	ProgramID=glCreateProgram();
	glAttachShader(ProgramID,VertexID);
	glAttachShader(ProgramID,FragmentID);
	glLinkProgram(ProgramID);
	glGetProgramiv(ProgramID,GL_LINK_STATUS,&sucess);
	if(!sucess)
	{
		glGetProgramInfoLog(ProgramID,512,0,infolog);
		cout<<"FAILED LINKING PROGRAM ID::"<<ProgramID<<endl;
		cout<<infolog<<endl;
		//_sleep(2);
		exit(0);
	}
	cout<<"SUCCESS LINKING PROGRAM ID::"<<FragmentID<<endl;
}

void Shaders::use()
{
	glUseProgram(ProgramID);
}
Shaders::~Shaders(void)
{
}
