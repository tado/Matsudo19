#pragma once

#include "ofMain.h"
#include "ofxSequencerBpm.h"
#include "OscHandler.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void getBeat();

	ofxSequencerBpm bpm;
	int sndNum;
	vector<ofSoundPlayer> snd;
	int beatCount;
	static const int div = 16;
	vector<int> rates;
	vector<int> notes;
	vector<float> pan;
	float amp[div];

	OscHandler* osc;
};
