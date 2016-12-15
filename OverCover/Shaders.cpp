#include "Shaders.h"

Shaders::Shaders()
{

}
Shaders::Shaders(const GLchar* vert_source,const GLchar* frag_source)
{
	//...........Initializing variables....................................................
	//GLuint VertexID,FragmentID;				
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
		system("pause");
		//exit(0);								
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
		system("pause");
		//exit(0);
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
		system("pause");
		//exit(0);
	}
	cout<<"SUCCESS LINKING PROGRAM ID::"<<ProgramID<<endl;
}

void Shaders::use()
{
	glUseProgram(ProgramID);
}
Shaders::~Shaders(void)
{
	//ResourceManager* inst=ResourceManager::GetInstance();
	//inst->clear(VertexID,FragmentID);
}
void Shaders::SetintU(const GLchar* name,GLint& value,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform1i(glGetUniformLocation(ProgramID,name),value);
}
void Shaders::SetFloatU(const GLchar* name,GLfloat value,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform1f(glGetUniformLocation(ProgramID,name),value);
}
void Shaders::SetVector2U(const GLchar* name,GLfloat& value,GLfloat& value1,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform2f(glGetUniformLocation(ProgramID,name),value,value1);
}
void Shaders::SetVector2U(const GLchar* name,glm::vec2& value,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform2f(glGetUniformLocation(ProgramID,name),value.x,value.y);
}
void Shaders::SetVector3U(const GLchar* name,glm::vec3& value,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform3f(glGetUniformLocation(ProgramID,name),value.x,value.y,value.z);
}
void Shaders::SetVector3U(const GLchar* name,GLfloat& value,GLfloat& value1,GLfloat& value2,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform3f(glGetUniformLocation(ProgramID,name),value,value1,value2);
}
void Shaders::SetVector4U(const GLchar* name,glm::vec4& value,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform4f(glGetUniformLocation(ProgramID,name),value.x,value.y,value.z,value.w);
}
void Shaders::SetVector4U(const GLchar* name,GLfloat& value,GLfloat& value1,GLfloat& value2,GLfloat& value3,GLboolean useshader)
{
	if(useshader)
		use();
	glUniform4f(glGetUniformLocation(ProgramID,name),value,value1,value2,value3);
}

