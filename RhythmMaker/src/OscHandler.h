#pragma once
#include "ofxOsc.h"

class OscHandler {
public:
	OscHandler();
	void update();

	ofxOscReceiver receiver;
};

