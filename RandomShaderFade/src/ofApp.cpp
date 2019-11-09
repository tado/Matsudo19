#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofToggleFullscreen();
	ofSetWindowShape(1920, 1080);
	ofHideCursor();

	for (int i = 0; i < 6; i++)	{
		sound.push_back(new SoundMix(i));
	}
	showCode = new ShowCode();
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
	string allCode = "";
	for (int i = 0; i < NUM; i++) {
		float br = sin(ofGetElapsedTimef() / 1.0 + TWO_PI / NUM * i) * 48 + 48;
		ofSetColor(br * 0.3, br * 0.8, br * 0.7);
		if (br < 0.1) {
			shader[i].changeShader();
		}
		shader[i].fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
		allCode += showCode->shaderString[shader[i].num];
	}
	ofSetColor(255);
	ofDrawBitmapString(allCode, 40, 40);
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
