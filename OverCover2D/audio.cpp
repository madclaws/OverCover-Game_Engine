#include"audio.h"

audio::audio(int fid, char* filepath, float svol = 1.0)
{
	fpath = filepath;
	id = fid;
	vol = svol;
	//loadsound(eng);
}

irrklang::ISoundSource* audio::getsoundsrcptr()
{
	return audptr;
}

void audio::loadsound(irrklang::ISoundEngine* eng)
{
	audptr = eng->addSoundSourceFromFile(fpath);
}

int audio::getid()
{
	return id;
}

char* audio::getpath()
{
	return fpath;
}

void audio::setvol(float v)
{
	vol = v;
	if (audptr != NULL)
	{
		audptr->setDefaultVolume(vol);
	}
}

float audio::getvol()
{
	return vol;
}

//////////////

