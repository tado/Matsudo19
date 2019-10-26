#pragma once
#include "ofMain.h"
#include "ofxSequencerBpm.h"

class RhythmMaker
{
public:
	RhythmMaker(int id, int bpm, int beatPerBar);
	void update();
	void restart();
	void getBeat();

	ofxSequencerBpm bpm;
	int id;
	int beatPerBar;
	int beatCount;
};

