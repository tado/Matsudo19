#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	receiver.setup(10000);
	snd.loadSound("bell.wav");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	// check for waiting messages
	while (receiver.hasWaitingMessages()) {

		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		// check for mouse moved message
		if (m.getAddress() == "/que") {
			snd.setSpeed(ofRandom(0.25, 1.5));
			snd.play();
		}
	}
	if (snd.isPlaying()) {
		ofBackground(255, 0, 0);
	}
	else {
		ofBackground(0);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
