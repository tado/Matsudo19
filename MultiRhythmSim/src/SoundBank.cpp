#include "SoundBank.h"

SoundBank::SoundBank() {
	string path = ofToDataPath("glockenspiel");
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
}