#include "KeyRect.h"

KeyRect::KeyRect() {
	corner = glm::vec2(0, 0);
	speed = 4.0;
	alpha = 255;
}

void KeyRect::draw() {
	if (live) {
		ofSetColor(63, 190, 255, alpha);
		ofDrawRectangle(corner, ofGetWidth()/8, ofGetHeight());
		alpha *= 0.9999;

		if (alpha < 1.0) {
			live = false;
		}
	}
}

void KeyRect::setLive() {
	alpha = 255;
	live = true;
}
