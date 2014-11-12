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
	// --!����һ�����Զ�����toggles�Ĺ��캯��
	//ofxUIRadio(string _name, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    ofxUIRadio(string _name, vector<string> names, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    void init(string _name, vector<string> names, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL);
    void setVisible(bool _visible);
	void activateToggle(string _name);
    void triggerSelf();
	void setParent(ofxUIWidget *_parent);

	vector<ofxUIToggle *> getToggles();
	// ��ǰѡ�е�toggle
	ofxUIToggle* getActive();
	string getActiveName();
	int getValue();

	void triggerEvent(ofxUIWidget *child);

	// --!�����п������һ��toggles�����е�Ԫ�ض�ָ��ͬһ���ڴ�ռ�
	void addToggle(ofxUIToggle *toggle);
	// �趨ÿ����toggle֮��ļ��
	void setSpacing(int spacing);
	// ��ȡradio��toggles���ܿ��
	int getRadioWidth();
	int getRadioHeight();

	// --!������ײ���ľ�������
	virtual void setAABB(int x, int y, int width, int height);
	virtual void setFrameAnimationPosition(ofPoint position);
	// --!�Զ��Ű�radio�е�toggle��
	void autoFrameAnimationSize();

	virtual void setDrawMode(ofxUIDrawMode drawMode);

	// --!����ԭ�������ӵ����޸���
	virtual void loadImageOfOnHover(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOnNormal(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOnPressed(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffHover(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffNormal(string path, string folderName, string suffixFormat, int sumNumber);
	virtual void loadImageOfOffPressed(string path, string folderName, string suffixFormat, int sumNumber);

	// --!��ʼ������������
	virtual void drawFrameAnimation();
    virtual void setFrameAnimationInterval(float interval = 1.0 / 13);

protected:
	int value; 
	int orientation; 
	vector<ofxUIToggle *> toggles; 		
    ofxUIToggle *active;     

	// toggle֮��ļ��
	int spacing;
	// radio��toggles���ܿ��(����AABB����)
	int width, height;
}; 