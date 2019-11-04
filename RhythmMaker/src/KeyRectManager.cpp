#include "KeyRectManager.h"

KeyRectManager::KeyRectManager() {
	for (int i = 0; i < 16; i++) {
		keyRect[i].corner = glm::vec2(ofGetWidth()/4 * (i % 4), 0);
	}
}

void KeyRectManager::draw() {
	for (int i = 0; i < 16; i++) {
		if (keyRect[i].live == true) {
			keyRect[i].draw();
		}
	}
}
