## ofxUI

Didn't change the usage of [ofxUI](https://github.com/rezaali/ofxUI), but more effient and supported more widget styles. Allows to change the widget's attribute, not confined in the widget canvas(position, texture etc...).

## Usage
1.To hide the canvas's panel
```cpp
canvas->setDrawable(false);
```
2.Use customize the widget's texture/frame animation
```cpp
widget->setDrawMode(OFX_UI_DRAW_FRAMEANIMATION_NOLABEL);
widget->setFrameAnimationPosition(x, y);
// setting the customize trigger aabb
widget->setAABB(x, y, w, h);
// foldername and picsNumber for import series gif photos(amount 1 for static widget)
button->loadImageOfHover(path, folderName, suffixFormat, picsAmount);
// the same for loading image of Normal and Pressed.
```
3.Rest of it is the same with ofxUI's usage


## Screentshot
#### Customizable style and frame animation supported

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/134486032@N03/23570686378/in/dateposted-public/" title="2"><img src="https://farm5.staticflickr.com/4417/23570686378_5056212a76_c.jpg" width="800" height="643" alt="2"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/134486032@N03/23570686458/in/dateposted-public/" title="1"><img src="https://farm5.staticflickr.com/4467/23570686458_19396ca7ea_c.jpg" width="800" height="643" alt="1"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

----

#### Effiency(Compatible with original ofxUI)
> Comparison each other with the fps

ofxUI with TattyUI

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/134486032@N03/23570686158/in/dateposted-public/" title="4"><img src="https://farm5.staticflickr.com/4465/23570686158_052928aed9_c.jpg" width="800" height="619" alt="4"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

Original ofxUI

<a data-flickr-embed="true"  href="https://www.flickr.com/photos/134486032@N03/23570686208/in/dateposted-public/" title="3"><img src="https://farm5.staticflickr.com/4503/23570686208_3816d80d55_c.jpg" width="800" height="619" alt="3"></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

## Updated
### 2014.11.19

- 极大提高渲染效率 最差情况依旧能够提高将近5倍帧率
- 控件加入极高效率的消息队列机制 最好的情况下是原先帧率的20倍
- 帧动画支持正常限帧 优化外部操作逻辑
- 更新scrollableCanvas绘制逻辑 使得其支持自定义皮肤样式
- 仍旧保证向下兼容
- 修正些许潜在BUG

### 2014.11.12
-  改造ofxUIFrameAnimation
- 支持自定义限帧 
- 最高层增添了接口能够直接自定义跳帧间隔(button toggle slider rangeSlider radio )
-  改造ofxUIScrollableCanvas
- 更好的支持自定义样式
-  修正潜在BUG
- 修正了当外部不自定义frameAnimation坐标但却尝试使用帧动画系统时的崩溃BUG
- 修正了当采用自动排版样式时 自定义样式不更新的错误

### 2014.9.22
- 改造ofxUIRangeSlider与ofxUISlider
- 为其的顶部底部背景条更新为动画帧滚动条 理论上可支持模拟进度条样式
- slider新增按钮(实质为更新后的ofxUIButton)理论支持所有ofxUIButton支持的特性
- rangeSlider新增两个按钮并且保持原生拖动风格
- 改造ofxRadio
- 将其内部逻辑转换为radio为管理一系列ofxUIButton的controller
- 理论所有内部按钮支持ofxUIButton支持的所有新旧特性 且风格一致
- 支持OSX系统下Xcode(6.0及以下版本)编译使用 

### 2014.3.1
- 改造ofxUIScrollableCanvas的mouseDragged处理函数
- 即便是当hitWidget的时候也同样进行下拉滑动 优化滑动逻辑
- 默认情况Slider不会触发input改变滑动栏大小的机制
- 下拉后回弹动画效果
- 滑动下(scrollCanvas)添加类似iOS的阻尼效果
- ofxUIDefines.h的宏定义改进
- ```OFX_UI_STATE_OVER``` 修正为 ```OFX_UI_STATE_HOVER ```
- 表达鼠标掠过而非和up同意义混淆
- 鼠标抬起使用up表示 ```#define OFX_UI_STATE_UP```抬起状态
- 各个派生类中mousePressed等函数在触发时 
- 是否需要触发Hover事件不确定 仍然需要用户反馈 即目前只能获取widget的up和down状态 
- 大部分在源代码上修正的位置都添加l "--!" 标示符 可以通过这样的方式快速查看修改的位置


##关于作者
```c
    int 官某某 = "Bingo";

    char[] 个人博客 = "http://bentleyblanks.github.io";
```
