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

	// 存放该消息的指针
	// --!可能存在该指针为临时变量申请而导致其变化为野指针的安全隐患
	void pushMessage(ofxUIMessage* message);

	// 弹出并删去该消息
	ofxUIMessage* popMessage();

	// 判空 置空
	bool isEmpty();

	void setEmpty();
private:
	// 不可删除 不可复制 不可自己创建实例
	ofxUIMessageQueue(){};
	ofxUIMessageQueue(const ofxUIMessageQueue&){};
	~ofxUIMessageQueue(){};
	ofxUIMessageQueue& operator=(const ofxUIMessageQueue& event) const{};

	// 手工实现的队列不如直接使用现成queue
	//vector<ofxUIMessage*> messages;
	deque<ofxUIMessage*> messages;
};