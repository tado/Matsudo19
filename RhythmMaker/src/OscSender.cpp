#include "OscSender.h"
#include "ofApp.h"

OscSender::OscSender() {
	ofApp* app = ((ofApp*)ofGetAppPtr());

	for (int i = 0; i < app->partNum; i++) {
		sender[i].setup("192.168.111." + ofToString(20 + i), 10000);
	}
	app->rhythmGen->sequenceBpm.start();	
	//init send bpm
	for (int i = 0; i < app->partNum; i++) {
		//send bpm
		ofxOscMessage m;
		m.setAddress("/bpm");
		m.addIntArg(app->bpm);
		sender[i].sendMessage(m, false);
	}

	partLastTime = ofGetElapsedTimef();
	tempoLastTime = ofGetElapsedTimef();
	partIntervalTime = ofRandom(30, 60);
	tempoIntervalTime = ofRandom(60, 120);
}

void OscSender::update() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (ofGetElapsedTimef() > partLastTime + partIntervalTime) {
		partLastTime = ofGetElapsedTimef();
		//set Player part
		int on[4];
		int partNum = int(ofRandom(1, app->partNum));
		for (int i = 0; i < app->partNum; i++) {
			if (i <= partNum) {
				on[i] = 1;
			}
			else {
				on[i] = 0;
			}
		}
		random_shuffle(&on[0], &on[app->partNum]);
		for (int i = 0; i < app->partNum; i++) {
			//send que to players
			ofxOscMessage m;
			m.setAddress("/que");
			m.addIntArg(on[i]);
			sender[i].sendMessage(m, false);
		}
	}
	if (ofGetElapsedTimef() > tempoLastTime + tempoIntervalTime) {
		tempoLastTime = ofGetElapsedTimef();
		for (int i = 0; i < app->partNum; i++) {
			//send bpm
			ofxOscMessage m;
			m.setAddress("/bpm");
			m.addIntArg(app->bpm);
			sender[i].sendMessage(m, false);
		}
	}
}

/*
void OscSender::getBeat() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (beatCount % 8 == 0) {
		//set Player part
		int on[12];
		int partNum = int(ofRandom(2, 8));
		for (int i = 0; i < 12; i++) {
			if (i <= partNum) {
				on[i] = 1;
			}
			else {
				on[i] = 0;
			}
		}
		random_shuffle(&on[0], &on[12]);
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
		beatCount = 0;
	}
	beatCount++;
	if (beatCount > 16) {
		bpm.stop();
		bpm.reset();
		bpm.start();
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
*/