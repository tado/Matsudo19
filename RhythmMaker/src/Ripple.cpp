#include "Ripple.h"

Ripple::Ripple() {
	center = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	speed = 4.0;
	radius = 0;
	alpha = 255;
}

void Ripple::draw() {
	ofSetColor(63, 127, 255, alpha);
	ofSetCircleResolution(32);
	ofDrawCircle(center, radius);
	radius += speed;
	alpha *= 0.9999;
}