#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "OscHandler.h"
#include "OscSender.h"
#include "RhythmGen.h"
#include "KeyRectManager.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();
	void showLog();

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

	OscHandler* osc;
	OscSender* oscSender;
	RhythmGen* rhythmGen;
	KeyRectManager* keyRectManager;
	ofxXmlSettings xml;
	string address;
	int id;
	int bpm;
	int partNum;
};
