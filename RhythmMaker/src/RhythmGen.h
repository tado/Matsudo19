#pragma once
#include "ofMain.h"
#include "ofxSequencerBpm.h"
#include "Ripple.h"

class RhythmGen {
public:
	RhythmGen(int bpm);
	void getBeat();
	void draw();

	ofxSequencerBpm sequenceBpm;
	int bpm;
	int sndNum;
	vector<ofSoundPlayer> snd;
	int beatCount;
	static const int div = 16;
	vector<int> rates;
	vector<int> notes;
	vector<float> pan;
	float amp[div];

	vector<Ripple *> ripples;
	bool live;
};

