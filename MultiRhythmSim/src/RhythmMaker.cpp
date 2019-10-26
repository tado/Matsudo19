#include "RhythmMaker.h"
#include "ofApp.h"

RhythmMaker::RhythmMaker(int _id, int _bpm, int _beatPerBar) {
	id = _id;
	beatPerBar = _beatPerBar;
	bpm.setBpm(_bpm);
	bpm.setBeatPerBar(_beatPerBar);
	bpm.start();

	beatCount = 0;
	ofAddListener(bpm.beatEvent, this, &RhythmMaker::getBeat);
}

void RhythmMaker::update() {

}

void RhythmMaker::getBeat() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	int note[] = { 0, 4, 5, 7, 9, 11 };
	float rate[] = {0.25, 0.25 * 1.5, 0.25 * pow(1.5, 2), 0.25 * pow(1.5, 3), 0.25 * pow(1.5, 4), 0.25 * pow(1.5, 5) ,0.25 * pow(1.5, 7)};
	int n = note[(int(ofRandom(6)) + id) % 6];
	float r = rate[(int(ofRandom(8)) + id) % 8];
	app->soundBank->snd[n].setVolume(0.5);
	app->soundBank->snd[n].setMultiPlay(true);
	app->soundBank->snd[n].setSpeed(r);
	app->soundBank->snd[n].setPan(ofRandom(-1, 1));
	app->soundBank->snd[n].play();
	beatCount = (beatCount++) % beatPerBar;
}

void RhythmMaker::restart() {
	bpm.reset();
}