#include "RhythmGen.h"

RhythmGen::RhythmGen(int _bpm) {
	bpm = _bpm;
	sequenceBpm.setBpm(bpm);
	sequenceBpm.setBeatPerBar(div);
	//sequenceBpm.start();

	string path = ofToDataPath("newGamelan");
	//cout << path << endl;
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
		if (i < div / 4) {
			amp[i] = 1.0;
		}
		else {
			amp[i] = 0.0;
		}
	}
	random_shuffle(&amp[0], &amp[div - 1]);
	ofAddListener(sequenceBpm.beatEvent, this, &RhythmGen::getBeat);
	beatCount = 0;
}

void RhythmGen::draw() {
	/*
	if (sequenceBpm.isPlaying()) {
		ofSetColor(255);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	}
	*/

	for (int i = 0; i < ripples.size(); i++) {
		ripples[i]->draw();
	}
}

void RhythmGen::getBeat() {
	int n = notes[beatCount % div];
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

	if (amp[beatCount % div] > 0) {
		ripples.push_back(new Ripple());
	}
	if (ripples.size() > 5) {
		ripples.erase(ripples.begin());
	}
}