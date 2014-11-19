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
	// ±≥æ∞∞ÎÕ∏√˜…´
	void setBokehColor(ofxUIColor bokeh_color);

	// ÃÌº”∞¥≈•—°œÓ
	void addSelectionButton();

protected:
	// ±≥æ∞–ÈªØ—’…´’‚’⁄’÷
	ofxUIColor bokeh_color;
	//// »∑»œ∫Õ»°œ˚∞¥≈•
	//ofxUIButton *okay;
};