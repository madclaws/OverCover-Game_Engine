#pragma once
#include"audiomanager.h"

AudioEngine* AudioEngine::AEngine = NULL;
bool AudioEngine::flag = false;

AudioEngine* AudioEngine::getEngine()
{
	if (!flag)
	{
		AEngine = new AudioEngine();
		flag = true;
		return AEngine;
	}
	else
	{
		return AEngine;
	}
}

AudioEngine::AudioEngine()
{
	Audioengine = irrklang::createIrrKlangDevice();
}

void AudioEngine::addaudio(char* fpath, int id, float vol = 1.0f)
{
	audio obj = audio(id, fpath, vol);
	audiolist.push_back(obj);
}

void AudioEngine::delaudio(int id)
{
	std::list<audio>::iterator i;
	for (i = audiolist.begin(); i != audiolist.end(); i++)
	{
		if (i->getid() == id)
		{
			swap(*i, audiolist.back());
			audiolist.pop_back();
		}
	}
}


/*	void delaudio(int id);*/
void AudioEngine::play(int id)
{
	std::list<audio>::iterator i;
	for (i = audiolist.begin(); i != audiolist.end(); i++)
	{
		if (i->getid() == id)
		{
			Audioengine->play2D(i->getsoundsrcptr());
		}
	}
}
void AudioEngine::loop(int id)
{
	std::list<audio>::iterator i;
	for (i = audiolist.begin(); i != audiolist.end(); i++)
	{
		if (i->getid() == id)
		{
			Audioengine->play2D(i->getsoundsrcptr(), true);
		}
	}
}

	void AudioEngine::setvol(int id, float vol)
	{
		std::list<audio>::iterator i;
		for (i = audiolist.begin(); i != audiolist.end(); i++)
		{
			if (i->getid() == id)
			{
				i->setvol(vol);
			}
		}
	}