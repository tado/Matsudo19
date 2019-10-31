#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	//ofToggleFullscreen();
	ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < NUM; i++) {
		shader[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	for (int i = 0; i < NUM; i++) {
		float br = sin(ofGetElapsedTimef() / 3.0 + TWO_PI / NUM * i) * 48 + 48;
		ofSetColor(br * 0.4, br * 1.2, br * 1.5);
		if (br <= 5) {
			shader[i].changeShader();
		}
		shader[i].fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
	ofDisableBlendMode();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'f') {
		ofToggleFullscreen();
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
