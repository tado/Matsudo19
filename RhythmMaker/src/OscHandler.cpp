#include "OscHandler.h"
#include "ofApp.h"

OscHandler::OscHandler() {
	receiver.setup(10000);
}

void OscHandler::update() {

	while (receiver.hasWaitingMessages()) {
		ofApp* app = ((ofApp*)ofGetAppPtr());
		ofxOscMessage m;
		receiver.getNextMessage(m);
		if (m.getAddress() == "/start") {
			app->rhythmGen->sequenceBpm.start();
		}
		if (m.getAddress() == "/stop") {
			app->rhythmGen->sequenceBpm.stop();
		}
		if (m.getAddress() == "/que") {
			if (m.getArgAsInt(0) == 0) {
				app->rhythmGen->live = false;
			}
			else {
				app->rhythmGen->live = true;
			}
		}
		if (m.getAddress() == "/bpm") {
			app->rhythmGen->sequenceBpm.setBpm(m.getArgAsInt(0));
			app->rhythmGen->beatCount = 0;
			if (app->rhythmGen->sequenceBpm.isPlaying()) {
				app->rhythmGen->sequenceBpm.stop();
				app->rhythmGen->sequenceBpm.start();
			}
		}
	}
}