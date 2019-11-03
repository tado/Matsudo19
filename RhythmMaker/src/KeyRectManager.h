#pragma once
#include "ofMain.h"
#include "KeyRect.h"

class KeyRectManager {
public:
	KeyRectManager();
	void draw();
	KeyRect keyRect[16];
};


