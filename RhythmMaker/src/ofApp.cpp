#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);

	bpm.setBpm(65);
	bpm.setBeatPerBar(div);
	//bpm.start();

	string path = ofToDataPath("newGamelan");
	cout << path << endl;
	ofDirectory dir(path);
	dir.allowExt("wav");
	dir.listDir();
	
	int sampleLength = 40;
	int sampleBegin = ofRandom(0, dir.size() - sampleLength);
	for (int i = sampleBegin; i < sampleBegin + 40; i++) {
		ofLogNotice(dir.getPath(i));
		ofSoundPlayer s;
		s.loadSound(dir.getPath(i));
		snd.push_back(s);
	}
	sndNum = snd.size();

	for (int i = 0; i < div; i++) {
		notes.push_back(ofRandom(0, snd.size()));
		pan.push_back(ofRandom(-1.0, 1.0));
	}
	for (int i = 0; i < div; i++) {
		if (i < div / 2) {
			amp[i] = 1.0;
		}
		else {
			amp[i] = 0.0;
		}
	}
	random_shuffle(&amp[0], &amp[div - 1]);
	ofAddListener(bpm.beatEvent, this, &ofApp::getBeat);
	beatCount = 0;

	osc = new OscHandler();
}

//--------------------------------------------------------------
void ofApp::update() {
	osc->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (bpm.isPlaying()) {
		ofSetColor(255);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}
}

void ofApp::getBeat() {
	int n = notes[beatCount % div];
	snd[n].setVolume(0.4);
	snd[n].setPan(ofRandom(-1, 1));
	snd[n].setVolume(amp[beatCount % div]);
	//snd[n].setPan(pan[beatCount % div]);
	snd[n].play();
	beatCount++;

	if (beatCount % (div * 4) == 0) {
		notes.clear();
		pan.clear();
		for (int i = 0; i < div; i++) {
			notes.push_back(ofRandom(0, snd.size()));
			pan.push_back(ofRandom(-1.0, 1.0));
		}
		random_shuffle(&amp[0], &amp[div - 1]);
		beatCount = 0;
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
