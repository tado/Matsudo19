#include "RippleManager.h"

RippleManager::RippleManager() {
	for (int i = 0; i < 12; i++) {
		ripple[i].center = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	}
}

void RippleManager::draw() {
	for (int i = 0; i < 12; i++) {
		if (ripple[i].live == true) {
			ripple[i].draw();
		}
	}
}