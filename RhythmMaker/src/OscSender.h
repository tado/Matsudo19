#pragma once
#include "ofMain.h"
#include "ofxSequencerBpm.h"
#include "ofxOsc.h"

class OscSender {
public:
	OscSender();
	void getBeat();
	void exit();

	ofxOscSender sender[12];
	ofxSequencerBpm bpm;
	float currentBpm;
	int beatCount;
};

