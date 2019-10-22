#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(10);
	ofBackground(0);

	bpm.setBpm(180.0);
	bpm.setBeatPerBar(8);
	bpm.start();

	string path = ofToDataPath("gamelan");
	cout << path << endl;
	ofDirectory dir(path);
	dir.allowExt("wav");
	dir.listDir();
	sndNum = dir.size();

	for (int i = 0; i < dir.size(); i++) {
		ofLogNotice(dir.getPath(i));
		ofSoundPlayer s;
		s.loadSound(dir.getPath(i));
		snd.push_back(s);
	}

	ofAddListener(bpm.beatEvent, this, &ofApp::getBeat);
	beatCount = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::getBeat() {
	int n = int(ofRandom(5)) + 5;
	snd[n].setVolume(0.5);
	snd[n].setMultiPlay(true);
	snd[n].play();
	beatCount++;
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
