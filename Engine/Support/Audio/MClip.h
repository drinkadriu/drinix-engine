#pragma once
#ifndef MClip_h
#define MClip_h
class MClip
{
public:
	Music sound;
	string Location;
	float Volume;
	bool Loop;

	void Play() {
		sound.play();
	}
	void SetVolume(float newv) {
		Volume = newv;
		sound.setVolume(Volume);
	}
	void SetLoop(bool newl) {
		Loop = newl;
		sound.setLoop(Loop);
	}
	MClip();
	MClip(string, bool, float vol = 100);
	~MClip();
};
#endif