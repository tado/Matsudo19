#include "OscSender.h"
#include "ofApp.h"

OscSender::OscSender() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (app->id == 0) {
		for (int i = 0; i < 12; i++) {
			sender[i].setup("192.168.11." + ofToString(20 + i), 10000);
		}
		beatCount = 0;
		currentBpm = 60;
		bpm.setBpm(currentBpm);
		bpm.setBeatPerBar(1);
		ofAddListener(bpm.beatEvent, this, &OscSender::getBeat);

		bpm.start();
		for (int i = 0; i < 12; i++) {
			for (int i = 0; i < 12; i++) {
				ofxOscMessage m;
				m.setAddress("/start");
				sender[i].sendMessage(m, false);
			}
		}
	}
}

void OscSender::getBeat() {
	if (beatCount % 3 == 0) {
		currentBpm = ofRandom(20, 100);
		//bpm.setBpm(currentBpm);
		//int on[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		int on[16];
		int partNum = ofRandom(2, 16);
		for (int i = 0; i < 16; i++) {
			if (i <= partNum) {
				on[i] = 1;
			}
			else {
				on[i] = 0;
			}
		}
		random_shuffle(&on[0], &on[11]);
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m;
			m.setAddress("/que");
			m.addIntArg(on[i]);
			sender[i].sendMessage(m, false);
		}
	}
	if (beatCount % 8 == 0) {
		//bpm.setBpm(currentBpm);
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m2;
			m2.setAddress("/bpm");
			m2.addIntArg(currentBpm);
			sender[i].sendMessage(m2, false);
		}
	}
	beatCount++;
}