#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowTitle("openFrameworks");
	ofSetFrameRate(30);

	ofBackground(255);
	ofSetColor(0);
	ofSetLineWidth(2);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 10;
	ofColor color;
	for (int x = -300; x <= 300; x += 30) {

		for (int y = -300; y <= 300; y += 30) {

			ofPushMatrix();
			ofTranslate(x, y);

			int deg = ofMap(ofNoise(x * 0.0035, y * 0.0035, ofGetFrameNum() * 0.0005), 0, 1, 0, 720);
			int deg_param = deg % 90;
			deg = deg / 90 * 90;
			if (deg_param > 85) {
				
				deg += ofMap(deg_param, 85, 90, 0, 90);
			}

			ofDrawCircle(glm::vec2(), radius);
			ofDrawLine(
				glm::vec2(radius * 1.85 * cos(deg * DEG_TO_RAD), radius * 1.85 * sin(deg * DEG_TO_RAD)),
				glm::vec2(radius * 1.85 * cos((deg + 180) * DEG_TO_RAD), radius * 1.85  * sin((deg + 180) * DEG_TO_RAD)));

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}