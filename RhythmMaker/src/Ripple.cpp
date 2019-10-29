#include "Ripple.h"

Ripple::Ripple() {
	center = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	speed = 4.0;
	radius = 0;
	alpha = 255;
}

void Ripple::draw() {
	if (live) {
		ofSetColor(63, 127, 255, alpha);
		ofSetCircleResolution(32);
		ofDrawCircle(center, radius);
		radius += speed;
		alpha *= 0.9999;

		if (radius > ofGetWidth() * 2) {
			live = false;
		}
	}
}

void Ripple::setLive() {
	radius = 0;
	alpha = 255;
	live = true;
}