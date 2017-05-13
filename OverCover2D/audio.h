#pragma once
#include<IRRK\irrKlang.h>
#include<iostream>
#include<vector>
#include<string>

using namespace irrklang;
using namespace std;

class audio
{
	int id;
	char* fpath;
	float vol;
	irrklang::ISoundSource* audptr;             //do we need that?
public:
	audio(int fid, char* filepath, float);
	//void play();
	irrklang::ISoundSource* getsoundsrcptr();    //not really required
	void setvol(float v);
	float getvol();
	char* getpath();
	int getid();
	void play(irrklang::ISoundEngine*);
	void loop(irrklang::ISoundEngine*);
	void loadsound(irrklang::ISoundEngine*);   //not really required
};













