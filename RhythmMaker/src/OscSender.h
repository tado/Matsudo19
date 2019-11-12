#pragma once
#include "ofMain.h"
//#include "ofxSequencerBpm.h"
#include "ofxOsc.h"

class OscSender {
public:
	OscSender();
	void update();
	void exit();
	float partIntervalTime;
	float tempoIntervalTime;
	float partLastTime;
	float tempoLastTime;

	//void getBeat();
	ofxOscSender sender[12];
	//ofxSequencerBpm bpm;
	//float currentBpm;
	//int beatCount;
};

