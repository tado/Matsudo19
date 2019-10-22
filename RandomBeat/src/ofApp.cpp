#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	snd.loadSound("bell.wav");
	rectW = ofGetWidth()/4;
	rectX = -rectW;
	rate = ofRandom(0.25, 1.5);
}

//--------------------------------------------------------------
void ofApp::update(){
	rectX += ofMap(rate, 0.25, 1.5, 0.25, 1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (rectX > ofGetWidth()){
		snd.setSpeed(rate);
		snd.play();
		rectX = -rectW;
		rate = ofRandom(0.25, 1.5);
	}
	ofDrawRectangle(rectX, 0, rectW, ofGetHeight());
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
