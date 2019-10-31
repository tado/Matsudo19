#include "RandomShader.h"

RandomShader::RandomShader(){
	ofDirectory dir("100fragments");
	for (int i = 0; i < dir.getFiles().size(); i++) {
		ostringstream digit;
		digit << setfill('0') << right << setw(2) << i;
		ofShader sh;
		sh.load("", "100fragments/" + digit.str() + ".frag");
		shaders.push_back(sh);
	}
	num = int(ofRandom(shaders.size()));
	fbo.allocate(1920, 1080);
}

void RandomShader::update() {
	fbo.begin();
	shaders[num].begin();
	shaders[num].setUniform1f("time", ofGetElapsedTimef() * 0.2);
	shaders[num].setUniform2f("resolution", 1920, 1080);
	ofDrawRectangle(0, 0, 1920, 1080);
	shaders[num].end();
	fbo.end();
}
void RandomShader::changeShader() {
	num = int(ofRandom(shaders.size()));
}

RandomShader::~RandomShader(){
}

