#include "stdafx.h"
#include "Public.h"
#include "MClip.h"


MClip::MClip()
{
}

MClip::MClip(string location, bool loop, float vol)
{
	sound.openFromFile(location);
	Location = location;
	Volume = vol;
	Loop = loop;
	sound.setVolume(Volume);
	sound.setLoop(Loop);
}

MClip::~MClip()
{
}
