#include "RhythmGen.h"
#include "ofApp.h"

RhythmGen::RhythmGen(int _bpm) {
	bpm = _bpm;
	live = true;
	repeat = int(ofRandom(4, 8));
	sequenceBpm.setBpm(bpm);
	sequenceBpm.setBeatPerBar(div);

	string path = ofToDataPath("newGamelan");
	ofDirectory dir(path);
	dir.allowExt("wav");
	dir.listDir();

	int sampleLength = dir.size();
	int sampleBegin = ofRandom(0, dir.size() - sampleLength);
	for (int i = sampleBegin; i < sampleBegin + sampleLength; i++) {
		//ofLogNotice(dir.getPath(i));
		ofSoundPlayer s;
		s.loadSound(dir.getPath(i));
		snd.push_back(s);
	}
	sndNum = snd.size();

	for (int i = 0; i < div; i++) {
		notes.push_back(ofRandom(0, snd.size()));
		//pan.push_back(ofRandom(-1.0, 1.0));
	}
	for (int i = 0; i < div; i++) {
		if (i < div / 8) {
			amp[i] = 0.75;
		}
		else {
			amp[i] = 0.0;
		}
	}
	random_shuffle(&amp[0], &amp[div]);
	ofAddListener(sequenceBpm.beatEvent, this, &RhythmGen::getBeat);
	beatCount = 0;
}

void RhythmGen::draw() {

}

void RhythmGen::getBeat() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (live) {
		int n = notes[beatCount % div];
		//snd[n].setPan(ofRandom(-1, 1));
		snd[n].setVolume(amp[beatCount % div]);
		snd[n].play();
		beatCount++;

		if (beatCount % (div * repeat) == 0) {
			notes.clear();
			//pan.clear();
			for (int i = 0; i < div; i++) {
				notes.push_back(ofRandom(0, snd.size()));
				//pan.push_back(ofRandom(-1.0, 1.0));
			}
			random_shuffle(&amp[0], &amp[div - 1]);
			beatCount = 0;
		}
		/*
		if (amp[beatCount % div] > 0) {
			app->keyRectManager->keyRect[beatCount % div].setLive();
		}
		*/
	}
}
