#include "KeyRect.h"

KeyRect::KeyRect() {
	corner = glm::vec2(0, 0);
	color = ofColor(127, 255, 255);
	speed = 4.0;
	alpha = 255;
}

void KeyRect::draw() {
	if (live) {
		ofSetColor(color.r, color.g, color.b, alpha);
		ofDrawRectangle(corner, ofGetWidth()/4, ofGetHeight());
		alpha *= 0.99;

		if (alpha < 1.0) {
			live = false;
		}
	}
}

void KeyRect::setLive() {
	alpha = 255;
	live = true;
}
