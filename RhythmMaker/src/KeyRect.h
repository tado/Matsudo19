#pragma once
#include "ofMain.h"

class KeyRect {
public:
	KeyRect();
	void draw();
	void setLive();

	float speed;
	int alpha;
	glm::vec2 corner;
	bool live;
	ofColor color;
}; 

