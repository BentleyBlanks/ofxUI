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

#include "ofxUILabel.h"
#include "ofxUI.h"

ofxUILabel::ofxUILabel() : ofxUIWidget()
{
	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float x, float y, string _name, string _label, int _size) : ofxUIWidget()
{
	init(x, y, 0, 0, _name, _label, _size);
	autoSize = true;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float x, float y, string _name, int _size) : ofxUIWidget()
{
	init(x, y, 0, 0, _name, _name, _size);
	autoSize = true;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(string _name, string _label, int _size) : ofxUIWidget()
{
	init(0, 0, 0, 0, _name, _label, _size);
	autoSize = true;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(string _name, int _size) : ofxUIWidget()
{
	init(0, 0, 0, 0, _name, _name, _size);
	autoSize = true;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float x, float y, float w, string _name, string _label, int _size) : ofxUIWidget()
{
	init(x, y, w, 0, _name, _label, _size);
	autoSize = false;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float x, float y, float w, string _name, int _size) : ofxUIWidget()
{
	init(x, y, w, 0, _name, _name, _size);
	autoSize = false;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float w, string _name, string _label, int _size) : ofxUIWidget()
{
	init(0, 0, w, 0, _name, _label, _size);
	autoSize = false;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float w, string _name, int _size) : ofxUIWidget()
{
	init(0, 0, w, 0, _name, _name, _size);
	autoSize = false;

	//bDrawString = true;
}

ofxUILabel::ofxUILabel(float w, string _name, int _size, float h) : ofxUIWidget()
{
	init(0, 0, w, h, _name, _name, _size);
	autoSize = false;

	//bDrawString = true;
}

void ofxUILabel::init(float x, float y, float w, float h, string _name, string _label, int _size)
{
	initRect(x,y,w,h);
	name = string(_name);
	kind = OFX_UI_WIDGET_LABEL;
	label = string(_label);
	size = _size;

	font = NULL;
	draw_back = OFX_UI_LABEL_DRAW_BACK;
	draw_fill = true;
}

void ofxUILabel::drawBack()
{
	if(draw_back)
	{
		drawBackLabel();
	}
}

void ofxUILabel::drawFill()
{
	if(draw_fill)
	{
		ofxUIFill();
		ofxUISetColor(color_fill);

		// --!
		int px=0, py=0;
		ofxUIRectangle* parentRect = rect;
		// 循环到canvas的上一层
		while(parentRect->getParent() != NULL)
		{
			px += parentRect->x;
			py += parentRect->y;

			parentRect = parentRect->getParent();
		}

		font->drawString(label, floor(px)+xOffset, floor(py+rect->getHeight())+yOffset);

		//font->drawString(label, floor(rect->x)+xOffset, floor(rect->y+rect->getHeight())+yOffset);

		// getX()和getY()并非实际意义上的xy 而是加了parent之后的坐标
		//cout << label << floor(rect->getX()) << ", " << floor(rect->getY()) << endl;
		//drawStringShadow(floor(rect->getX())+xOffset, floor(rect->getY()+rect->getHeight())+yOffset, label);
	}
}

void ofxUILabel::drawFillHighlight()
{
	if(draw_fill_highlight)
	{
		ofxUIFill();
		ofxUISetColor(color_fill_highlight);

		// --!
		int px=0, py=0;
		ofxUIRectangle* parentRect = rect;
		// 循环到canvas的上一层
		while(parentRect->getParent() != NULL)
		{
			px += parentRect->x;
			py += parentRect->y;

			parentRect = parentRect->getParent();
		}

		font->drawString(label, floor(px)+xOffset, floor(py+rect->getHeight())+yOffset);
	}
}

void ofxUILabel::drawBackLabel()
{
	ofxUIFill();
	ofxUISetColor(color_back);

	// --!
	int px=0, py=0;
	ofxUIRectangle* parentRect = rect;
	// 循环到canvas的上一层
	while(parentRect->getParent() != NULL)
	{
		px += parentRect->x;
		py += parentRect->y;

		parentRect = parentRect->getParent();
	}

	//if(bDrawString == true)
	font->drawString(label, floor(px)+1+xOffset, floor(py+rect->getHeight())+1+yOffset);
}

void ofxUILabel::drawString(float x, float y, string _string)
{
	// --!外部调用此函数就直接覆盖bDrawString
	//bDrawString = true;
	font->drawString(_string, floor(x), floor(y));
}

void ofxUILabel::drawStringShadow(float x, float y, string _string)
{
	ofxUIFill();
	ofxUISetColor(color_back);
	// --!ofxUI只是ofTrueTypeFont的别称
	// --!floor()返回小于或者等于指定表达式的最大整数 即向上取整
	//if(bDrawString == true)
	font->drawString(_string, floor(x)+1, floor(y)+1);
}

float ofxUILabel::getStringWidth(string s)
{
	return font->stringWidth(s);
}

float ofxUILabel::getStringHeight(string s)
{
	return font->stringHeight(s);
}

float ofxUILabel::getLineHeight()
{
	return font->getLineHeight();
}

ofxUILabel* ofxUILabel::getLabelWidget()
{
	return this;
}

void ofxUILabel::setLabel(string _label)
{
	label = string(_label);
	if(autoSize)
	{
		float w = font->stringWidth(label);
		float h = font->stringHeight("1");          //otherwise we get some funky non-uniform spacing :(
		rect->setWidth(w);
		rect->setHeight(h);
		xOffset = 0;
		yOffset = 0;
	}
	else
	{
		while(getStringWidth(label) > rect->getWidth()-padding*4.0 && label.size())
		{
			label = label.substr(0, label.size()-1);
		}
		float h = (int)font->stringHeight("1");     //otherwise we get some funky non-uniform spacing :(
		if(rect->getHeight() > 0)
		{
			yOffset = 0;
		}
		else
		{
			rect->setHeight(h);
			yOffset = 0;
		}
		xOffset = 0;
	}
}

bool ofxUILabel::getAutoSize()
{
	return autoSize;
}

void ofxUILabel::setAutoSize(bool _autoSize)
{
	autoSize = _autoSize;
}

string& ofxUILabel::getLabel()
{
	return label;
}

void ofxUILabel::setFont(ofxUIFont *_font)
{
	font = _font;
	setLabel(label);
	calculatePaddingRect();
}

int ofxUILabel::getSize()
{
	return size;
}

void ofxUILabel::focus()
{
	draw_fill_highlight = true;
	draw_fill = false;
}

void ofxUILabel::unfocus()
{
	draw_fill_highlight	= false;
	draw_fill = true;
}

void ofxUILabel::setVisible(bool _visible)
{
	visible = _visible;
	if(parent != NULL)
	{
		parent->calculatePaddingRect();
	}
}

bool ofxUILabel::isVisible()
{
	return visible;
}

void ofxUILabel::toggleVisible()
{
	setVisible(!visible);
}
