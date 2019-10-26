#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	for (int i = 0; i < 12; i++) {
		sender[i].setup("192.168.11." + ofToString(20 + i), 10000);
	}
	beatCount = 0;
	currentBpm = 60;
	bpm.setBpm(currentBpm);
	bpm.setBeatPerBar(1);
	bpm.start();
	/*
	ofxOscMessage m;
	m.setAddress("/bpm");
	m.addIntArg(currentBpm);
	for (int i = 0; i < 12; i++) {
		sender[i].sendMessage(m, false);
	}
	*/


	ofAddListener(bpm.beatEvent, this, &ofApp::getBeat);
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::getBeat() {
	if (beatCount % 8 == 0) {
		currentBpm = ofRandom(20, 120);
		//bpm.setBpm(currentBpm);

		int on[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
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
	/*
	if (beatCount % 14 == 0) {
		bpm.setBpm(currentBpm);
		bpm.setBeatPerBar(1);
		ofxOscMessage m2;
		m2.setAddress("/bpm");
		m2.addIntArg(currentBpm);
		for (int i = 0; i < 12; i++) {
			sender[i].sendMessage(m2, false);
		}
		bpm.start();
	}
	*/
	beatCount++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	currentBpm = ofRandom(20, 120);
	bpm.setBpm(currentBpm);

	int on[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
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

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
