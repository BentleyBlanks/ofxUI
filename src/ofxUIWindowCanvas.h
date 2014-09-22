#pragma once

#include "ofMain.h"
#include "ofxUISuperCanvas.h"

class ofxUISuperCanvas;

class ofxUIWindowCanvas:public ofxUISuperCanvas
{
public:
	ofxUIWindowCanvas(string _label, int _size = OFX_UI_FONT_MEDIUM);
	ofxUIWindowCanvas(string _label, float x, float y, float w, float h, int _size = OFX_UI_FONT_MEDIUM);

	virtual void draw();
	// ������͸��ɫ
	void setBokehColor(ofxUIColor bokeh_color);

	// ��Ӱ�ťѡ��
	void addSelectionButton();

protected:
	// �����黯��ɫ������
	ofxUIColor bokeh_color;
	//// ȷ�Ϻ�ȡ����ť
	//ofxUIButton *okay;
};