#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60.0f);
	canvas = new ofxUISuperCanvas("");
	canvas1 = new ofxUISuperCanvas("");
	radioCanvas = new ofxUISuperCanvas("");

	background.loadImage("background.png");
	TattyUI.loadImage("TattyUI.png");

	int blueX = 140, blueY = 290;
	int deltaX = 100;
	int offsetX = 50, offsetY = 50;
	int blueWidth = 34, blueHeight = 34;

	int darkX = 141, darkY = 390;
	int deltaDarkX = 100;

	canvas->setDrawable(false);
	canvas1->setDrawable(false);
	radioCanvas->setDrawable(false);
	// 分两页
	canvas->setVisible(true);
	canvas1->setVisible(false);
	radioCanvas->setVisible(true);

	button = canvas->addButton("blueAddButton", false);
	button->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	button->setFrameAnimationPosition(ofPoint(blueX + deltaX, blueY));
	button->setAABB(blueX + deltaX + offsetX, blueY + offsetY, blueWidth, blueHeight);
	button->loadImageOfHover("blueAddButton/", "hover", "png", 1);
	button->loadImageOfNormal("blueAddButton/", "normal", "png", 1);
	button->loadImageOfPressed("blueAddButton/", "pressed", "png", 1);

	button2 = canvas->addButton("blueRemoveButton", false);
	button2->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	button2->setFrameAnimationPosition(ofPoint(blueX + deltaX*2, blueY));
	button2->setAABB(blueX + deltaX*2 + offsetX, blueY + offsetY, blueWidth, blueHeight);
	button2->loadImageOfHover("blueRemoveButton/", "hover", "png", 1);
	button2->loadImageOfNormal("blueRemoveButton/", "normal", "png", 1);
	button2->loadImageOfPressed("blueRemoveButton/", "pressed", "png", 1);


	button3 = canvas->addButton("blueCloseButton", false);
	button3->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	button3->setFrameAnimationPosition(ofPoint(blueX + deltaX*3, blueY));
	button3->setAABB(blueX + deltaX*3 + offsetX, blueY + offsetY, blueWidth, blueHeight);
	button3->loadImageOfHover("blueCloseButton/", "hover", "png", 1);
	button3->loadImageOfNormal("blueCloseButton/", "normal", "png", 1);
	button3->loadImageOfPressed("blueCloseButton/", "pressed", "png", 1);


	button4 = canvas->addButton("blueCheckmarkButton", false);
	button4->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	button4->setFrameAnimationPosition(ofPoint(blueX + deltaX*4, blueY));
	button4->setAABB(blueX + deltaX*4 + offsetX, blueY + offsetY, blueWidth, blueHeight);
	button4->loadImageOfHover("blueCheckmarkButton/", "hover", "png", 1);
	button4->loadImageOfNormal("blueCheckmarkButton/", "normal", "png", 1);
	button4->loadImageOfPressed("blueCheckmarkButton/", "pressed", "png", 1);


	button5 = canvas->addButton("blueSearchButton", false);
	button5->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	button5->setFrameAnimationPosition(ofPoint(blueX + deltaX*5, blueY));
	button5->setAABB(blueX + deltaX*5 + offsetX, blueY + offsetY, blueWidth, blueHeight);
	button5->loadImageOfHover("blueSearchButton/", "hover", "png", 1);
	button5->loadImageOfNormal("blueSearchButton/", "normal", "png", 1);
	button5->loadImageOfPressed("blueSearchButton/", "pressed", "png", 1);




	int darkOffsetX = 3, drawOffsetY = 3;
	drakButton5 = canvas->addButton("darkAddButton", false);
	drakButton5->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	drakButton5->setFrameAnimationPosition(ofPoint(darkX + deltaDarkX + darkOffsetX, darkY + drawOffsetY));
	drakButton5->setAABB(darkX + deltaDarkX + offsetX, darkY + offsetY, blueWidth, blueHeight);
	drakButton5->loadImageOfHover("darkAddButton/", "hover", "png", 1);
	drakButton5->loadImageOfNormal("darkAddButton/", "normal", "png", 1);
	drakButton5->loadImageOfPressed("darkAddButton/", "pressed", "png", 1);


	drakButton4 = canvas->addButton("drakRemoveButton", false);
	drakButton4->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	drakButton4->setFrameAnimationPosition(ofPoint(darkX + deltaDarkX*2 + darkOffsetX, darkY + drawOffsetY));
	drakButton4->setAABB(darkX + deltaDarkX*2 + offsetX, darkY + offsetY, blueWidth, blueHeight);
	cout << darkY + drawOffsetY;
	drakButton4->loadImageOfHover("drakRemoveButton/", "hover", "png", 1);
	drakButton4->loadImageOfNormal("drakRemoveButton/", "normal", "png", 1);
	drakButton4->loadImageOfPressed("drakRemoveButton/", "pressed", "png", 1);


	drakButton3 = canvas->addButton("darkCloseButton", false);
	drakButton3->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	drakButton3->setFrameAnimationPosition(ofPoint(darkX + deltaDarkX*3 + darkOffsetX, darkY + drawOffsetY));
	drakButton3->setAABB(darkX + deltaDarkX*3 + offsetX, darkY + offsetY, blueWidth, blueHeight);
	drakButton3->loadImageOfHover("darkCloseButton/", "hover", "png", 1);
	drakButton3->loadImageOfNormal("darkCloseButton/", "normal", "png", 1);
	drakButton3->loadImageOfPressed("darkCloseButton/", "pressed", "png", 1);


	drakButton2 = canvas->addButton("darkCheckmarkButton", false);
	drakButton2->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	drakButton2->setFrameAnimationPosition(ofPoint(darkX + deltaDarkX*4 + darkOffsetX, darkY + drawOffsetY));
	drakButton2->setAABB(darkX + deltaDarkX*4 + offsetX, darkY + offsetY, blueWidth, blueHeight);
	drakButton2->loadImageOfHover("darkCheckmarkButton/", "hover", "png", 1);
	drakButton2->loadImageOfNormal("darkCheckmarkButton/", "normal", "png", 1);
	drakButton2->loadImageOfPressed("darkCheckmarkButton/", "pressed", "png", 1);


	drakButton1 = canvas->addButton("darkSearchButton", false);
	drakButton1->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	drakButton1->setFrameAnimationPosition(ofPoint(darkX + deltaDarkX*5 + darkOffsetX, darkY + drawOffsetY));
	drakButton1->setAABB(darkX + deltaDarkX*5 + offsetX, darkY + offsetY, blueWidth, blueHeight);
	drakButton1->loadImageOfHover("darkSearchButton/", "hover", "png", 1);
	drakButton1->loadImageOfNormal("darkSearchButton/", "normal", "png", 1);
	drakButton1->loadImageOfPressed("darkSearchButton/", "pressed", "png", 1);




	//avaliableButton = canvas->addButton("avaliableOnTheAppStore", false);
	//avaliableButton->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	//avaliableButton->setFrameAnimationPosition(ofPoint(384, 680));
	//avaliableButton->setAABB(393, 693, 263, 70);
	//avaliableButton->loadImageOfHover("avaliableOnTheAppStore/", "hover", "png", 13);
	//avaliableButton->loadImageOfNormal("avaliableOnTheAppStore/", "normal", "png", 1);
	//avaliableButton->loadImageOfPressed("avaliableOnTheAppStore/", "pressed", "png", 1);



	int toggleWidth = 74, toggleHeight = 27;
	int toggleX = 325, toggleY = 560;
	int toggleDeltaX = 150;

	toggle1 = canvas->addToggle("toggle", false);
	toggle1->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	toggle1->setFrameAnimationPosition(ofPoint(toggleX, toggleY));
	toggle1->setAABB(toggleX, toggleY, toggleWidth, toggleHeight);
	// on
	toggle1->loadImageOfOnHover("switchToggleButton/", "on_hover", "png", 1);
	toggle1->loadImageOfOnNormal("switchToggleButton/", "on_normal", "png", 1);
	toggle1->loadImageOfOnPressed("switchToggleButton/", "on_pressed", "png", 1);
	// off
	toggle1->loadImageOfOffHover("switchToggleButton/", "off_hover", "png", 1);
	toggle1->loadImageOfOffNormal("switchToggleButton/", "off_normal", "png", 1);
	toggle1->loadImageOfOffPressed("switchToggleButton/", "off_pressed", "png", 1);

	
	toggle2 = canvas->addToggle("toggle", false);
	toggle2->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	toggle2->setFrameAnimationPosition(ofPoint(toggleX + toggleDeltaX, toggleY));
	toggle2->setAABB(toggleX + toggleDeltaX, toggleY, toggleWidth, toggleHeight);
	// on
	toggle2->loadImageOfOnHover("switch2ToggleButton/", "on_hover", "png", 1);
	toggle2->loadImageOfOnNormal("switch2ToggleButton/", "on_normal", "png", 1);
	toggle2->loadImageOfOnPressed("switch2ToggleButton/", "on_pressed", "png", 1);
	// off
	toggle2->loadImageOfOffHover("switch2ToggleButton/", "off_hover", "png", 1);
	toggle2->loadImageOfOffNormal("switch2ToggleButton/", "off_normal", "png", 1);
	toggle2->loadImageOfOffPressed("switch2ToggleButton/", "off_pressed", "png", 1);


	
	toggle3 = canvas->addToggle("toggle", false);
	toggle3->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	toggle3->setFrameAnimationPosition(ofPoint(toggleX + toggleDeltaX*2, toggleY));
	toggle3->setAABB(toggleX + toggleDeltaX*2, toggleY, toggleWidth, toggleHeight);
	// on
	toggle3->loadImageOfOnHover("switch3ToggleButton/", "on_hover", "png", 1);
	toggle3->loadImageOfOnNormal("switch3ToggleButton/", "on_normal", "png", 1);
	toggle3->loadImageOfOnPressed("switch3ToggleButton/", "on_pressed", "png", 1);
	// off
	toggle3->loadImageOfOffHover("switch3ToggleButton/", "off_hover", "png", 1);
	toggle3->loadImageOfOffNormal("switch3ToggleButton/", "off_normal", "png", 1);
	toggle3->loadImageOfOffPressed("switch3ToggleButton/", "off_pressed", "png", 1);


	int sliderX = ofGetWidth()/2 - 145, sliderY = ofGetHeight()/2;
	int rangeSliderX = ofGetWidth()/2 - 150, rangeSliderY = ofGetHeight()/2 + 70;
	int sliderOffsetX = 3, sliderOffsetY = 3;

	// slider
	sliderButton = new ofxUIButton("sliderButton", false, 20, 20);
	sliderButton->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	sliderButton->setFrameAnimationPosition(ofPoint(sliderX, sliderY));
	sliderButton->setAABB(sliderX+sliderOffsetX, sliderY+sliderOffsetY, 20, 20);
	sliderButton->loadImageOfHover("slider/", "button", "png", 1);
	sliderButton->loadImageOfNormal("slider/", "button", "png", 1);
	sliderButton->loadImageOfPressed("slider/", "button", "png", 1);

	
	slider = canvas1->addSlider("slider", 0.0f, 10.0f, 2.0f);
	slider->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	slider->setFrameAnimationPosition(ofPoint(sliderX, sliderY));
	slider->setAABB(sliderX, sliderY, 290, 20);
	slider->loadImageOfDownBackground("slider/", "downBackground", "png", 1);
	slider->loadImageOfUpBackground("slider/", "upBackground", "png", 1);
	slider->setButton(sliderButton);


	//rangeSlider
	buttonLow = new ofxUIButton("buttonLow", false, 20, 20);
	buttonLow->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	buttonLow->setFrameAnimationPosition(ofPoint(rangeSliderX, rangeSliderY));
	buttonLow->setAABB(rangeSliderX+sliderOffsetX, rangeSliderY+sliderOffsetY, 20, 20);
	buttonLow->loadImageOfHover("rangeSlider/", "buttonLow", "png", 1);
	buttonLow->loadImageOfNormal("rangeSlider/", "buttonLow", "png", 1);
	buttonLow->loadImageOfPressed("rangeSlider/", "buttonLow", "png", 1);

	buttonHigh = new ofxUIButton("buttonHigh", false, 20, 20);
	buttonHigh->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	buttonHigh->setFrameAnimationPosition(ofPoint(rangeSliderX, rangeSliderY));
	buttonHigh->setAABB(rangeSliderX+sliderOffsetX, rangeSliderY+sliderOffsetY, 20, 20);
	buttonHigh->loadImageOfHover("rangeSlider/", "buttonHigh", "png", 1);
	buttonHigh->loadImageOfNormal("rangeSlider/", "buttonHigh", "png", 1);
	buttonHigh->loadImageOfPressed("rangeSlider/", "buttonHigh", "png", 1);


	rangeSlider = canvas1->addRangeSlider("rangeSlider", 0, 20, 2, 14);
	rangeSlider->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	rangeSlider->setFrameAnimationPosition(ofPoint(rangeSliderX, rangeSliderY));
	rangeSlider->setAABB(rangeSliderX, rangeSliderY+sliderOffsetY, 300, 20);
	rangeSlider->loadImageOfDownBackground("rangeSlider/", "downBackground", "png", 1);
	rangeSlider->loadImageOfUpBackground("rangeSlider/", "upBackground", "png", 1);

	rangeSlider->setButton(buttonLow, buttonHigh);


	// radio
	vector<string> name;
	name.push_back("radio1");
	name.push_back("radio2");
	name.push_back("radio3");
	name.push_back("radio4");
	name.push_back("radio5");
	name.push_back("radio6");
	name.push_back("radio7");

	radio = radioCanvas->addRadio("radio", name, OFX_UI_ORIENTATION_HORIZONTAL);
	radio->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	radio->setFrameAnimationPosition(ofPoint(ofGetWidth()/2 - 130, 700));
	// 第一个toggle的AABB
	radio->setAABB(ofGetWidth()/2 - 130, 720, 20, 20);
		// 设置间距
	radio->setSpacing(20);
	// 自动排版radio当中的toggle
	radio->autoFrameAnimationSize();

	radio->loadImageOfOffHover("radio/", "off_hover", "png", 1);
	radio->loadImageOfOffNormal("radio/", "off_normal", "png", 1);
	radio->loadImageOfOffPressed("radio/", "off_pressed", "png", 1);

	radio->loadImageOfOnHover("radio/", "on_hover", "png", 1);
	radio->loadImageOfOnNormal("radio/", "on_normal", "png", 1);
	radio->loadImageOfOnPressed("radio/", "on_pressed", "png", 1);


	// 存在较为严重的设计缺陷
	//bigButtonLow = new ofxUIButton("bigButtonLow", false, 20, 20);
	//bigButtonLow->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	//bigButtonLow->setFrameAnimationPosition(ofPoint(25, 104));
	//bigButtonLow->setAABB(28, 107, 20, 20);
	//bigButtonLow->loadImageOfHover("bigRangeSlider/", "buttonLow", "png", 1);
	//bigButtonLow->loadImageOfNormal("bigRangeSlider/", "buttonLow", "png", 1);
	//bigButtonLow->loadImageOfPressed("bigRangeSlider/", "buttonLow", "png", 1);

	//bigButtonHigh = new ofxUIButton("bigButtonHigh", false, 20, 20);
	//bigButtonHigh->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	//bigButtonHigh->setFrameAnimationPosition(ofPoint(25, 104));
	//bigButtonHigh->setAABB(28, 107, 20, 20);
	//bigButtonHigh->loadImageOfHover("bigRangeSlider/", "buttonHigh", "png", 1);
	//bigButtonHigh->loadImageOfNormal("bigRangeSlider/", "buttonHigh", "png", 1);
	//bigButtonHigh->loadImageOfPressed("bigRangeSlider/", "buttonHigh", "png", 1);


	//bigRangeSlider = canvas->addRangeSlider("bigRangeSlider", 0, 20, 2, 14);
	//bigRangeSlider->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
	//bigRangeSlider->setFrameAnimationPosition(ofPoint(10, 80));
	//bigRangeSlider->setAABB(25, 110, 343, 7);
	//bigRangeSlider->loadImageOfDownBackground("bigRangeSlider/", "downBackground", "png", 1);
	//bigRangeSlider->loadImageOfUpBackground("bigRangeSlider/", "upBackground", "png", 1);

	//bigRangeSlider->setButton(bigButtonLow, bigButtonHigh);

	ofAddListener(canvas->newGUIEvent, this, &ofApp::guiEvent);
	ofAddListener(radioCanvas->newGUIEvent, this, &ofApp::guiEvent);
	ofAddListener(canvas1->newGUIEvent, this, &ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
	//static float value = 0.1;
	//value += 0.01f;
	//slider->setValue(value);
}

//--------------------------------------------------------------
void ofApp::draw(){
	background.draw(0, 0);
	TattyUI.draw(248, 20);

	// 中轴线
	//ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
	//ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);

	//ofNoFill();
	//ofRect(23, 111, 301, 7);
}


void ofApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.getName();

	if(name == "radio1")
	{
		canvas->setVisible(true);
		canvas1->setVisible(false);
	}
	else if(name == "radio2")
	{
		canvas->setVisible(false);
		canvas1->setVisible(true);
	}

	cout << name << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
