#include <ofxUIMessage.h>

ofxUIMessage::ofxUIMessage()
{
	widget = NULL;
}


ofxUIWidget* ofxUIMessage::getWidget()
{
	return widget;
}

void ofxUIMessage::setWidget(ofxUIWidget* widget)
{
	this->widget = widget;
}

ofxUIMessageQueue* ofxUIMessageQueue::getQueue()
{
	static ofxUIMessageQueue queue;
	return &queue;
}

void ofxUIMessageQueue::pushMessage(ofxUIMessage* message)
{
	messages.push_back(message);
}

ofxUIMessage* ofxUIMessageQueue::popMessage()
{
	ofxUIMessage* message = messages.front();
	//³ö¶ÓÁÐ
	messages.pop_front();
	return message;
}

bool ofxUIMessageQueue::isEmpty()
{
	return messages.empty();
}

void ofxUIMessageQueue::setEmpty()
{
	messages.clear();
}