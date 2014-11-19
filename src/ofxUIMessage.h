#pragma once

#include <ofxUIWidget.h>
#include <deque>

class ofxUIMessage
{
public:
	ofxUIMessage();
	ofxUIMessage(ofxUIWidget* widget):widget(widget){};

	ofxUIWidget* getWidget();

	void setWidget(ofxUIWidget* widget);

private:
	ofxUIWidget* widget;
};

class ofxUIMessageQueue
{
public:
	static ofxUIMessageQueue* getQueue();

	// ��Ÿ���Ϣ��ָ��
	// --!���ܴ��ڸ�ָ��Ϊ��ʱ���������������仯ΪҰָ��İ�ȫ����
	void pushMessage(ofxUIMessage* message);

	// ������ɾȥ����Ϣ
	ofxUIMessage* popMessage();

	// �п� �ÿ�
	bool isEmpty();

	void setEmpty();
private:
	// ����ɾ�� ���ɸ��� �����Լ�����ʵ��
	ofxUIMessageQueue(){};
	ofxUIMessageQueue(const ofxUIMessageQueue&){};
	~ofxUIMessageQueue(){};
	ofxUIMessageQueue& operator=(const ofxUIMessageQueue& event) const{};

	// �ֹ�ʵ�ֵĶ��в���ֱ��ʹ���ֳ�queue
	//vector<ofxUIMessage*> messages;
	deque<ofxUIMessage*> messages;
};