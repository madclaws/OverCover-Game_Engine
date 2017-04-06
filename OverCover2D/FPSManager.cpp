#include "FPSManager.h"

GLint FPSManager::FrameCount;
GLfloat FPSManager::MaxFps;
FPSManager::FPSManager(void):StartTime(0.0f),EndTime(0.0f)
{
	MaxFps=60.0f;
	FrameCount=0;
	Required_ms=1000/MaxFps;
}

void FPSManager::Begin()
{
	StartTime=glfwGetTime();
}
void FPSManager::LimitFps()
{
	++FrameCount;
	EndTime=glfwGetTime()-StartTime;
	EndTime*=1000;
	if(Required_ms>EndTime)
		Sleep(Required_ms-EndTime);
}
void FPSManager::CalculateFPS()
{
	static GLdouble previous_time=glfwGetTime();
	GLdouble curr_time=glfwGetTime();
	static const GLint SAMPLE=5;
	static GLint sample_count=0;
	GLint avg_count=0;
	GLdouble frame_avg_time=0;
	static GLdouble frame_array[SAMPLE];
	GLdouble frametime=curr_time-previous_time;
	frame_array[sample_count++ % SAMPLE]=frametime;
	
	previous_time=curr_time;
	if(sample_count<SAMPLE)
		avg_count=sample_count;
	else
		avg_count=SAMPLE;
	for(GLint i=0;i<avg_count;i++)
	{
		frame_avg_time+=frame_array[i];
	}
	frame_avg_time/=avg_count;
	frame_avg_time*=1000;
	if(this->FrameCount==10){
	cout<<(1000/frame_avg_time)<<endl;
	this->FrameCount=0;
}
}
FPSManager::~FPSManager(void)
{

}
