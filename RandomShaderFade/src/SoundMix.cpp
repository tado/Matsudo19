#include "SoundMix.h"

SoundMix::SoundMix(int num) {
	snd.load("drone.wav");
	snd.setVolume(1.0);
	snd.setLoop(true);
	float pitchTable[6] = { 0.125, 0.25, 0.5, 1.0, 1.0, 1.5};
	pitch = pitchTable[int(num % 6)] + ofRandom(0.001);
	snd.setSpeed(pitch);
	snd.play();
	snd.setPosition(ofRandom(1.0));
	snd.setPan(ofRandom(-1, 1));
}