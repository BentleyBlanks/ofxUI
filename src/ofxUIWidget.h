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

#include "ofxUIWrapper.h"
#include "ofxUIDefines.h"

#ifndef OFX_UI_NO_XML
    #include "ofxXmlSettings.h"
#endif 

class ofxUIFrameAnimation;
class ofxUICanvas;
<<<<<<< HEAD
class ofxUIMessage;
=======
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf

class ofxUIWidget           
{
public:
    ofxUIWidget();
    virtual ~ofxUIWidget();
    ofxUIWidget(const ofxUIWidget &other); // Mitchell Nordine 2/2/14
    virtual ofxUIWidget& operator=(const ofxUIWidget &other); // Mitchell Nordine 2/2/14
    
    virtual void initRect(float x = 0, float y = 0, float w = 0, float h = 0);
    virtual void initPaddingRect();
<<<<<<< HEAD
	// --!
	virtual void initFbo();
=======
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
    virtual void calculatePaddingRect();

    virtual void setup(); 
    virtual void update();
    virtual void draw();
   

    virtual void drawBack();
    virtual void drawOutline();
    virtual void drawOutlineHighlight();
    virtual void drawFill();
    virtual void drawFillHighlight();
    virtual void drawPadded();
    virtual void drawPaddedOutline();
    
#ifdef OFX_UI_TARGET_TOUCH
    void touchDown(float x, float y, int id);
    void touchMoved(float x, float y, int id);
    void touchUp(float x, float y, int id);
    void touchCancelled(float x, float y, int id);
    void touchDoubleTap(float x, float y, int id) {}
#endif

	virtual void mouseMoved(int x, int y ) {}
	virtual void mouseDragged(int x, int y, int button) {}
	virtual void mousePressed(int x, int y, int button) {}
	virtual void mouseReleased(int x, int y, int button) {}
    
	virtual void keyPressed(int key) {}
	virtual void keyReleased(int key) {}
	virtual void windowResized(int w, int h) {}           		
    
    void setTriggerType(ofxUITriggerType _triggerType);
    ofxUITriggerType getTriggerType();
    
<<<<<<< HEAD
	// --!新增绘制模式的getter/setter
	virtual void setDrawMode(ofxUIDrawMode drawMode);
	virtual ofxUIDrawMode getDrawMode();

	// 设置碰撞检测的矩形区域
=======
	// --!–¬‘ˆªÊ÷∆ƒ£ Ωµƒgetter/setter
	virtual void setDrawMode(ofxUIDrawMode drawMode);
	virtual ofxUIDrawMode getDrawMode();

	// …Ë÷√≈ˆ◊≤ºÏ≤‚µƒæÿ–Œ«¯”Ú
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	virtual void setAABB(int x, int y, int width, int height);
	virtual void setFrameAnimationPosition(ofPoint position);
    // --!限帧
    virtual void setFrameAnimationInterval(float interval = 1.0 / 13);
	virtual ofPoint* getFrameAnimationPosition();

	virtual void setParent(ofxUIWidget *_parent);
	virtual ofxUIWidget *getParent();

<<<<<<< HEAD
	// --!取这个名字其实我也不想的……实在是名字给它取走了又必须要兼容老版本
	void setCanvasController(ofxUICanvas* canvas);
	ofxUICanvas *getCanvasController();

	// 发布消息给观察者
	virtual void notifyObserver();

	// --!判断是否放入消息队列
	void updateMessage();
	// 并不安全！
	ofxUIMessage* getMessage();

=======
	// --!»°’‚∏ˆ√˚◊÷∆‰ µŒ““≤≤ªœÎµƒ°≠°≠ µ‘⁄ «√˚◊÷∏¯À¸»°◊ﬂ¡À”÷±ÿ–Î“™ºÊ»›¿œ∞Ê±æ
	void setCanvasController(ofxUICanvas* canvas);
	ofxUICanvas *getCanvasController();

	// ∑¢≤ºœ˚œ¢∏¯π€≤Ï’ﬂ
	virtual void notifyObserver();

>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	virtual void setName(string _name);
    virtual string& getName();
    
    virtual void setModal(bool _modal);
    virtual bool isModal();
	
    virtual void setVisible(bool _visible);
    virtual bool isVisible();
    virtual void toggleVisible();
	
    virtual void setEmbedded(bool _embedded);
    virtual bool isEmbedded();
    
    void setID(int _id);
    int getID();
    virtual void setKind(ofxUIWidgetType _kind);
    virtual ofxUIWidgetType getKind();
    
    virtual bool isDraggable();
    virtual bool hasLabel();

    virtual void triggerEvent(ofxUIWidget *child);
    virtual void triggerSelf();
    virtual void stateChange();
    virtual bool isHit(float x, float y);
    
    virtual void addWidget(ofxUIWidget *widget);
    virtual void removeWidget(ofxUIWidget *widget);
    
    virtual void addEmbeddedWidget(ofxUIWidget *widget);
    virtual void clearEmbeddedWidgets();
    virtual int getEmbeddedWidgetsSize();
    ofxUIWidget *getEmbeddedWidget(int index);
    
    virtual void setState(int _state);
	virtual int getState();
    virtual void setFont(ofxUIFont *_font);

    virtual void setPadding(float _padding);
    virtual float getPadding();
    
	virtual ofxUIRectangle* getRect();
    virtual ofxUIRectangle *getPaddingRect();
    virtual void setRectParent(ofxUIRectangle *_prect);
    
    virtual void setDrawPadding(bool _draw_padded_rect);
    virtual bool getDrawPadding();
    
    virtual void setDrawPaddingOutline(bool _draw_padded_rect_outline);
    virtual bool getDrawPaddingOutline();
	
    virtual void setDrawBack(bool _draw_back);
	virtual bool getDrawBack();
	
    virtual void setDrawOutline(bool _draw_outline);
	virtual bool getDrawOutline();
	
    virtual void setDrawFill(bool _draw_fill);
	virtual bool getDrawFill();
    
    virtual void setDrawFillHighLight(bool _draw_fill_highlight);
	virtual bool getDrawFillHighLight();
    
    virtual void setDrawOutlineHighLight(bool _draw_outline_hightlight);
	virtual bool getDrawOutlineHighLight();
	
	virtual void setColorBack(ofxUIColor _color_back);
    ofxUIColor& getColorBack();
    
	virtual void setColorOutline(ofxUIColor _color_outline);
    ofxUIColor& getColorOutline();
    
	virtual void setColorOutlineHighlight(ofxUIColor _color_outline_highlight);
	ofxUIColor& getColorOutlineHighlight();
    
	virtual void setColorFill(ofxUIColor _color_fill);
	ofxUIColor& getColorFill();
    
	virtual void setColorFillHighlight(ofxUIColor _color_fill_highlight);
	ofxUIColor& getColorFillHighlight();
    
    virtual void setColorPadded(ofxUIColor _color_padded_rect);
	ofxUIColor& getColorPadded();
    
    virtual void setColorPaddedOutline(ofxUIColor _color_padded_rect_outline);
    ofxUIColor& getColorPaddedOutline();

<<<<<<< HEAD
	// --!重绘接口
	void setRedraw(bool redraw);
	bool getRedraw();

=======
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
    virtual void addModalWidget(ofxUIWidget *widget);
    virtual void removeModalWidget(ofxUIWidget *widget);

    ofxUIWidget *getCanvasParent();

    virtual bool hasState();
    
#ifndef OFX_UI_NO_XML   
    
    virtual void saveState(ofxXmlSettings *XML);
    virtual void loadState(ofxXmlSettings *XML);
    
#endif

<<<<<<< HEAD
	// --!新增 倘若子类覆盖了此方法则会调用子类函数 否则为基类
=======
	// --!–¬‘ˆ Ã»»Ù◊”¿‡∏≤∏«¡À¥À∑Ω∑®‘Úª·µ˜”√◊”¿‡∫Ø ˝ ∑Ò‘ÚŒ™ª˘¿‡
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	virtual void initFrameAnimation(float interval);
	virtual void drawFrameAnimation();

protected:

	ofxUIWidget *parent;
<<<<<<< HEAD
	// --!完全不知道作者为什么要把好端端的ofxUICanvas parent写成widget
	// --!酱很明显就等于是把canvas的高度下放到widget了好嘛！
	// 正确的做法应该是讲Canvas和widget独立开来 而不是让Canvas去继承widget因为无论是在功能上或者说是在实际上其实都不应该判定为继承关系 
=======
	// --!ÕÍ»´≤ª÷™µ¿◊˜’ﬂŒ™ ≤√¥“™∞—∫√∂À∂ÀµƒofxUICanvas parent–¥≥…widget
	// --!Ω¥∫‹√˜œ‘æÕµ»”⁄ «∞—canvasµƒ∏ﬂ∂»œ¬∑≈µΩwidget¡À∫√¬Ô£°
	// ’˝»∑µƒ◊ˆ∑®”¶∏√ «Ω≤Canvas∫Õwidget∂¿¡¢ø™¿¥ ∂¯≤ª «»√Canvas»•ºÃ≥–widget“ÚŒ™Œﬁ¬€ «‘⁄π¶ƒ‹…œªÚ’ﬂÀµ «‘⁄ µº …œ∆‰ µ∂º≤ª”¶∏√≈–∂®Œ™ºÃ≥–πÿœµ 
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	ofxUICanvas *canvasController;

	ofxUIRectangle *rect;
	ofPoint *position;
	ofxUIFont *font;
	
    std::string name;                    
	ofxUIWidgetType kind; 
	bool visible;
    int ID;
    bool hit; 
    int state;
<<<<<<< HEAD
	// --!用于判断和上一帧控件状态是否发生变化
	int previousState;

=======
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
    ofxUITriggerType triggerType; 
    bool embedded;
    bool modal;
    
	bool draw_back;    
	bool draw_outline;
	bool draw_outline_highlight; 
	bool draw_fill; 
	bool draw_fill_highlight; 

<<<<<<< HEAD
	// --!新增
	ofxUIDrawMode drawMode;
	bool focus;
	ofxUIFbo frameBuffer;
	bool bFirst;
	// --!此控件是否需要重绘
	bool bRedraw;
	ofxUIMessage* message;
=======
	// --!–¬‘ˆ
	ofxUIDrawMode drawMode;
	bool focus;
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf

	ofxUIColor color_back;
	ofxUIColor color_outline; 
	ofxUIColor color_outline_highlight;	
	ofxUIColor color_fill; 
	ofxUIColor color_fill_highlight; 

	float padding;                 
	ofxUIRectangle *paddedRect; 	

	bool draw_padded_rect; 
	bool draw_padded_rect_outline;     
    ofxUIColor color_padded_rect; 
	ofxUIColor color_padded_rect_outline;
    
    vector<ofxUIWidget *> embeddedWidgets; 
    
#ifdef OFX_UI_TARGET_TOUCH       
    int touchId;     
#endif
};