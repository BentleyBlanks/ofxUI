#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		

		void guiEvent(ofxUIEventArgs &e);

		ofImage background, TattyUI;
		ofxUISuperCanvas *canvas, *canvas1, *radioCanvas;
		ofxUIButton *button, *button2, *button3, *button4, *button5;
		ofxUIButton *drakButton1, *drakButton2, *drakButton3, *drakButton4, *drakButton5;
		ofxUIButton *avaliableButton;

		ofxUIToggle *toggle1, *toggle2, *toggle3;

		ofxUISlider *slider;
		ofxUIButton *sliderButton;

		ofxUIRangeSlider *rangeSlider, *bigRangeSlider;
		ofxUIButton *buttonLow, *buttonHigh, *bigButtonLow, *bigButtonHigh;

		ofxUIRadio *radio;

};
