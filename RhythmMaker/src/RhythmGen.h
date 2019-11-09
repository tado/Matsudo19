#pragma once
#include "ofMain.h"
#include "ofxSequencerBpm.h"

class RhythmGen {
public:
	RhythmGen(int bpm);
	void getBeat();
	void draw();
	void reset();

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
	bool live;
};

