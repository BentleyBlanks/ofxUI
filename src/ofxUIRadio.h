/********************************************************************************** 
 
 Copyright (C) 2012 Syed Reza Ali (www.syedrezaali.com)
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 **********************************************************************************/

#pragma once

#include "ofxUIWidgetWithLabel.h"
#include "ofxUIDefines.h"
#include "ofxUIToggle.h"

class ofxUIRadio : public ofxUIWidget
{
public:
	// --!增加一个非自动创建toggles的构造函数
	//ofxUIRadio(string _name, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    ofxUIRadio(string _name, vector<string> names, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    void init(string _name, vector<string> names, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    void setVisible(bool _visible);
	void activateToggle(string _name);
    void triggerSelf();
	void setParent(ofxUIWidget *_parent);

	vector<ofxUIToggle *> getToggles();
	// 当前选中的toggle
	ofxUIToggle* getActive();
	string getActiveName();
	int getValue();

	void triggerEvent(ofxUIWidget *child);

	// --!这样有可能造成一个toggles集所有的元素都指向同一块内存空间
	void addToggle(ofxUIToggle *toggle);
	// 设定每两个toggle之间的间隔
	void setSpacing(int spacing);
	// 获取radio中toggles的总宽高
	int getRadioWidth();
	int getRadioHeight();

	// --!设置碰撞检测的矩形区域
	virtual void setAABB(int x, int y, int width, int height);
	virtual void setFrameAnimationPosition(ofPoint position);
	// --!自动排版radio中的toggle集
	void autoFrameAnimationSize();

	virtual void setDrawMode(ofxUIDrawMode drawMode);

	// --!尊重原作而增加的有限更改
	virtual void loadImageOfOnHover(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOnNormal(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOnPressed(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffHover(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffNormal(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffPressed(string path, string folderName, string suffixFormat, int sumNumber);

	// --!初始化动画管理器
	virtual void drawFrameAnimation();
    virtual void setFrameAnimationInterval(float interval = 1.0 / 13);

protected:
	int value; 
	int orientation; 
	vector<ofxUIToggle *> toggles; 		
    ofxUIToggle *active;     

	// toggle之间的间隔
	int spacing;
	// radio中toggles集总宽高(根据AABB计算)
	int width, height;
}; 