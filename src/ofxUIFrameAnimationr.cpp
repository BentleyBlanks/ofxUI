#include "ofxUIFrameAnimation.h"


ofxUIFrameAnimation::ofxUIFrameAnimation()
{
	currentFrame = 0;
	sumFrames = 0;

	width = 0.0f;
	height = 0.0f;

	//清空向量集
	pictures.clear();
}

ofxUIFrameAnimation::~ofxUIFrameAnimation()
{
	// 建议以后释放vector内存都将调用 clear() 改为 swap()
	// --!摘自:http://blog.jobbole.com/37700/
	vector<ofImage>(pictures).swap(pictures);
}

void ofxUIFrameAnimation::loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber)
{
	string current;
	char convert[5];

	// 在图集中重新加载出来需清空
	pictures.clear();
	sumFrames = 0;

	//循环添加完整个文件夹
	for(int i=1; i<=sumNumber; i++)
	{
		ofImage* temp = new ofImage();

		//将int型i转换为char*之后再转换为string
		sprintf(convert, "%d", i);
		current = convert;
		//path/文件夹/folderName-x.suffix
		if(!temp->loadImage(path + folderName + "/" + folderName + "-" + current + "." + suffixFormat))
		{
			printf("无法从指定文件夹中读取帧动画相关图片");
			continue;
		}

		width += temp->getWidth();
		height += temp->getHeight();

		addFrame(*temp);
	}

	// 帧动画集宽高平均值
	width /= sumFrames;
	height /= sumFrames;
}

void ofxUIFrameAnimation::addFrame(ofImage& image)
{
	//在尾部插入新图片/帧
	pictures.push_back(image);

	sumFrames++;
}

void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position)
{
	drawCurrentFrame(position, width, height);
}


void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position, float width, float height)
{
	//若当前动画没有帧则直接跳过
	if(sumFrames == 0)
		return;

	//头尾循环更新当前帧位置指向
	currentFrame = (currentFrame+1) % sumFrames;

	//在指定位置直接绘制出给定图片长宽的帧动画
	pictures[currentFrame].drawSubsection(position.x, position.y, width, height, 0, 0);
}


float ofxUIFrameAnimation::getWidth()
{
	return width;
}


float ofxUIFrameAnimation::getHeight()
{
	return height;
}

// 重置当前计数
void ofxUIFrameAnimation::reset()
{
	currentFrame = 0;
}