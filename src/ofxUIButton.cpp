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

#include "ofxUIButton.h"
#include "ofxUI.h"

#include "ofxUIFrameAnimation.h"

ofxUIButton::ofxUIButton() : ofxUIWidgetWithLabel()
{
	// --!
	initFrameAnimation();
}

ofxUIButton::ofxUIButton(string _name, bool _value, float w, float h, float x, float y, int _size) : ofxUIWidgetWithLabel()
{
    useReference = false;
    init(_name, &_value, w, h, x, y, _size);

	// --!
	initFrameAnimation();
}

ofxUIButton::ofxUIButton(string _name, bool *_value, float w, float h, float x, float y, int _size) : ofxUIWidgetWithLabel()
{
    useReference = true;
    init(_name, _value, w, h, x, y, _size);

	// --!
	initFrameAnimation();
}

ofxUIButton::~ofxUIButton()
{
    if(!useReference)
    {
        delete value;
    }

	delete hover;
	delete normal;
	delete pressed;
}

void ofxUIButton::init(string _name, bool *_value, float w, float h, float x, float y, int _size)
{
    initRect(x,y,w,h);
    name = string(_name);
    kind = OFX_UI_WIDGET_BUTTON;
    label = new ofxUILabel((name+" LABEL"),name,_size);
    addEmbeddedWidget(label);
    
    labelPosition = OFX_UI_WIDGET_POSITION_RIGHT;
    
    if(useReference)
    {
        value = _value;
    }
    else
    {
        value = new bool();
        *value = *_value;
    }
    
    setValue(*_value);
}


void ofxUIButton::drawFrameAnimation()
{
	// 不同状态的不同帧动画
	switch (state)
	{
	case OFX_UI_STATE_UP:
	case OFX_UI_STATE_NORMAL:
		normal->drawCurrentFrame(*position);
		break;
	case OFX_UI_STATE_HOVER:
		hover->drawCurrentFrame(*position);
		break;
	case OFX_UI_STATE_DOWN:
		pressed->drawCurrentFrame(*position);
		break;
	}
}


void ofxUIButton::drawFill()
{
	// 是否填充
    if(*value)
    {
        ofxUIFill();
        ofxUISetColor(color_fill);
        rect->draw();
    }
}

void ofxUIButton::mouseMoved(int x, int y)
{
    if(rect->inside(x, y) || (label->isVisible() && label->getPaddingRect()->inside(x, y)))
    {
        state = OFX_UI_STATE_HOVER;
    }
    else
    {
        state = OFX_UI_STATE_NORMAL;
    }
    stateChange();
}

void ofxUIButton::mouseDragged(int x, int y, int button)
{
    if(hit)
    {
        if(rect->inside(x, y) || (label->isVisible() && label->getPaddingRect()->inside(x, y)))
        {
            state = OFX_UI_STATE_DOWN;
        }
        else
        {
            hit = false;
            state = OFX_UI_STATE_NORMAL;
            toggleValue();
            triggerEvent(this);
        }
        stateChange();
    }
}

void ofxUIButton::mousePressed(int x, int y, int button)
{
    if(rect->inside(x, y) || (label->isVisible() && label->getPaddingRect()->inside(x, y)))
    {
        hit = true;
		state = OFX_UI_STATE_DOWN;
		toggleValue();
		triggerEvent(this);
	}
    else
    {
        state = OFX_UI_STATE_NORMAL;
    }
    stateChange();
}

void ofxUIButton::mouseReleased(int x, int y, int button)
{
    if(hit)
    {
#ifdef OFX_UI_TARGET_TOUCH
        state = OFX_UI_STATE_NORMAL;
#else
		if(rect->inside(x, y) || (label->isVisible() && label->getPaddingRect()->inside(x, y)))
		{
			state = OFX_UI_STATE_UP;
		}
        else
        {
            state = OFX_UI_STATE_NORMAL;
        }
#endif
        toggleValue();
        triggerEvent(this);
    }
    else
    {
        state = OFX_UI_STATE_NORMAL;
    }
    stateChange();
    hit = false;
}

void ofxUIButton::stateChange()
{
    switch (state) {
        case OFX_UI_STATE_NORMAL:
        {
            draw_fill_highlight = false;
            draw_outline_highlight = false;
            label->unfocus();
        }
            break;
		case OFX_UI_STATE_UP:
        case OFX_UI_STATE_HOVER:
        {
            draw_fill_highlight = false;
            draw_outline_highlight = true;
            label->focus();
        }
            break;
        case OFX_UI_STATE_DOWN:
        {
            draw_fill_highlight = true;
            draw_outline_highlight = false;
            label->focus();
        }
            break;
        case OFX_UI_STATE_SUSTAINED:
        {
            draw_fill_highlight = false;
            draw_outline_highlight = false;
            label->unfocus();
        }
            break;
            
        default:
            break;
    }

	// 对三个帧动画重新计数
	hover->reset();
	normal->reset();
	pressed->reset();

	// 告知父类canvas当前控件状态发生改变
	notifyObserver();
}

void ofxUIButton::setParent(ofxUIWidget *_parent)
{
    parent = _parent;
    setLabelPosition(labelPosition);
}

bool ofxUIButton::getValue()
{
    return *value;
}
void ofxUIButton::setValue(bool _value)
{
    *value = _value;
    draw_fill = *value;
}

void ofxUIButton::setValuePtr(bool *_value)
{
    if(!useReference)
    {
        delete value;
        useReference = true;
    }
    value = _value;
    setValue(*value);
}

void ofxUIButton::toggleValue()
{
    setValue(!(*value));
}

bool ofxUIButton::isHit(float x, float y)
{
    if(visible)
    {
        return (rect->inside(x, y) || (label->isVisible() && label->getPaddingRect()->inside(x, y)));
    }
    else
    {
        return false;
    }
}

void ofxUIButton::setLabelPosition(ofxUIWidgetPosition pos)
{
    labelPosition = pos;
    switch (labelPosition)
    {
        case OFX_UI_WIDGET_POSITION_LEFT:
        {
            ofxUIRectangle *labelrect = label->getRect();
            float h = labelrect->getHeight();
            float ph = rect->getHeight();
            labelrect->setX(-label->getRect()->getWidth() - padding*2);
            labelrect->setY(ph/2.0 - h/2.0);
        }
            break;
            
        case OFX_UI_WIDGET_POSITION_RIGHT:
        {
            ofxUIRectangle *labelrect = label->getRect();
            float h = labelrect->getHeight();
            float ph = rect->getHeight();
            labelrect->setX(rect->getWidth()+padding);
            labelrect->setY(ph/2.0 - h/2.0);
        }
            break;
            
        case OFX_UI_WIDGET_POSITION_DOWN:
        {
            label->getRect()->setX(0);
            label->getRect()->setY(rect->getHeight() + padding);
        }
            break;
            
        case OFX_UI_WIDGET_POSITION_UP:
        {
            label->getRect()->setX(0);
			label->getRect()->setY(-label->getRect()->getHeight() - padding);
		}
		break;

		default:
			break;
	}
	calculatePaddingRect();
}

void ofxUIButton::loadImageOfHover(string path, string folderName, string suffixFormat, int sumNumber)
{
	hover->loadImages(path, folderName, suffixFormat, sumNumber);
}

void ofxUIButton::loadImageOfNormal(string path, string folderName, string suffixFormat, int sumNumber)
{
	normal->loadImages(path, folderName, suffixFormat, sumNumber);
}

void ofxUIButton::loadImageOfPressed(string path, string folderName, string suffixFormat, int sumNumber)
{
	pressed->loadImages(path, folderName, suffixFormat, sumNumber);
}

// 初始化三个动画管理器
void ofxUIButton::initFrameAnimation()
{
	// 倘若在构造函数中再定义hover,normal,pressed = NULL初始化的话则改动太多 
	// 不如直接使用 new 尽管
	//if(hover != NULL)
	//	delete hover;
	hover = new ofxUIFrameAnimation();

	//if(normal !=NULL)
	//	delete normal;
	normal = new ofxUIFrameAnimation();

	//if(pressed !=NULL)
	//	delete pressed;
	pressed = new ofxUIFrameAnimation();
}

void ofxUIButton::setFrameAnimationInterval(float interval)
{
    hover->setInterval(interval);
    
    normal->setInterval(interval);
    
    pressed->setInterval(interval);
}

