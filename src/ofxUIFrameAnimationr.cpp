#include "ofxUIFrameAnimation.h"


ofxUIFrameAnimation::ofxUIFrameAnimation()
{
	currentFrame = 0;
	sumFrames = 0;

	width = 0.0f;
	height = 0.0f;

    previousTime = 0;
    interval = 0.07692308;
	//«Âø’œÚ¡øºØ
	pictures.clear();
}

ofxUIFrameAnimation::ofxUIFrameAnimation(float interval):interval(interval)
{
//    // 显式调用
//    ofxUIFrameAnimation::ofxUIFrameAnimation();
    currentFrame = 0;
    sumFrames = 0;
    
    width = 0.0f;
    height = 0.0f;
    
    previousTime = 0;
    
    //«Âø’œÚ¡øºØ
    pictures.clear();
}

ofxUIFrameAnimation::~ofxUIFrameAnimation()
{
	// Ω®“È“‘∫Û Õ∑≈vectorƒ⁄¥Ê∂ºΩ´µ˜”√ clear() ∏ƒŒ™ swap()
	// --!’™◊‘:http://blog.jobbole.com/37700/
	vector<ofImage>(pictures).swap(pictures);
}

void ofxUIFrameAnimation::loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber)
{
	string current;
	char convert[5];

	// ‘⁄ÕººØ÷–÷ÿ–¬º”‘ÿ≥ˆ¿¥–Ë«Âø’
	pictures.clear();
	sumFrames = 0;

	//—≠ª∑ÃÌº”ÕÍ’˚∏ˆŒƒº˛º–
	for(int i=1; i<=sumNumber; i++)
	{
		ofImage* temp = new ofImage();

		//Ω´int–Õi◊™ªªŒ™char*÷Æ∫Û‘Ÿ◊™ªªŒ™string
		sprintf(convert, "%d", i);
		current = convert;
		//path/Œƒº˛º–/folderName-x.suffix
		if(!temp->loadImage(path + folderName + "/" + folderName + "-" + current + "." + suffixFormat))
		{
			printf("Œﬁ∑®¥”÷∏∂®Œƒº˛º–÷–∂¡»°÷°∂Øª≠œ‡πÿÕº∆¨");
			continue;
		}

		width += temp->getWidth();
		height += temp->getHeight();

		addFrame(*temp);
	}

	// ÷°∂Øª≠ºØøÌ∏ﬂ∆Ωæ˘÷µ
	width /= sumFrames;
	height /= sumFrames;
}

void ofxUIFrameAnimation::addFrame(ofImage& image)
{
	//‘⁄Œ≤≤ø≤Â»Î–¬Õº∆¨/÷°
	pictures.push_back(image);

	sumFrames++;
}

void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position)
{
	drawCurrentFrame(position, width, height);
}


void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position, float width, float height)
{
	//»Ùµ±«∞∂Øª≠√ª”–÷°‘Ú÷±Ω”Ã¯π˝
	if(sumFrames == 0)
		return;

    nowTime = ofGetElapsedTimef();
    if(nowTime - previousTime >= interval)
    {
        //Õ∑Œ≤—≠ª∑∏¸–¬µ±«∞÷°Œª÷√÷∏œÚ
        currentFrame = (currentFrame+1) % sumFrames;
        previousTime = nowTime;
    }

	//‘⁄÷∏∂®Œª÷√÷±Ω”ªÊ÷∆≥ˆ∏¯∂®Õº∆¨≥§øÌµƒ÷°∂Øª≠
	pictures[currentFrame].drawSubsection(position.x, position.y, width, height, 0, 0);
}

void ofxUIFrameAnimation::setInterval(float interval)
{
    this->interval = interval;
}

float ofxUIFrameAnimation::getWidth()
{
	return width;
}


float ofxUIFrameAnimation::getHeight()
{
	return height;
}

// ÷ÿ÷√µ±«∞º∆ ˝
void ofxUIFrameAnimation::reset()
{
	currentFrame = 0;
}