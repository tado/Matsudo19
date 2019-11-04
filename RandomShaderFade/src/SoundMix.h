#pragma once
#include "ofMain.h"

class SoundMix {
public:
	SoundMix(int num);
	
	ofSoundPlayer snd;
	float pitch;
};

