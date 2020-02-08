#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
  image.loadImage("images/snowdonia.jpg");
  levels.setup(image.getWidth(), image.getHeight());
  doDrawInfo = true;
}

//--------------------------------------------------------------
void testApp::update() {
  levels.begin();
  image.draw(0, 0);
  levels.end();
}

//--------------------------------------------------------------
void testApp::draw() {
  levels.draw();
  if (doDrawInfo) {
    string s = "";
    s += "\nLevels (space to toggle info)";
    s += "\nbrightness (b/B) : " + ofToString(levels.brightness);
    s += "\ncontrast (c/C) : " + ofToString(levels.contrast);
    s += "\nsaturation (s/S) : " + ofToString(levels.saturation);
    s += "\ngamma (g/G) : " + ofToString(levels.gamma);
    ofDrawBitmapStringHighlight(s, 10, 10);
    ofDrawBitmapString(s, 10, 10);
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
  float step = .1;
  switch (key) {
  case 'B':
    levels.brightness += step;
    break;
  case 'b':
    levels.brightness -= step;
    break;
  case 'C':
    levels.contrast += step;
    break;
  case 'c':
    levels.contrast -= step;
    break;
  case 'S':
    levels.saturation += step;
    break;
  case 's':
    levels.saturation -= step;
    break;
  case 'G':
    levels.gamma += step;
    break;
  case 'g':
    levels.gamma -= step;
    break;
  case ' ':
    doDrawInfo = !doDrawInfo;
    break;
  }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {}
