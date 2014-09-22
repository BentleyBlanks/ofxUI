#ifndef OFX_UI_FRAMEANIMATION_H
#define OFX_UI_FRAMEANIMATION_H

#include "ofxUIDefines.h"

class ofxUIFrameAnimation
{
public:
	ofxUIFrameAnimation();
	~ofxUIFrameAnimation();

	// ��������XXX�ļ����µ�����ͼƬ 
	// --!�淶��Ҫ��:
	// 1.��Ҫ������ʽΪ XXX-1.png/bmp...
	// 2.�ļ����� ��׺��(�����ļ��ĸ�ʽ����ҪͳһΪͬһ��ʽ) ֡��(�ļ�����)
	// 3.Ĭ����Ϊ����֡������ͼƬ��߶���һ�µ�(���Դ˽��й淶���)
	void loadImages(string& path, string& folderName, string& suffixFormat, int sumNumber);

	//��ָ��λ�û��Ƶ�ǰ֡
	void drawCurrentFrame(ofPoint& position);

	// ������֡����ִ�л���һ���ֵĲ���(subsction)���ﲢ����Ҫscale
	void drawCurrentFrame(ofPoint& position, float width, float height);

	// --!Ĭ�����ж�����߶���ͬ
	// --!���ض������ƽ��ֵ
	float getWidth();

	float getHeight();

	// ���õ�ǰ����
	void reset();
private:
	//���֡����ͼ
	void addFrame(ofImage& image);

	//��ǰ֡
	int currentFrame;
	//��֡��
	int sumFrames;
	//֡������
	vector<ofImage> pictures;

	// ֡����ͼƬ�����ƽ��ֵ
	float width, height;
};

#endif