#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofHideCursor();

	rhythmGen = new RhythmGen(60);
	xml.loadFile("settings.xml");
	cout << xml.getValue("address", "127.0.0.1") << endl;
	cout << xml.getValue("id", 0) << endl;
	address = xml.getValue("address", "127.0.0.1");
	id = xml.getValue("id", 0);
	bpm = int(ofMap(id, 0, 11, 20, 110));

	osc = new OscHandler();
	oscSender = new OscSender();
	keyRectManager = new KeyRectManager();
}

//--------------------------------------------------------------
void ofApp::update() {
	osc->update();
	oscSender->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	keyRectManager->draw();
}

void ofApp::exit() {
	//oscSender->exit();
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
