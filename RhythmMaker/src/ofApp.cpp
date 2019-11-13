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
	bpm = int(ofMap(id, 0, 11, 20, 120));

	osc = new OscHandler();
	oscSender = new OscSender();
	keyRectManager = new KeyRectManager();
}

//--------------------------------------------------------------
void ofApp::update() {
	osc->update();
	oscSender->update();
	if (ofGetElapsedTimef() > 1024) {
		ofResetElapsedTimeCounter();
		rhythmGen->sequenceBpm.start();
		oscSender->partLastTime = ofGetElapsedTimef();
		oscSender->tempoLastTime = ofGetElapsedTimef();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	keyRectManager->draw();
	//showLog();
	//ofSetColor(255);
	//ofDrawBitmapString(ofGetElapsedTimef(), 20, 20);
}

void ofApp::exit() {
	//oscSender->exit();
}

void ofApp::showLog() {
	ofSetColor(255);
	int line = 13;
	ofDrawBitmapString("ID : " + ofToString(id), 10, line);
	ofDrawBitmapString("IP : " + ofToString(address), 10, line*2);
	ofDrawBitmapString("RhythmLive : " + ofToString(rhythmGen->live), 10, line*3);
	ofDrawBitmapString("RhythmGen isPlaying : " + ofToString(rhythmGen->sequenceBpm.isPlaying()), 10, line*4);
	//ofDrawBitmapString("OscSender isPlaying : " + ofToString(oscSender->bpm.isPlaying()), 10, line*5);
	ofDrawBitmapString("OwnBPM : " + ofToString(bpm), 10, line*6);
	ofDrawBitmapString("CurrentBPM : " + ofToString(rhythmGen->sequenceBpm.getBpm()), 10, line*7);
	//ofDrawBitmapString("OscBPM : " + ofToString(oscSender->bpm.getBpm()), 10, line*8);
	ofDrawBitmapString("RhythmGen beatCount : " + ofToString(rhythmGen->beatCount), 10, line*9);
	//ofDrawBitmapString("OscSender beatCount : " + ofToString(oscSender->beatCount), 10, line*10);

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
