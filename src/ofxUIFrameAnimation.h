#ifndef OFX_UI_FRAMEANIMATION_H
#define OFX_UI_FRAMEANIMATION_H

#include "ofxUIDefines.h"

class ofxUIFrameAnimation
{
public:
	ofxUIFrameAnimation();
	~ofxUIFrameAnimation();

	// 读入整个XXX文件夹下的所有图片 
	// --!规范性要求:
	// 1.需要命名方式为 XXX-1.png/bmp...
	// 2.文件夹名 后缀名(所有文件的格式都需要统一为同一格式) 帧数(文件个数)
	// 3.默认认为所有帧动画的图片宽高都是一致的(不对此进行规范检测)
	void loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber);

	//在指定位置绘制当前帧
	void drawCurrentFrame(ofPoint& position);

	// 对所有帧动画执行绘制一部分的操作(subsction)这里并不需要scale
	void drawCurrentFrame(ofPoint& position, float width, float height);

	// --!默认所有动画宽高都相同
	// --!返回动画宽高平均值
	float getWidth();

	float getHeight();

	// 重置当前计数
	void reset();
private:
	//添加帧动画图
	void addFrame(ofImage& image);

	//当前帧
	int currentFrame;
	//总帧数
	int sumFrames;
	//帧动画集
	vector<ofImage> pictures;

	// 帧动画图片集宽高平均值
	float width, height;
};

#endif