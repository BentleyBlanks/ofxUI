#include "ofxUIFrameAnimation.h"


ofxUIFrameAnimation::ofxUIFrameAnimation()
{
	currentFrame = 0;
	sumFrames = 0;

	width = 0.0f;
	height = 0.0f;

    previousTime = 0;
    interval = 0.07692308;
<<<<<<< HEAD
	
	//清空向量集
=======
	//«Âø’œÚ¡øºØ
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
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
    
<<<<<<< HEAD
=======
    //«Âø’œÚ¡øºØ
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
    pictures.clear();
}

ofxUIFrameAnimation::~ofxUIFrameAnimation()
{
<<<<<<< HEAD
	// 建议以后释放vector内存都将调用 clear() 改为 swap()
	// --!摘自:http://blog.jobbole.com/37700/
=======
	// Ω®“È“‘∫Û Õ∑≈vectorƒ⁄¥Ê∂ºΩ´µ˜”√ clear() ∏ƒŒ™ swap()
	// --!’™◊‘:http://blog.jobbole.com/37700/
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	vector<ofImage>(pictures).swap(pictures);
}

void ofxUIFrameAnimation::loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber)
{
	string current;
	char convert[5];

<<<<<<< HEAD
	// 在图集中重新加载出来需清空
	pictures.clear();
	sumFrames = 0;

	//循环添加完整个文件夹
=======
	// ‘⁄ÕººØ÷–÷ÿ–¬º”‘ÿ≥ˆ¿¥–Ë«Âø’
	pictures.clear();
	sumFrames = 0;

	//—≠ª∑ÃÌº”ÕÍ’˚∏ˆŒƒº˛º–
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	for(int i=1; i<=sumNumber; i++)
	{
		ofImage* temp = new ofImage();

<<<<<<< HEAD
		//将int型i转换为char*之后再转换为string
		sprintf(convert, "%d", i);
		current = convert;
		//path/文件夹/folderName-x.suffix
		if(!temp->loadImage(path + folderName + "/" + folderName + "-" + current + "." + suffixFormat))
		{
			printf("无法从指定文件夹中读取帧动画相关图片");
=======
		//Ω´int–Õi◊™ªªŒ™char*÷Æ∫Û‘Ÿ◊™ªªŒ™string
		sprintf(convert, "%d", i);
		current = convert;
		//path/Œƒº˛º–/folderName-x.suffix
		if(!temp->loadImage(path + folderName + "/" + folderName + "-" + current + "." + suffixFormat))
		{
			printf("Œﬁ∑®¥”÷∏∂®Œƒº˛º–÷–∂¡»°÷°∂Øª≠œ‡πÿÕº∆¨");
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
			continue;
		}

		width += temp->getWidth();
		height += temp->getHeight();

		addFrame(*temp);
	}

<<<<<<< HEAD
	// 帧动画集宽高平均值
=======
	// ÷°∂Øª≠ºØøÌ∏ﬂ∆Ωæ˘÷µ
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	width /= sumFrames;
	height /= sumFrames;
}

void ofxUIFrameAnimation::addFrame(ofImage& image)
{
<<<<<<< HEAD
=======
	//‘⁄Œ≤≤ø≤Â»Î–¬Õº∆¨/÷°
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	pictures.push_back(image);

	sumFrames++;
}

void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position)
{
	drawCurrentFrame(position, width, height);
}


void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position, float width, float height)
{
<<<<<<< HEAD
	// 若当前动画没有帧则直接跳过
=======
	//»Ùµ±«∞∂Øª≠√ª”–÷°‘Ú÷±Ω”Ã¯π˝
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
	if(sumFrames == 0)
		return;

    nowTime = ofGetElapsedTimef();
    if(nowTime - previousTime >= interval)
    {
<<<<<<< HEAD
        // 头尾循环更新当前帧位置指向
=======
        //Õ∑Œ≤—≠ª∑∏¸–¬µ±«∞÷°Œª÷√÷∏œÚ
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
        currentFrame = (currentFrame+1) % sumFrames;
        previousTime = nowTime;
    }

<<<<<<< HEAD
	// 在指定位置直接绘制出给定图片长宽的帧动画
=======
	//‘⁄÷∏∂®Œª÷√÷±Ω”ªÊ÷∆≥ˆ∏¯∂®Õº∆¨≥§øÌµƒ÷°∂Øª≠
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
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

<<<<<<< HEAD
// 重置当前计数
=======
// ÷ÿ÷√µ±«∞º∆ ˝
>>>>>>> 03cafd9e07d52d7d9b9248a68c0e10e6fbeeeabf
void ofxUIFrameAnimation::reset()
{
	currentFrame = 0;
}