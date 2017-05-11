#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<IRRK\irrKlang.h>
#include<string>
#include"audio.h"

using namespace std;
using namespace irrklang;

class AudioEngine
{
	static AudioEngine *AEngine;  //singleton instance AEngine
	static bool flag;             //singleton flag
	irrklang::ISoundEngine* Audioengine;    //irrklang Audio Engine --- Audioengine
											//list of sounds
	std::list<audio> audiolist;          //list of Audio objects
	AudioEngine();
public:
	static AudioEngine* getEngine();
	void addaudio(char* fpath, int id, float);
	void delaudio(int id);
	void play(int id);
	void loop(int id);
	void setvol(int id, float vol);
	~AudioEngine() { flag = false; };
};


