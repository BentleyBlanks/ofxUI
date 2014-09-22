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

#include "ofxUIRadio.h"
//
//ofxUIRadio::ofxUIRadio(string _name, int _orientation, float w, float h, float x = 0, float y = 0, int _size = OFX_UI_FONT_SMALL)
//{
//	// 空toggles名字集
//	vector<string> name;
//
//	init(_name, name, _orientation, w, h, x, y, _size);
//}

ofxUIRadio::ofxUIRadio(string _name, vector<string> names, int _orientation, float w, float h, float x, float y, int _size) : ofxUIWidget()
{
    init(_name, names, _orientation, w, h, x, y, _size);
}

void ofxUIRadio::init(string _name, vector<string> names, int _orientation, float w, float h, float x, float y, int _size)
{
    initRect(x,y,w,h);
    name = string(_name);
    kind = OFX_UI_WIDGET_RADIO;
    
    draw_back = false;
    orientation = _orientation;
    
    value = -1;
    
    if(names.size() == 0)
    {
        setEmbedded(true);
    }
    else
    {
        for(unsigned int i = 0; i < names.size(); i++)
        {
            string tname = names[i];
            ofxUIToggle *toggle = new ofxUIToggle(tname, false, w, h, 0, 0, _size);
            addEmbeddedWidget(toggle);
            toggles.push_back(toggle);            
        }
    }
    
    active = NULL;
	// --!
	spacing = 0;
}

void ofxUIRadio::setVisible(bool _visible)
{
    visible = _visible;
    for(unsigned int i = 0; i < toggles.size(); i++)
    {
        ofxUIToggle *t = toggles[i];
        t->setVisible(visible);
    }
}
void ofxUIRadio::activateToggle(string _name)
{
    for(unsigned int i = 0; i < toggles.size(); i++)
    {
        ofxUIToggle *t = toggles[i];
		// 给定名称来设定激活开关
        if(t->getName() == _name)
        {
            t->setValue(true);
            active = t;
            value = i;
        }
        else
        {
            t->setValue(false);
        }
    }
}

void ofxUIRadio::triggerSelf()
{
    if(parent != NULL)
    {
        parent->triggerEvent(this);
        parent->triggerEvent(active);
    }
}

void ofxUIRadio::setParent(ofxUIWidget *_parent)
{
    parent = _parent;
    
    float tWidth = 0;
    float tHeight = 0;
    
    float xt = 0;
    float yt = 0;
    
    for(unsigned int i = 0; i < toggles.size(); i++)
    {
		// toggle合集父类为radio
        ofxUIToggle *t = toggles[i];
        t->setParent(this);
        t->setRectParent(this->getRect());
        if(orientation == OFX_UI_ORIENTATION_HORIZONTAL)
        {
            t->getRect()->x = xt;
            t->getRect()->y = 0;
			// 统计最大宽度
            xt+=t->getPaddingRect()->width;
            tHeight = t->getPaddingRect()->height;
        }
        else
        {
            t->getRect()->x = 0;
            t->getRect()->y = yt;
            if(t->getPaddingRect()->width > tWidth)
            {
                tWidth = t->getPaddingRect()->width;
            }
            tHeight+=t->getPaddingRect()->getHeight();
            yt +=t->getPaddingRect()->getHeight();
        }
    }
    
    if(orientation == OFX_UI_ORIENTATION_HORIZONTAL)
    {
        if(xt > tWidth)
        {
            tWidth = xt;
        }
    }
    rect->setWidth(tWidth - padding);
    rect->setHeight(tHeight - padding*2.0);
    calculatePaddingRect();
}

vector<ofxUIToggle *> ofxUIRadio::getToggles()
{
    return toggles;
}

ofxUIToggle* ofxUIRadio::getActive()
{
    return active;
}

void ofxUIRadio::triggerEvent(ofxUIWidget *child)
{
    activateToggle(child->getName());
    triggerSelf();
}
   
void ofxUIRadio::addToggle(ofxUIToggle *toggle)
{
	toggles.push_back(toggle);

	toggle->setParent(this);

	// 外部添加的toggle已为激活状态
	if(toggle->getValue())
	{
		activateToggle(toggle->getName());
	}
}

void ofxUIRadio::setAABB(int x, int y, int width, int height)
{
	for(int i=0; i<toggles.size(); i++)
	{
		if(i == 0)
			toggles[i]->setAABB(x, y, width, height);
		else
		// radioAABB的宽高作为每个toggle的宽高
			toggles[i]->setAABB(0, 0, width, height);
	}

	ofxUIWidget::setAABB(x, y, width, height);
}

void ofxUIRadio::setFrameAnimationPosition(ofPoint position)
{
	// radio的position作为第一个toggle的初始位置
	if(toggles.size() != 0)
		toggles[0]->setFrameAnimationPosition(position);

	ofxUIWidget::setFrameAnimationPosition(position);
}

int ofxUIRadio::getValue()
{
	return value;
}

string ofxUIRadio::getActiveName()
{
	if(active != NULL)
	{
		return active->getName();
	}
	return ""; 
}

void ofxUIRadio::loadImageOfOnHover(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOnHover(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::loadImageOfOnNormal(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOnNormal(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::loadImageOfOnPressed(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOnPressed(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::loadImageOfOffHover(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOffHover(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::loadImageOfOffNormal(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOffNormal(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::loadImageOfOffPressed(string path, string folderName, string suffixFormat, int sumNumber)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->loadImageOfOffPressed(path, folderName, suffixFormat, sumNumber);
	}
}

void ofxUIRadio::setDrawMode(ofxUIDrawMode drawMode)
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->setDrawMode(drawMode);
	}

	ofxUIWidget::setDrawMode(drawMode);
}


void ofxUIRadio::setSpacing(int spacing)
{
	this->spacing = spacing;
}


void ofxUIRadio::autoFrameAnimationSize()
{
	int toggleWidth = rect->width, toggleHeight = rect->height;

	int x = position->x, y = position->y;

	int leftWidth = 0, leftHeight = 0;

	int n = toggles.size();

	if(n != 0)
	{
		// AABB左上角与帧动画左上角的差
		leftWidth = getRect()->x - toggles[0]->getFrameAnimationPosition()->x;
		leftHeight = getRect()->y - toggles[0]->getFrameAnimationPosition()->y;
	}
	else
		return;

	for(int i=0; i<n; i++)
	{
		ofxUIToggle *toggle = toggles[i];

		if(orientation == OFX_UI_ORIENTATION_HORIZONTAL)
		{
			toggle->setFrameAnimationPosition(ofPoint(x, y));
			toggle->setAABB(x + leftWidth, y, toggleWidth, toggleHeight);

			x += leftWidth + toggleWidth + spacing;
		}
		else
		{
			toggle->setFrameAnimationPosition(ofPoint(x, y));
			toggle->setAABB(x, y+leftHeight, toggleWidth, toggleHeight);

			y += leftHeight + toggleHeight + spacing;
		}
	}

	// 统计radio的总宽高
	if(orientation == OFX_UI_ORIENTATION_HORIZONTAL)
	{
		width = (n-1)*spacing + n*leftWidth + n*toggleWidth;
		height = toggleHeight;
	}
	else
	{
		width = toggleWidth;
		height = (n-1)*spacing + n*leftHeight + n*toggleHeight;
	}
}


int ofxUIRadio::getRadioWidth()
{
	return this->width;
}

int ofxUIRadio::getRadioHeight()
{
	return this->height;
}

void ofxUIRadio::drawFrameAnimation()
{
	for(int i=0; i<toggles.size(); i++)
	{
		toggles[i]->drawFrameAnimation();
	}
}