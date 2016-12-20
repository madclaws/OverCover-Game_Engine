#pragma once
#include<GL\glew.h>
#include<iostream>
#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtc\type_ptr.hpp>
using namespace std;
class Shaders
{GLuint ProgramID;
	GLuint VertexID,FragmentID;		
public:
	Shaders(const GLchar*,const GLchar*);
	Shaders();
	//call gluseprogram() to use the current shader program for following render code
	void use();
	//Setting integer uniform variable OR Can be used for texture
	void SetintU(const GLchar*,GLint,GLboolean);

	//Setting Float uniform variable
	void SetFloatU(const GLchar*,GLfloat,GLboolean);
	
	//Setting Vector2 uniform variable(input as float)
	void SetVector2U(const GLchar*,GLfloat&,GLfloat&,GLboolean);

	//Setting Vector2 uniform varaible(input as vector)
	void SetVector2U(const GLchar*,glm::vec2&,GLboolean);

	//Setting Vector3 uniform variable(input as float)
	void SetVector3U(const GLchar*,glm::vec3&,GLboolean);

	//Setting Vector3 uniform variable(input as vector)
	void SetVector3U(const GLchar*,GLfloat&,GLfloat&,GLfloat&,GLboolean);

	//Setting Vector4 uniform variable(input as float)
	void SetVector4U(const GLchar*,GLfloat&,GLfloat&,GLfloat&,GLfloat&,GLboolean);

	//Setting Vector4 uniform variable(input as vector)
	void SetVector4U(const GLchar*,glm::vec4&,GLboolean);

	//Setting matrix 4x4 uniform variable
	void SetMatrix4U(const GLchar*,glm::mat4&,GLboolean);
	
	~Shaders(void);
};

