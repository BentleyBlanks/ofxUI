#pragma once
#include "ofMain.h"

class ofxUISuperCanvas;
class ofxUITattyXML
{
public:
	// ֻ��Ϊ����дһ�ζ����XML�������ļ̳�
	virtual void saveSettings(string fileName);
    virtual void loadSettings(string fileName);

private:
	vector<ofxUISuperCanvas> canvas;
};