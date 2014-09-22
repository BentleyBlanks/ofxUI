#include "ofxUIWindowCanvas.h"

ofxUIWindowCanvas::ofxUIWindowCanvas(string _label, float x, float y, float w, float h, int _size):ofxUISuperCanvas(_label, x, y, w, h, _size)
{
	setBokehColor(ofxUIColor(50, 200));
	//okay = addButton("okay", false);
	//// ������ʾ���±�
	//okay->setLabelPosition(OFX_UI_WIDGET_POSITION_DOWN);
}

ofxUIWindowCanvas::ofxUIWindowCanvas(string _label, int _size):ofxUISuperCanvas(_label, _size)
{
	setBokehColor(ofxUIColor(50, 200));
}

void ofxUIWindowCanvas::draw()
{
	ofxUIPushStyle();
	
	ofxUIPushStyle();
	// ��Ϯcanvas�ķ�� ֻ����һ�����������
	ofSetColor(bokeh_color);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	ofxUIPopStyle();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glEnable(GL_BLEND);
#ifndef OFX_UI_TARGET_TOUCH
    glBlendEquation(GL_FUNC_ADD);
#endif
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ofxUISetRectMode(OFX_UI_RECTMODE_CORNER);
	ofxUISetLineWidth(1.0);

	// --!ֻ����Canvas���Ի��ƲŻ����
	if(isDrawable())
	{
		ofxUIPushStyle();

		drawPadded();
		drawPaddedOutline();
		drawBack();
		drawFill();
		drawFillHighlight();
		drawOutline();
		drawOutlineHighlight();

		ofxUIPopStyle();
	}

	// ���������ӿؼ� 
	vector<ofxUIWidget *>::reverse_iterator it = widgets.rbegin();
	vector<ofxUIWidget *>::reverse_iterator eit = widgets.rend();

	for(; it != eit; ++it) {
		// ԭ��Ϊ((*it)->isVisible() && ((*it)->getRect()->rInside(*rect) || (*it)->isModal()))
		// --!���ӿؼ���λ����frameAnimation״̬��������ָ�� ��� �����Ƿ���Canvas��rect�ڽ����ж�
		if((*it)->getDrawMode() == OFX_UI_DRAW_FRAMEANIMATION)
		{
			//if((*it)->isVisible() && ((*it)->getRect()->rInside(*rect) || (*it)->isModal())) {
			//	(*it)->draw();
			//}
			if((*it)->isVisible()) {
				(*it)->draw();
			}

		}
		else
		{
			if((*it)->isVisible()) {
				(*it)->draw();
			}
		}
	}

	ofxUIPopStyle();
}


// ������͸��ɫ
void ofxUIWindowCanvas::setBokehColor(ofxUIColor bokeh_color)
{
	this->bokeh_color = bokeh_color;
}

// ��Ӱ�ťѡ��
void ofxUIWindowCanvas::addSelectionButton()
{
	ofxUIButton *button;
	button = addButton("Okay", false);
	button->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION);
	button->setFrameAnimationPosition(ofPoint(getRect()->x + getRect()->width * 0.5 - 150, getRect()->y + getRect()->height * 0.8));
	button->setAABB(getRect()->x  + getRect()->width * 0.5 - 150, getRect()->y + getRect()->height * 0.8, 300, 40);
	// Ĭ�ϵİ�ť��ʽ
	button->loadImageOfHover("window/selectionOkay/", "hover", "png", 1);
	button->loadImageOfNormal("window/selectionOkay/", "normal", "png", 1);
	button->loadImageOfPressed("window/selectionOkay/", "pressed", "png", 1);
	button->getLabelWidget()->setVisible(false);
}