#include "ofApp.h"

void ofApp::setup() {
	ofSetFrameRate(40);
	soundBank = new SoundBank();
	for (int i = 0; i < 12; i++) {
		RhythmMaker *r = new RhythmMaker(i, 40, 16);
		rhythmMaker.push_back(r);
	}
	bpm.setBpm(40);
	bpm.setBeatPerBar(1);
	ofAddListener(bpm.beatEvent, this, &ofApp::getBeat);
}

void ofApp::getBeat() {
	for (int i = 0; i < 4; i++) {
		//rhythmMaker[i]->restart();
	}
}

void ofApp::update() {

}

void ofApp::draw() {

}

void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
