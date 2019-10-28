#pragma once
#include "ofMain.h"

class Ripple {
public:
	Ripple();
	void draw();
	float radius;
	float speed;
	int alpha;
	glm::vec2 center;
};

