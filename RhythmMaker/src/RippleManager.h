#pragma once
#include "ofMain.h"
#include "Ripple.h"

class RippleManager {
public:
	Ripple ripple[16];
	RippleManager();
	void draw();
};

