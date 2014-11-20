##ofxUI
=====

不改动ofxUI原有使用逻辑和架构方式前提下 向下兼容 
支持自定义样式 自定义控件位置属性


=====
###运行截图
####可自定义外观样式 支持帧动画渲染
* ofxUI with TattyUI
![image](https://github.com/BentleyBlanks/ofxUI/raw/master/pictures/%20(1).jpg)
![image](https://github.com/BentleyBlanks/ofxUI/raw/master/pictures/%20(2).jpg)

####与原ofxUI渲染帧率对比
* ofxUI with TattyUI
![image](https://github.com/BentleyBlanks/ofxUI/raw/master/pictures/%20(4).jpg)

* ofxUI
![image](https://github.com/BentleyBlanks/ofxUI/raw/master/pictures/%20(3).jpg)

##何处改进 2014.11.19更新
*  极大提高渲染效率 最差情况依旧能够提高将近5倍帧率<br><br><br>
  * 控件加入极高效率的消息队列机制 最好的情况下是原先帧率的20倍<br><br><br>
*  帧动画支持正常限帧 优化外部操作逻辑<br><br><br>
*  更新scrollableCanvas绘制逻辑 使得其支持自定义皮肤样式<br><br><br>
*  仍旧保证向下兼容<br><br><br>
  * 修正些许潜在BUG<br><br><br>

*  手动查看两者绘制效率的方式如下<br><br><br>
*  新建工程中 关闭垂直同步 尽可能的调高FPS 对比两个相同程序的FPS值<br><br><br>

```c
//渲染/输出fps这个过程也会带来些许性能影响 但这并不影响大局

ofSetVerticalSync(false);

ofSetFrameRate(10000);
```

=====
###2014.11.12更新
*  改造ofxUIFrameAnimation<br><br><br>
    * 支持自定义限帧 <br><br><br>
    * 最高层增添了接口能够直接自定义跳帧间隔(button toggle slider rangeSlider radio )<br><br><br>

*  改造ofxUIScrollableCanvas<br><br><br>
    * 更好的支持自定义样式<br><br><br>

*  修正潜在BUG<br><br><br>
    * 修正了当外部不自定义frameAnimation坐标但却尝试使用帧动画系统时的崩溃BUG<br><br><br>
    * 修正了当采用自动排版样式时 自定义样式不更新的错误<br><br><br>


=====
###2014.9.22更新


* 改造ofxUIRangeSlider与ofxUISlider<br><br><br>
    * 为其的顶部底部背景条更新为动画帧滚动条 理论上可支持模拟进度条样式<br><br><br>
    * slider新增按钮(实质为更新后的ofxUIButton)理论支持所有ofxUIButton支持的特性<br><br><br>
    * rangeSlider新增两个按钮并且保持原生拖动风格<br><br><br>


* 改造ofxRadio<br><br><br>
    * 将其内部逻辑转换为radio为管理一系列ofxUIButton的controller<br><br><br>
    * 理论所有内部按钮支持ofxUIButton支持的所有新旧特性 且风格一致<br><br><br>



* 支持OSX系统下Xcode(6.0及以下版本)编译使用 <br><br><br>


=====
###2014.3.1更新
* 改造ofxUIScrollableCanvas的mouseDragged处理函数<br><br><br>
    * 即便是当hitWidget的时候也同样进行下拉滑动 优化滑动逻辑<br><br><br>
    * 默认情况Slider不会触发input改变滑动栏大小的机制<br><br><br>
    * 下拉后回弹动画效果<br><br><br>
    * 滑动下(scrollCanvas)添加类似iOS的阻尼效果<br><br><br>

* ofxUIDefines.h的宏定义改进<br><br><br>
    * ``` OFX_UI_STATE_OVER ``` 修正为 ``` OFX_UI_STATE_HOVER ```
<br><br><br>
    * 表达鼠标掠过而非和up同意义混淆<br><br><br>
    * 鼠标抬起使用up表示 ``` #define OFX_UI_STATE_UP 抬起状态 ```<br><br><br>

* 各个派生类中mousePressed等函数在触发时 
    * 是否需要触发Hover事件不确定 仍然需要用户反馈 即目前只能获取widget的up和down状态 <br><br><br>
    
* 大部分在源代码上修正的位置都添加l "--!" 标示符 可以通过这样的方式快速查看修改的位置


##关于作者
```c
   int 官某某 = Bingo;
```
