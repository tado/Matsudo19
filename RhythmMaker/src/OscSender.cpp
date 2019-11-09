#include "OscSender.h"
#include "ofApp.h"

OscSender::OscSender() {
	ofApp* app = ((ofApp*)ofGetAppPtr());

	for (int i = 0; i < 12; i++) {
		sender[i].setup("192.168.11." + ofToString(20 + i), 10000);
	}
	beatCount = 0;
	bpm.setBpm(ofRandom(10, 32));
	bpm.setBeatPerBar(1);
	ofAddListener(bpm.beatEvent, this, &OscSender::getBeat);
	bpm.start();
	app->rhythmGen->sequenceBpm.start();

	//init send bpm
	for (int i = 0; i < 12; i++) {
		//send bpm
		ofxOscMessage m;
		m.setAddress("/bpm");
		m.addIntArg(app->bpm);
		sender[i].sendMessage(m, false);
	}
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

void OscSender::update() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (bpm.isPlaying() == false) {
		bpm.stop();
		bpm.reset();
		bpm.setBpm(ofRandom(10, 32));
		bpm.setBeatPerBar(1);
		bpm.start();
	}
	if (app->rhythmGen->sequenceBpm.isPlaying() == false) {
		app->rhythmGen->reset();
	}
}

void OscSender::getBeat() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (beatCount % 8 == 0) {
		//set Player part
		int on[12];
		int partNum = int(ofRandom(2, 12));
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
			ofxOscMessage m;
			m.setAddress("/bpm");
			m.addIntArg(app->bpm);
			sender[i].sendMessage(m, false);
		}
	}
	beatCount++;
	if (beatCount > 1024) {
		beatCount = 0;
	}

	/*
	if (app->id == 0) {
		if (beatCount % 64 == 0) {
			for (int i = 0; i < 12; i++) {
				ofxOscMessage m;
				m.setAddress("/start");
				sender[i].sendMessage(m, false);
			}
		}
	}
	*/
}

void OscSender::exit() {
	/*
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (app->id == 0) {
		bpm.start();
		for (int i = 0; i < 12; i++) {
			ofxOscMessage m;
			m.setAddress("/stop");
			sender[i].sendMessage(m, false);
		}
	}
	*/
}