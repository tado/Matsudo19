#include "OscSender.h"
#include "ofApp.h"

OscSender::OscSender() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	for (int i = 0; i < 12; i++) {
		sender[i].setup("192.168.11." + ofToString(20 + i), 10000);
	}
	beatCount = 0;
	currentBpm = 60;
	bpm.setBpm(currentBpm);
	bpm.setBeatPerBar(1);
	ofAddListener(bpm.beatEvent, this, &OscSender::getBeat);
	if (app->id == 0) {
		bpm.start();
	}
}

void OscSender::getBeat() {
	if (beatCount % 32 == 0) {
		currentBpm = ofRandom(20, 120);
		int on[] = { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 };
		random_shuffle(&on[0], &on[11]);
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m;
			m.setAddress("/que");
			m.addIntArg(on[i]);
			sender[i].sendMessage(m, false);

			ofxOscMessage m2;
			m2.setAddress("/bpm");
			m2.addIntArg(currentBpm);
			sender[i].sendMessage(m2, false);
		}
	}
	beatCount++;
}