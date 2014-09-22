#include "ofxUITattyXML.h"	
#include "ofXml.h"
#include "ofxUISuperCanvas.h"

// ֻ��Ϊ����дһ�ζ����XML�������ļ̳�
void ofxUITattyXML::saveSettings(string fileName)
{

}

void ofxUITattyXML::loadSettings(string fileName)
{
	ofXml *XML = new ofXml();
	string message = "";

	if(!XML->load(fileName))
	{
		message = "�޷���ָ��·���µ�XML�����ļ�";
		cout << message;
		return;
	}
	else
	{
		// ��Ϊ�ϸ�ıȶ�
		// --!OF�ƺ���ֱ�ӽ����һ���ڵ� ��������������Χ�Ľڵ��ж�
		//if(XML->exists("TattyUI"))
		//{
		//	XML->setTo("TattyUI");

		// ���ܴ��ڽ϶��Canvas
		if(XML->exists("canvas[0]"))
		{
			XML->setTo("canvas[0]");
			do
			{
				string name = XML->getValue<string>("name");
				// �����µ�Canvas���ϼ���
				ofxUISuperCanvas* superCanvas = new ofxUISuperCanvas(name);
				// --!��ʱ�����Ϊ����ӵ���vector֮��canvas�Ĳ����ƾ�ʧЧ��BUG
				//canvas.push_back(*superCanvas);

				bool drawable = XML->getValue<bool>("drawable");
				// canvas�Ƿ���Ҫ����
				superCanvas->setDrawable(drawable);

				// ���ܴ��ڶ��widgets
				if(XML->exists("button[0]"))
				{
					XML->setTo("button[0]");
					do
					{
						string name = XML->getValue<string>("name");
						// �˴���bool�ô������ر�� ֱ������ΪĬ��ΪfalseӰ���С
						ofxUIButton *button = superCanvas->addButton(name, false);

						// ǿ������ת��ΪofxUIDrawMode��ʽ(XML��ֻ����int��������ʽ��ʾ)
						ofxUIDrawMode drawMode = (ofxUIDrawMode)XML->getValue<int>("drawMode");
						button->setDrawMode(drawMode);

						if(XML->exists("AABB"))
						{
							XML->setTo("AABB");
							int x = XML->getValue<int>("x");
							int y = XML->getValue<int>("y");
							int width = XML->getValue<int>("width");
							int height = XML->getValue<int>("height");

							// �Զ������ײ�������
							button->setAABB(x, y, width, height);

							XML->setToParent();
						}

						if(XML->exists("animation"))
						{
							XML->setTo("animation");

							// ����֡������λ��
							if(XML->exists("position"))
							{
								XML->setTo("position");
								int x = XML->getValue<int>("x");
								int y = XML->getValue<int>("y");								

								ofPoint position(x, y);
								button->setFrameAnimationPosition(position);

								XML->setToParent();
							}

							// ����״̬�Ĳ�ͬ״̬ͼ
							// hover
							if(XML->exists("imageOfHover"))
							{
								XML->setTo("imageOfHover");

								string path = XML->getValue<string>("path");
								string folderName = XML->getValue<string>("folderName");
								string suffix = XML->getValue<string>("suffix");
								int num = XML->getValue<int>("num");

								button->loadImageOfHover(path, folderName, suffix, num);
								XML->setToParent();
							}

							// normal
							if(XML->exists("imageOfNoraml"))
							{
								XML->setTo("imageOfNoraml");

								string path = XML->getValue<string>("path");
								string folderName = XML->getValue<string>("folderName");
								string suffix = XML->getValue<string>("suffix");
								int num = XML->getValue<int>("num");

								button->loadImageOfNormal(path, folderName, suffix, num);

								XML->setToParent();
							}

							// pressed
							if(XML->exists("imageOfPressed"))
							{
								XML->setTo("imageOfPressed");

								string path = XML->getValue<string>("path");
								string folderName = XML->getValue<string>("folderName");
								string suffix = XML->getValue<string>("suffix");
								int num = XML->getValue<int>("num");

								button->loadImageOfPressed(path, folderName, suffix, num);

								XML->setToParent();
							}
							// ����animation
							XML->setToParent();
						}

						// button��Lable�����Ƿ���Ҫ�ɼ�
						if(XML->exists("label"))
						{
							bool visible = XML->getValue<bool>("visible");
							button->getLabelWidget()->setVisible(visible);
						}
					}
					while(XML->setToSibling());

					// ����button
					XML->setToParent();
				}

				// δ�����е�widgets���ڴ˴����

			}
			while(XML->setToSibling()); // ������һ��canvas�ֵܽڵ�
		}
		else
			message += "canvas: XML�ڵ㲻����";
		//}
		//else
		//	message += "TattyUI: XML�ڵ㲻����";
	}
}