#include "ofxUIFrameAnimation.h"


ofxUIFrameAnimation::ofxUIFrameAnimation()
{
	currentFrame = 0;
	sumFrames = 0;

	width = 0.0f;
	height = 0.0f;

	//���������
	pictures.clear();
}

ofxUIFrameAnimation::~ofxUIFrameAnimation()
{
	// �����Ժ��ͷ�vector�ڴ涼������ clear() ��Ϊ swap()
	// --!ժ��:http://blog.jobbole.com/37700/
	vector<ofImage>(pictures).swap(pictures);
}

void ofxUIFrameAnimation::loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber)
{
	string current;
	char convert[5];

	// ��ͼ�������¼��س��������
	pictures.clear();
	sumFrames = 0;

	//ѭ������������ļ���
	for(int i=1; i<=sumNumber; i++)
	{
		ofImage* temp = new ofImage();

		//��int��iת��Ϊchar*֮����ת��Ϊstring
		sprintf(convert, "%d", i);
		current = convert;
		//path/�ļ���/folderName-x.suffix
		if(!temp->loadImage(path + folderName + "/" + folderName + "-" + current + "." + suffixFormat))
		{
			printf("�޷���ָ���ļ����ж�ȡ֡�������ͼƬ");
			continue;
		}

		width += temp->getWidth();
		height += temp->getHeight();

		addFrame(*temp);
	}

	// ֡���������ƽ��ֵ
	width /= sumFrames;
	height /= sumFrames;
}

void ofxUIFrameAnimation::addFrame(ofImage& image)
{
	//��β��������ͼƬ/֡
	pictures.push_back(image);

	sumFrames++;
}

void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position)
{
	drawCurrentFrame(position, width, height);
}


void ofxUIFrameAnimation::drawCurrentFrame(ofPoint& position, float width, float height)
{
	//����ǰ����û��֡��ֱ������
	if(sumFrames == 0)
		return;

	//ͷβѭ�����µ�ǰ֡λ��ָ��
	currentFrame = (currentFrame+1) % sumFrames;

	//��ָ��λ��ֱ�ӻ��Ƴ�����ͼƬ�����֡����
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

// ���õ�ǰ����
void ofxUIFrameAnimation::reset()
{
	currentFrame = 0;
}