#pragma once
#include "ofMain.h"

class ofxUISuperCanvas;
class ofxUITattyXML
{
public:
	// 只是为了重写一次读入的XML而所做的继承
	virtual void saveSettings(string fileName);
    virtual void loadSettings(string fileName);

private:
	vector<ofxUISuperCanvas> canvas;
};