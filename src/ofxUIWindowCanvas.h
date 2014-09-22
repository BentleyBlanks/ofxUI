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
	// 背景半透明色
	void setBokehColor(ofxUIColor bokeh_color);

	// 添加按钮选项
	void addSelectionButton();

protected:
	// 背景虚化颜色这遮罩
	ofxUIColor bokeh_color;
	//// 确认和取消按钮
	//ofxUIButton *okay;
};