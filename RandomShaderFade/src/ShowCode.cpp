#include "ShowCode.h"

ShowCode::ShowCode() {
	ofDirectory dir("100fragments");
	for (int i = 0; i < dir.getFiles().size(); i++) {
		ostringstream digit;
		digit << setfill('0') << right << setw(2) << i;
		ifstream ifs(ofToDataPath("100fragments/" + digit.str() + ".frag"));
		shaderString[i] = string(istreambuf_iterator<char>(ifs), istreambuf_iterator<char>());
		//cout << "Shader " << i << " : " << shaderString[i] << endl;
	}
}

void ShowCode::drawCode(int n) {
	ofSetColor(255);
	ofDrawBitmapString(shaderString[n], 20, 20);
}