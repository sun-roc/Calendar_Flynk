# 基于NodeMCU(ESP8266)芯片的多功能(物联网)万年历设计

> 本项目在之前写的基于STC-15的电子设计基础上,使用其相关算法重构了相关功能并增加了物联网功能,并完成了PCB设计和实物焊接搭建

## 1. 基本功能

1. 获取当前的年、月、日、时、分、秒并显示
2. 设置年、月、日、时、分、秒
3. AM、PM设置与显示
4. 农历年、月、日显示
5. 农历二十四节气显示
6. 闹钟时间设置，声光报警提示
7. 温度和湿度的检测与显示
8. 闹钟音乐选择

### 物联网相关功能

1. 使用手机APP通过WiFi网络连接该万年历，通过手机APP可以完成基本功能中的所有设置功能
2. 调用相关API接口获得网上天气预报数据(当前天气,天气预报,风速,湿度,降雨概率)，并将该数据通过WiFi网络传递给芯片，万年历可以完成天气信息显示
3. 火灾检测与报警，通过电子邮箱和手机短信通知。
4. 开机校时功能,保证每次开机与北京时间误差不超过一秒

## 2. 文件结构

Slynk 文件夹为不含手机APP控制的初始版本 

Flynk 文件夹为增添了手机APP控制的最终版本 

PCB 文件夹为使用Altium Designer设计的PCB线路图(印刷后可以用)

Repository 文件夹为该项目所依赖的相关Arduino库文件

Docs 文件夹为搭建项目过程中学习相关元器件和软件使用方法时撰写的Markdown笔记

Test 文件夹为测试过程中的废弃方案

## 3. 元器件型号

### 1. 主控芯片: ESP8266-NodeMCU

**主要技术参数**:

![NodeMCU-Pin-Layout](http://www.taichi-maker.com/wp-content/uploads/2016/12/esp8266_devkit_horizontal-01.png)

**选用优势**:

1. 价格便宜:淘宝售价15元左右
2. 集成度高:基于ESP8266,芯片本身带有WIFI通讯能力
3. 功能强大:支持1MB ram,3MB rom

### 2. 实时时钟芯片:DS1302

### 3. 显示模块:OLED-12864模块

选用优势:

1. 体积小巧
2. 串行口通信仅需4个引脚

### 4. 温度传感器:DHT11温度传感器

### 5. 音乐播放和闹钟提醒: 无源蜂鸣器

### 6.火灾检测: 红外线火焰传感器

## 4. 项目开发流程

1. 学习了Keil C51的基本操作(包括建立工程,DEBUG,联合Proteus远程调试等)

   [Keil使用指南](https://github.com/XupengSun/Calendar_STC15/blob/main/Docs/Keil%E4%BD%BF%E7%94%A8%E7%AC%94%E8%AE%B0.md)

2. 学习了Proteus和Altium Designer的基本使用搭建了本次项目,仿真所需要的环境

   [Altium designer使用指南](https://github.com/XupengSun/Calendar_STC15/blob/main/Docs/Altium%20Desinger%E4%BD%BF%E7%94%A8%E7%AC%94%E8%AE%B0.md)

3. 有关读取DS1302中年、月、日、时、分、秒的程序设计并搭建了仿真环境

- 编写流程为:
  1. 时钟芯片初始化,令时钟工作
  2. 将要读取的时间位地址写入芯片(一个字节)
  3. 将该位的时间数据读取出来(一个字节)
  4. 将读取的年月日时分秒数据返回

4. 有关农历显示的程序设计,通过LCD12864可以通过DS1302获取当前时间并通过内部算法运算获得当前时间农历日期

5. 完成了公历显示程序和农历显示程序的切换程序并获得节气信息.



## 程序总体结构与大纲

![image-20200906194525828](https://gitee.com/sun-roc/picture/raw/master/img/image-20200906194525828.png)

![image-20210129165218009](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165218009.png)

![image-20210129165226886](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165226886.png)

如上图所示,程序入口文件为**Flynk.c**文件,其他子函数和相关功能函数定义在编写的头文件中: 

1. Bell.h是操作蜂鸣器和播放歌曲的文件.
2. BlynkPage存放有关手机远程控制的页面文件.
3. Character用于存放有关查表信息,如:农历24节气,天干地支,开屏图片等信息.
4. Fire是有关火灾检测和发送报警邮件的有关函数.
5. HTTPRquest是向相关API网站发送请求信息获得如天气预报,实时时间的有关函数.
6. Lunar用于计算农历和节气的函数,OLED用于控制12864显示屏,显示消息的相关函数.
7. Scankey用于检测按键状态并调用相关页面.
8. SetTime用于初始化当前时间和闹钟时间.
9. Tempertaure用于取用DHT11的相关温湿度信息.
10. Timer用于修改时间,并写入DS1302中.
11. Weather用于获取当前天气和未来一天天气信息.
12. WIFiConnerct用于连接wifi,将设备接入互联网.

## 各项功能的具体实现:

### 1.   当前年月日时分秒显示

![image-20210129165239609](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165239609.png)

如上图所示,有关当前时间的相关程序存放在SetTime文件中,在闹钟启动的同时,连接WIFI并调用API接口进行网络校时,本方法相对于传统的通过DS1302在断电时通过本身电池维持时间的方法要准确的多,和标准北京时间误差不超过一秒.

### 2. 设置年月日时分秒

![image-20210129165246635](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165246635.png)

![image-20210129165254304](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165254304.png)

如上图所示,通过改变闹钟的DS1302的数值,达到设置年月日时分秒的目的,同步更改与公历相关的农历时间.

### 3. AM、PM设置与显示

![image-20210129165303282](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165303282.png)

如上图所示,该功能的实现较为简单.只需将显示数值大于12的作差即可

### 4. 农历年月日、二十四节气显示

![image-20210129165312922](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165312922.png)

如上图所示,该功能实现相关函数编写在Lunar文件中,通过输入公历年月日,通过查询Character.h中的数据表和进行相关公式计算获得输入的日期相关天干地支生肖月日等信息,并输出是否为节气,节气名称等信息.

### 5. 闹钟时间设置，闹钟时间到进行声光报警提示

![image-20210129165352035](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165352035.png)

![image-20210129165358573](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165358573.png)

如上图所示,分别展现了闹钟设置页面和闹钟响铃页面,该功能通过内部定义时间变量,在程序循环的过程中查询闹钟时间和当前时间是否相同,在相同时调用bell文件播放相应音乐和LED闪烁.



### 6. 温湿度检测

![image-20210129165331778](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165331778.png)

如上图所示,本功能实现是通过DHT11温湿度传感器,想相关数值通过引脚输入,并通过OLED展示在首页,并实时更新.



## 高级功能实现

### 1. 闹钟音乐选择

<img src="https://gitee.com/sun-roc/picture/raw/master/img/image-20200907183359005.png" alt="image-20200907183359005" style="zoom:50%;" />

![image-20210129165426870](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165426870.png)

如上图所示,将想要播放的音乐按照其音谱,转换成数字信号的音谱高低和节拍长短,并通过蜂鸣器播放(在前期制作过程中曾经实现过直接播放MP3格式音乐,但是因为使用的蜂鸣器相比于喇叭在功率和效率上都较低,播放可以流畅实现但音量极小,故而选用一个一个音节播放的形式)

### 2. 手机通过蓝牙或WiFi网络连接该万年历

![image-20210129165435312](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165435312.png)

![image-20210129165453353](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165453353.png)

如上图所示,本项目选用ESP8266芯片通过WIFI 接入互联网,并通过手机APP实现全部设置页面(开发过程中本想通过同原本设置页面公用一套页面的方式实现,但限于手机操作方式与按键实现的逻辑存在差异,因而开发了两套设置页面,但是显示格式相同,只是内在操作逻辑存在差异)



### 3.  万年历天气信息显示

![image-20210129165500417](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165500417.png)

如上图所示,通过WIFI连接互联网,并将单片机伪装为浏览器,向心知天气的API接口请求当天的天气信息,获得网站返回的Json格式的数据后,进行解析,并将解析后的信息存储,在LED显示屏上展现.

### 4. 火灾检测与报警

![image-20210129165509559](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165509559.png)

![image-20210129165515164](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165515164.png)

本功能通过红外线传感器实现,当出现火焰时,红外线传感器将感受到,将信息传至单片机,当数值超过程序设定的阈值时,通过远程服务器,将相关报警信息发至本机邮箱,从而实现远程报警.

## 其他功能

### 1. 开机图片

![image-20210129165524876](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165524876.png)

如上图所示,因为本项目涵盖了与WIFI和互联网相关的功能,因而开机时需要连接WiFi网络,这个过程不能及时完成,因而在这个等待的过程中,然显示屏空置未免浪费.本项目通过添加山大校徽logo作为开屏画面.

### 2. 开机校时功能

如果仅仅通过内置的DS1302作为时钟,因为晶振的问题,一天的误差可达六七秒,这种误差不符合我们的预期.因而在每次开机的时候,联网加入网络校时的功能,这样同北京时间的误差不超过一秒,极大的提高了本时钟的精度.

### 3. 加入了天气预报,风速,湿度,降雨概率的功能.

![image-20210129165538529](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165538529.png)

在完成要求的当日天气信息的基础上,加入了有关未来两天天气预报,风速,湿度,降雨概率的功能.

## 相关原理图,印制PCB版的展示

![image-20200907194012713](https://gitee.com/sun-roc/picture/raw/master/img/image-20200907194012713.png)

<img src="https://gitee.com/sun-roc/picture/raw/master/img/image-20200907193735508.png" alt="image-20200907193735508" style="zoom:50%;" />



## 调试过程

![image-20210129165824210](https://gitee.com/sun-roc/picture/raw/master/img/image-20210129165824210.png)

![image-20200907211947622](https://gitee.com/sun-roc/picture/raw/master/img/image-20200907211947622.png)



## 学习笔记和相关参考资料

### 笔记内容



### 参考资料

1. (生产商相关技术文档)https://www.espressif.com/zh-hans/support/documents/technical-documents

2. https://github.com/Toshik/TickerScheduler

3. http://tools.clz.me/image-to-bitmap-array

4. https://pan.baidu.com/s/1aROzKaKxbXm2DzMy2OtICA  提取码: q6qb
5. https://pan.baidu.com/s/1lZTOpTTXW0T0sAZQOpbFnA  提取码: fndp

