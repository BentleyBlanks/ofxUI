#include "ofxUITattyXML.h"	
#include "ofXml.h"
#include "ofxUISuperCanvas.h"

// 只是为了重写一次读入的XML而所做的继承
void ofxUITattyXML::saveSettings(string fileName)
{

}

void ofxUITattyXML::loadSettings(string fileName)
{
	ofXml *XML = new ofXml();
	string message = "";

	if(!XML->load(fileName))
	{
		message = "无法打开指定路径下的XML配置文件";
		cout << message;
		return;
	}
	else
	{
		// 较为严格的比对
		// --!OF似乎会直接进入第一个节点 因此无需对于最外围的节点判断
		//if(XML->exists("TattyUI"))
		//{
		//	XML->setTo("TattyUI");

		// 可能存在较多的Canvas
		if(XML->exists("canvas[0]"))
		{
			XML->setTo("canvas[0]");
			do
			{
				string name = XML->getValue<string>("name");
				// 增添新的Canvas到合集中
				ofxUISuperCanvas* superCanvas = new ofxUISuperCanvas(name);
				// --!暂时不清楚为何添加到了vector之后canvas的不绘制就失效的BUG
				//canvas.push_back(*superCanvas);

				bool drawable = XML->getValue<bool>("drawable");
				// canvas是否需要绘制
				superCanvas->setDrawable(drawable);

				// 可能存在多个widgets
				if(XML->exists("button[0]"))
				{
					XML->setTo("button[0]");
					do
					{
						string name = XML->getValue<string>("name");
						// 此处的bool用处不是特别大 直接设置为默认为false影响较小
						ofxUIButton *button = superCanvas->addButton(name, false);

						// 强制类型转换为ofxUIDrawMode形式(XML中只能以int的数字形式表示)
						ofxUIDrawMode drawMode = (ofxUIDrawMode)XML->getValue<int>("drawMode");
						button->setDrawMode(drawMode);

						if(XML->exists("AABB"))
						{
							XML->setTo("AABB");
							int x = XML->getValue<int>("x");
							int y = XML->getValue<int>("y");
							int width = XML->getValue<int>("width");
							int height = XML->getValue<int>("height");

							// 自定义的碰撞检测区域
							button->setAABB(x, y, width, height);

							XML->setToParent();
						}

						if(XML->exists("animation"))
						{
							XML->setTo("animation");

							// 绘制帧动画的位置
							if(XML->exists("position"))
							{
								XML->setTo("position");
								int x = XML->getValue<int>("x");
								int y = XML->getValue<int>("y");								

								ofPoint position(x, y);
								button->setFrameAnimationPosition(position);

								XML->setToParent();
							}

							// 三种状态的不同状态图
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
							// 跳出animation
							XML->setToParent();
						}

						// button的Lable名字是否需要可见
						if(XML->exists("label"))
						{
							bool visible = XML->getValue<bool>("visible");
							button->getLabelWidget()->setVisible(visible);
						}
					}
					while(XML->setToSibling());

					// 跳出button
					XML->setToParent();
				}

				// 未来所有的widgets都在此处添加

			}
			while(XML->setToSibling()); // 走向下一个canvas兄弟节点
		}
		else
			message += "canvas: XML节点不存在";
		//}
		//else
		//	message += "TattyUI: XML节点不存在";
	}
}