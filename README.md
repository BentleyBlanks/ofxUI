##ofxUI
=====

不改动ofxUI原有架构前提下 合理改造

##何处改进
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
