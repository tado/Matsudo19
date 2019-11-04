#include "OscSender.h"
#include "ofApp.h"

OscSender::OscSender() {
	ofApp* app = ((ofApp*)ofGetAppPtr());

	for (int i = 0; i < 12; i++) {
		sender[i].setup("192.168.11." + ofToString(20 + i), 10000);
	}
	beatCount = 0;
	bpm.setBpm(ofRandom(10, 20));
	bpm.setBeatPerBar(1);
	ofAddListener(bpm.beatEvent, this, &OscSender::getBeat);
	bpm.start();
	app->rhythmGen->sequenceBpm.start();

	/*
	if (app->id == 0) {
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m;
			m.setAddress("/start");
			sender[i].sendMessage(m, false);
		}
	}
	*/
}

void OscSender::getBeat() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (beatCount % 6 == 0) {
		//set Player part
		int on[12];
		int partNum = ofRandom(2, 8);
		for (int i = 0; i < 12; i++) {
			if (i <= partNum) {
				on[i] = 1;
			}
			else {
				on[i] = 0;
			}
		}
		random_shuffle(&on[0], &on[11]);
		for (int i = 0; i < 12; i++) {
			//send que to players
			ofxOscMessage m;
			m.setAddress("/que");
			m.addIntArg(on[i]);
			sender[i].sendMessage(m, false);
		}
	}
	if (beatCount % 16 == 0) {
		for (int i = 0; i < 12; i++) {
			//send bpm
			ofxOscMessage m2;
			m2.setAddress("/bpm");
			m2.addIntArg(app->bpm);
			sender[i].sendMessage(m2, false);
		}
	}
	beatCount++;

	//Check live
	if (app->id == 0) {
		if (beatCount % 64 == 0) {
			for (int i = 0; i < 12; i++) {
				ofxOscMessage m;
				m.setAddress("/start");
				sender[i].sendMessage(m, false);
			}
		}
	}
}

void OscSender::exit() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (app->id == 0) {
		bpm.start();
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m;
			m.setAddress("/stop");
			sender[i].sendMessage(m, false);
		}
	}
}