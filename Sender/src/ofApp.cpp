#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	int port = 10000;
	for (size_t i = 0; i < 12; i++){
		ip[i] = "192.168.11." + ofToString(20 + i);
		sender[i].setup(ip[i], port);
	}
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
	ofxOscMessage m;
	m.setAddress("/que");
	for (size_t i = 0; i < 12; i++){
		sender[i].sendMessage(m, false);
	}
	ofBackground(255, 0, 0);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofBackground(0);
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
