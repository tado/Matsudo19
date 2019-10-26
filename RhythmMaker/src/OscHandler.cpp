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

		if (m.getAddress() == "/que") {
			if (m.getArgAsInt(0) == 0) {
				app->bpm.stop();
			}
			else {
				app->beatCount = 0;
				app->bpm.start();
			}
		}
		if (m.getAddress() == "/bpm") {
			app->bpm.setBpm(m.getArgAsInt(0));
			app->beatCount = 0;
			if (app->bpm.isPlaying()) {
				app->bpm.stop();
				app->bpm.start();
			}
		}
	}
}