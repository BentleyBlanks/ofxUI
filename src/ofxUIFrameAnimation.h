#ifndef OFX_UI_FRAMEANIMATION_H
#define OFX_UI_FRAMEANIMATION_H

#include "ofxUIDefines.h"

class ofxUIFrameAnimation
{
public:
	ofxUIFrameAnimation();
    ofxUIFrameAnimation(float interval);
	~ofxUIFrameAnimation();

	// ∂¡»Î’˚∏ˆXXXŒƒº˛º–œ¬µƒÀ˘”–Õº∆¨ 
	// --!πÊ∑∂–‘“™«Û:
	// 1.–Ë“™√¸√˚∑Ω ΩŒ™ XXX-1.png/bmp...
	// 2.Œƒº˛º–√˚ ∫Û◊∫√˚(À˘”–Œƒº˛µƒ∏Ò Ω∂º–Ë“™Õ≥“ªŒ™Õ¨“ª∏Ò Ω) ÷° ˝(Œƒº˛∏ˆ ˝)
	// 3.ƒ¨»œ»œŒ™À˘”–÷°∂Øª≠µƒÕº∆¨øÌ∏ﬂ∂º «“ª÷¬µƒ(≤ª∂‘¥ÀΩ¯––πÊ∑∂ºÏ≤‚)
	void loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber);

	//‘⁄÷∏∂®Œª÷√ªÊ÷∆µ±«∞÷°
	void drawCurrentFrame(ofPoint& position);

	// ∂‘À˘”–÷°∂Øª≠÷¥––ªÊ÷∆“ª≤ø∑÷µƒ≤Ÿ◊˜(subsction)’‚¿Ô≤¢≤ª–Ë“™scale
	void drawCurrentFrame(ofPoint& position, float width, float height);

    void setInterval(float interval);
    
	// --!ƒ¨»œÀ˘”–∂Øª≠øÌ∏ﬂ∂ºœ‡Õ¨
	// --!∑µªÿ∂Øª≠øÌ∏ﬂ∆Ωæ˘÷µ
	float getWidth();

	float getHeight();

	// ÷ÿ÷√µ±«∞º∆ ˝
	void reset();
private:
    float previousTime;
    float nowTime;
    // 帧率间隔
    float interval;
        
	//ÃÌº”÷°∂Øª≠Õº
	void addFrame(ofImage& image);

	//µ±«∞÷°
	int currentFrame;
	//◊‹÷° ˝
	int sumFrames;
	//÷°∂Øª≠ºØ
	vector<ofImage> pictures;

	// ÷°∂Øª≠Õº∆¨ºØøÌ∏ﬂ∆Ωæ˘÷µ
	float width, height;
};

#endif