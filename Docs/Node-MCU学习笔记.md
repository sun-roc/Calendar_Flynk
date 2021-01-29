# Node-MCU学习笔记

> 参考链接:
>
> http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/
>
> https://www.bilibili.com/video/av90838317
>
> 库文件:http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/

# 1. 安装开发板驱动

 [安装 ESP8266-NodeMCU开发板驱动](http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/install-esp8266-nodemcu-driver/)

NodeMCU开发板不是即插即用的设备，因此我们需要安装驱动才能使用。

# 2. 安装Arduino IDE

[为ESP8266-NodeMCU搭建Arduino IDE开发环境](http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/nodemcu-arduino-ide/)

Arduino IDE要经过设置以后才能配合NodeMCU开发板使用。这一节我们一起学习如何设置IDE。
请注意:由于网络环境，很多朋友在下载ESP8266的Arduino IDE开发插件时出现了无法下载的情况。如果是这样，请[点击此处下载插件安装文件](https://pan.baidu.com/s/1BGT9Vw31mz5CdlPKyKYXUQ)（提取码：49c1），并运行该文件即可完成Arduino IDE配置。您接下来就可以使用Arduino IDE来开发ESP8266-NodeMCU开发板了。



**打开Arduino IDE 首选项**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/6-mod.jpg" alt="打开Arduino IDE首选项" style="zoom:50%;" />

------

**在Arduino IDE的“首选项”对话框中找到“附加开发板管理网址”**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/7-mod.jpg" alt="在Arduino IDE的“首选项”对话框中找到“附加开发板管理网址”" style="zoom:50%;" />

在Arduino IDE的“首选项”对话框中找到“附加开发板管理网址”

------

**输入网址**
将以下网址复制并且黏贴到到“附加开发板管理网址”栏中



Arduino

| 1    | http://arduino.esp8266.com/stable/package_esp8266com_index.json |
| ---- | ------------------------------------------------------------ |
|      |                                                              |



<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/8-mod.jpg" alt="输入NodeMCU开发板管理文件网址" style="zoom:50%;" />

输入NodeMCU开发板管理文件网址

------

**打开Arduino IDE的“开发板管理器”**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/9-mod.jpg" alt="打开Arduino IDE的“开发板管理器”" style="zoom:50%;" />

打开Arduino IDE的“开发板管理器”

------

**在“开发板管理器”的搜索栏中输入“esp8266”
**这一步需要您的电脑从互联网下载资料，所以请确保您的电脑已经连上了互联网。**
**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/10-mod.jpg" alt="在“开发板管理器”的搜索栏中输入“esp8266”" style="zoom:50%;" />

在“开发板管理器”的搜索栏中输入“esp8266”

------

**开始安装“esp8266开发板”插件文件**

![ 开始安装“esp8266开发板”定义文件](http://www.taichi-maker.com/wp-content/uploads/2019/02/11-mod.jpg)开始安装“esp8266开发板”定义文件

**请注意:由于网络环境，很多朋友在下载ESP8266的Arduino IDE开发插件时出现了无法下载的情况。如果是这样，请[点击此处下载插件安装文件](https://pan.baidu.com/s/1BGT9Vw31mz5CdlPKyKYXUQ)（提取码：49c1），并运行该文件即可完成Arduino IDE配置。您接下来就可以使用Arduino IDE来开发ESP8266-NodeMCU开发板了。**

------

**成功安装“esp8266开发板”插件文件**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/12-mod.jpg" alt="成功安装“esp8266开发板”定义文件" style="zoom:50%;" />

成功安装“esp8266开发板”定义文件

------

**在Arduino IDE的开发板菜单中找到“NodeMCU开发板”**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/13-mod.jpg" alt="在Arduino IDE的开发板菜单中找到“esp8266开发板”" style="zoom:50%;" />

在Arduino IDE的开发板菜单中找到“esp8266开发板”

------

**在Arduino IDE的开发板菜单中选中“NodeMCU开发板”**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/14-mod.jpg" alt="在Arduino IDE的开发板菜单中选中“esp8266开发板”" style="zoom:50%;" />

在Arduino IDE的开发板菜单中选中“esp8266开发板”

------

**设置Arduino IDE的NodeMCU开发板端口
**假如您不知道如何查看NodeMCU连接端口号，[请参考上一节内容](http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/install-esp8266-nodemcu-driver/)。**
**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/15-mod.jpg" alt="设置Arduino IDE的NodeMCU开发板端口" style="zoom:50%;" />

设置Arduino IDE的NodeMCU开发板端口

------

**打开Blink示例程序**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/16-mod.jpg" alt="打开Blink示例程序" style="zoom:50%;" />

打开Blink示例程序

------

**将Blink示例程序编译上传给NodeMCU**

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/17.jpg" alt="将Blink示例程序编译上传给NodeMCU" style="zoom:50%;" />

将Blink示例程序编译上传给NodeMCU

------

**确认NodeMCU开发板上LED开始闪烁**
程序上传完毕，如果看到NodeMCU开发板上的LED开始闪烁就说明驱动程序已经成功安装了。恭喜，您现在可以开始用Arduino IDE为NodeMCU编写控制程序了。

<img src="http://www.taichi-maker.com/wp-content/uploads/2019/02/esp8s66-nodemcu-led-blink.gif" alt="esp8s66-nodemcu开发板的LED开始闪烁" style="zoom:50%;" />esp8s66-nodemcu开发板的LED开始闪烁



# 3.VScode

> https://blog.csdn.net/CCC_122/article/details/97611228

## arduino IDE 配置

下载安装完成arduinoIDE后，我们需要打开设置一下。

打开文件->首选项

![img](https://img-blog.csdnimg.cn/20190728175909132.png)

为了方便，此处修改三个地方：

1.在arduinoIDE的安装目录下新建一个compile文件夹，并且设置项目文件夹位置到对应位置，这样做的目的是我们通过arduinoIDE下载的第三方库文件都会放在这个路径，方便管理。

2.编辑器语言选择English：由于考虑到大部分朋友的电脑系统是中文的，如果不设置为英文，在VScode上打印出来的信息会出现乱码。

3.打勾使用外部编辑器：这样操作arduinoIDE就变成只读的，不可以修改代码，这样我们就不用担心两边改过后内容不一致的问题了。

<img src="https://img-blog.csdnimg.cn/20190728211356496.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NDQ18xMjI=,size_16,color_FFFFFF,t_70" alt="img" style="zoom:50%;" />

##  添加自己下载的库

![image-20200624134949100](https://gitee.com/sun-roc/picture/raw/master/img/image-20200624134949100.png)

## vsode配置

1.打开VScode，点击左边的扩展图标，搜索arduino，然后安装插件

2.打开设置：File->Preferences->Setting，也可以通过按快捷键Ctrl+，来打开

3.在弹出的设置里搜索arduino，并且点击Edit in settings.json(也可直接在框中填)

**(加了报错的话也可以不用加)**

4.把arduinoIDE的安装路径添加到该文件中，注意路径是两个斜杠的，并且只需要定位到安装的目录就好，不需要精确定位到exe文件名。

![image-20200610223923126](https://gitee.com/sun-roc/picture/raw/master/img/image-20200610223923126.png)

(选好板子和端口)

![image-20200610232320034](https://gitee.com/sun-roc/picture/raw/master/img/image-20200610232320034.png)

串口监视器,要选择对应的波特率不然会乱码



用快捷键：
 上传代码: Alt + Ctrl + U
 编译代码: Alt + Ctrl + R
 随便选一个 方式，这里就用 上传代码吧Alt + Ctrl + U ，之后你会发现右下角 会有变化，在那儿可以选择一些对arduino 的设置。如图就知道了：



## 乱码

Arduino在vscode中输出乱码解决方法——亲测有效
问题
解决办法
最终效果
问题
Arduino版本 1.8.11
新版Arduino IDE在使用vscode时出现输出中文乱码的问题，博主踩坑无数后找到了可行

解决办法
1、找到vscode的arduino拓展的安装目录，找到util.js这个文件，以我电脑上的为例，（注意不同电脑下，路径不同，一般是在用户文件夹下，找不到的话就直接用文件管理器搜索）：

```C:\Users\Administrator\.vscode\extensions\vsciot-vscode.vscode-arduino-0.2.29\out\src\common\util.js ```

2、找到文件中的215行左右如下代码

        if (os.platform() === "win32") {
            try {
                const chcp = childProcess.execSync("chcp.com");
                codepage = chcp.toString().split(":").pop().trim();
            }
            catch (error) {
                outputChannel_1.arduinoChannel.warning(`Defaulting to code page 850 because chcp.com failed.\
                \rEnsure your path includes %SystemRoot%\\system32\r${error.message}`);
                codepage = "850";
            }
        }
    
    3、将上述的代码注释掉
    	/**
        if (os.platform() === "win32") {
            try {
                const chcp = childProcess.execSync("chcp.com");
                codepage = chcp.toString().split(":").pop().trim();
            }
            catch (error) {
                outputChannel_1.arduinoChannel.warning(`Defaulting to code page 850 because chcp.com failed.\
                \rEnsure your path includes %SystemRoot%\\system32\r${error.message}`);
                codepage = "850";
            }
        }
    	**/

4、重启Vscode

# 坑

1. **一个ino文件一个文件夹,不然会被当成一个工程,如果有重复函数会报错**
2. 程序有错误也会报code=1

exit code = 1



![image-20200612201844857](https://gitee.com/sun-roc/picture/raw/master/img/image-20200612201844857.png)

采坑,这里换文件,不然一直编译同一个,相当于切换工程

# 4.接入模式

## 1.接入点模式(Acess Point)

NodeMCU可以建立WiFi网络供其它设备连接。当NodeMCU以此模式运行时，我们可以使用手机搜索NodeMCU所发出的WiFi网络并进行连接。

```c
#include <ESP8266WiFi.h>        // 本程序使用ESP8266WiFi库
 
const char *ssid = "taichi-maker"; // 这里定义将要建立的WiFi名称。此处以"taichi-maker"为示例
                                   // 您可以将自己想要建立的WiFi名称填写入此处的双引号中
 
const char *password = "12345678";  // 这里定义将要建立的WiFi密码。此处以12345678为示例
                                    // 您可以将自己想要使用的WiFi密码放入引号内
                                    // 如果建立的WiFi不要密码，则在双引号内不要填入任何信息
 
void setup() {
  Serial.begin(9600);              // 启动串口通讯
 
  WiFi.softAP(ssid, password);     // 此语句是重点。WiFi.softAP用于启动NodeMCU的AP模式。
                                   // 括号中有两个参数，ssid是WiFi名。password是WiFi密码。
                                   // 这两个参数具体内容在setup函数之前的位置进行定义。
 
  
  Serial.print("Access Point: ");    // 通过串口监视器输出信息
  Serial.println(ssid);              // 告知用户NodeMCU所建立的WiFi名
  Serial.print("IP address: ");      // 以及NodeMCU的IP地址
  Serial.println(WiFi.softAPIP());   // 通过调用WiFi.softAPIP()可以得到NodeMCU的IP地址
}
 
void loop() { 
}
```



当您将以上程序上传以后,NodeMCU在每次启动以后，都会自动启动接入点模式。接入点WiFi的详细信息会通过串口监视器输出给用户查看，如下图所示：

![NodeMCUæ¥å¥ç¹æ¨¡å¼ï¼APï¼å¯å¨åä¸²å£çè§å¨è¾åºWiFiä¿¡æ¯](http://www.taichi-maker.com/wp-content/uploads/2019/03/nodeMcu-access-point-wifi.png)

**记得每次启动要按一下复位按钮**



## 2. 无线终端模式

```c
#include <ESP8266WiFi.h>        // 本程序使用ESP8266WiFi库
 
const char* ssid     = "taichi-maker";      // 连接WiFi名（此处使用taichi-maker为示例）
                                            // 请将您需要连接的WiFi名填入引号中
const char* password = "12345678";          // 连接WiFi密码（此处使用12345678为示例）
                                            // 请将您需要连接的WiFi密码填入引号中
                                            
void setup() {
  Serial.begin(9600);         // 启动串口通讯
  
  WiFi.begin(ssid, password);                  // 启动网络连接
  Serial.print("Connecting to ");              // 串口监视器输出网络连接信息
  Serial.print(ssid); Serial.println(" ...");  // 告知用户NodeMCU正在尝试WiFi连接
  
  int i = 0;                                   // 这一段程序语句用于检查WiFi是否连接成功
  while (WiFi.status() != WL_CONNECTED) {      // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。 
    delay(1000);                               // 如果WiFi连接成功则返回值为WL_CONNECTED                       
    Serial.print(i++); Serial.print(' ');      // 此处通过While循环让NodeMCU每隔一秒钟检查一次WiFi.status()函数返回值
  }                                            // 同时NodeMCU将通过串口监视器输出连接时长读秒。
                                               // 这个读秒是通过变量i每隔一秒自加1来实现的。
                                               
  Serial.println("");                          // WiFi连接成功后
  Serial.println("Connection established!");   // NodeMCU将通过串口监视器输出"连接成功"信息。
  Serial.print("IP address:    ");             // 同时还将输出NodeMCU的IP地址。这一功能是通过调用
  Serial.println(WiFi.localIP());              // WiFi.localIP()函数来实现的。该函数的返回值即NodeMCU的IP地址。
}
 
void loop() {                                   
}
```

假如您不清楚以上操作的原理，请让我在这里给您做一个简单的介绍。当NodeMCU成功连接WiFi以后，电脑就可以通过WiFi与NodeMCU相互通讯了。反之，如果NodeMCU没有成功连接WiFi，那电脑自然是无法与NodeMCU通讯的。因此我们可以通过电脑能否与NodeMCU通讯来判断NodeMCU是否成功联网?但是该如何让电脑和NodeMCU进行通讯呢？这就要借助Windows指令ping了。

从以上的串口监视器截屏我们知道了NodeMCU在网络中的IP地址是192.168.0.106。接下来我们只需要在Windows的“命令提示符”中输入`ping 192.168.0.106`然后回车。这时电脑将会向NodeMCU所在的IP地址192.168.0.106发送多个数据包。如果NodeMCU成功接收到了这些数据包，那么它会同样回复几个数据包给电脑。于是在“命令提示符”窗口中，我们看到了这几条`Reply from 192.168.0.106: bytes=32 ...`信息如下图红色方框标注部分所示：

**2. 自动连接最强信号WiFi网络**

假如我们的NodeMCU只在一个地方使用，它也就只需要知道一个WiFi网络的连接信息。但是如果NodeMCU需要在多个地方使用，这时候就需要它能存储多个地点的WiFi信息。通过以下示例程序，NodeMCU可以在它所处的网络环境里搜索预先存储好的WiFi。一旦找到预存的WiFi名称，NodeMCU将会使用预存的密码信息尝试连接该WiFi。如果同时找到多个预存WiFi，NodeMCU将会尝试连接信号最强的WiFi。

```c
#include <ESP8266WiFi.h>          // 本程序使用ESP8266WiFi库
#include <ESP8266WiFiMulti.h>   // 本程序使用ESP8266WiFiMulti库
 
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
 
void setup() {
  Serial.begin(9600);            // 启动串口通讯
 
//通过addAp函数存储  WiFi名称       WiFi密码
  wifiMulti.addAP("taichi-maker", "12345678");  // 这三条语句通过调用函数addAP来记录3个不同的WiFi网络信息。
  wifiMulti.addAP("taichi-maker2", "87654321"); // 这3个WiFi网络名称分别是taichi-maker, taichi-maker2, taichi-maker3。
  wifiMulti.addAP("taichi-maker3", "13572468"); // 这3个网络的密码分别是123456789，87654321，13572468。
                                                // 此处WiFi信息只是示例，请在使用时将需要连接的WiFi信息填入相应位置。
                                                // 另外这里只存储了3个WiFi信息，您可以存储更多的WiFi信息在此处。
                                                
  Serial.println("Connecting ...");         // 通过串口监视器输出信息告知用户NodeMCU正在尝试连接WiFi
  int i = 0;                                 
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print('.');                       // 将会连接信号最强的那一个WiFi信号。
  }                                           // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                                              // 此处while循环判断是否跳出循环的条件。
 
  
  Serial.println('\n');                     // WiFi连接成功后
  Serial.print("Connected to ");            // NodeMCU将通过串口监视器输出。
  Serial.println(WiFi.SSID());              // 连接的WiFI名称
  Serial.print("IP address:\t");            // 以及
  Serial.println(WiFi.localIP());           // NodeMCU的IP地址
}
 
void loop() { 
}
```

# 5.NodeMCU网络服务器

## 1.纯文本

```c
#include"ESP8266WiFi.h"
#include"ESP8266WiFiMulti.h"
#include"ESP8266WebServer.h"
 
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
 
ESP8266WebServer esp8266_server(80);// 建立ESP8266WebServer对象，对象名称为esp8266_server
                                    // 括号中的数字是网路服务器响应http请求的端口号
                                    // 网络服务器标准http端口号为80，因此这里使用80为端口号
 
void setup(void){
  Serial.begin(9600);          // 启动串口通讯
 
  //通过addAp函数存储  WiFi名称       WiFi密码
  wifiMulti.addAP("ChinaNet-ChNS", "s18953201606");  // 这三条语句通过调用函数addAP来记录3个不同的WiFi网络信息。
  wifiMulti.addAP("Honor", "020070ss"); // 这3个WiFi网络名称分别是taichi-maker, taichi-maker2, taichi-maker3。
  wifiMulti.addAP("taichi-maker3", "13572468"); // 这3个网络的密码分别是123456789，87654321，13572468。
                                                // 此处WiFi信息只是示例，请在使用时将需要连接的WiFi信息填入相应位置。
                                                // 另外这里只存储了3个WiFi信息，您可以存储更多的WiFi信息在此处。
 
  int i = 0;                                 
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print(i++); Serial.print(' ');    // 将会连接信号最强的那一个WiFi信号。
  }                                          // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                                             // 此处while循环判断是否跳出循环的条件。
 
  // WiFi连接成功后将通过串口监视器输出连接成功信息 
  Serial.println('\n');                     // WiFi连接成功后
  Serial.print("Connected to ");            // NodeMCU将通过串口监视器输出。
  Serial.println(WiFi.SSID());              // 连接的WiFI名称
  Serial.print("IP address:\t");            // 以及
  Serial.println(WiFi.localIP());           // NodeMCU的IP地址
  
//--------"启动网络服务功能"程序部分开始-------- //  此部分为程序为本示例程序重点1
  esp8266_server.begin();                   //  详细讲解请参见太极创客网站《零基础入门学用物联网》
  esp8266_server.on("/", handleRoot);       //  第3章-第2节 ESP8266-NodeMCU网络服务器-1
  esp8266_server.onNotFound(handleNotFound);        
//--------"启动网络服务功能"程序部分结束--------
  Serial.println("HTTP esp8266_server started");//  告知用户ESP8266网络服务功能已经启动
}
 
/* 以下函数语句为本示例程序重点3
详细讲解请参见太极创客网站《零基础入门学用物联网》
第3章-第2节 3_2_1_First_Web_Server 的说明讲解*/  
void loop(void){
  esp8266_server.handleClient();     // 处理http服务器访问
}
 
/* 以下两个函数为本示例程序重点2
详细讲解请参见太极创客网站《零基础入门学用物联网》
第3章-第2节 3_2_1_First_Web_Server 的说明讲解*/                                                                            
void handleRoot() {   //处理网站根目录“/”的访问请求 
  esp8266_server.send(200, "text/plain", "Hello from ESP8266");   // NodeMCU将调用此函数。
}
 
// 设置处理404情况的函数'handleNotFound'
void handleNotFound(){                                        // 当浏览器请求的网络资源无法在服务器找到时，
  esp8266_server.send(404, "text/plain", "404: Not found");   // NodeMCU将调用此函数。
}
```

如下所示，我首先要对”启动网络服务功能”程序部分进行详细讲解，这也是整个示例程序的第1个重点内容。

启动网络服务

```c
  web_server.begin();                          
  esp8266_server.on("/", handleRoot);           
  esp8266_server.onNotFound(handleNotFound); 
```



程序第一句`web_server.begin()`使用了ESP8266WebServer库中的`begin`函数。这个函数的作用是让ESP8266-NodeMCU来启动网络服务功能。该函数无需任何参数。

接下来的的语句`web_server.on("/", handleRoot)`相对复杂一些。这条语句调用了ESP8266WebServer库中的`on`函数，该函数的作用是**指挥NodeMCU来如何处理浏览器的http请求**。我们看到`on`函数一共有两个参数，第一个参数是字符串”/”，第二个参数是一个函数的名称handleRoot。这个handleRoot函数的具体内容，我后面会给您做详细讲解。现在请您留意`on`函数有两个参数，一个是字符串”/”，另一个是函数名handleRoot。



好了，现在请将您的思绪拉回到我们的NodeMCU程序中来。接下来我们来看`on`函数的第二个参数。这个参数是`handleRoot`函数的名字。`handlRoot`函数的主要作用是告诉NodeMCU该如何生成和发送网站首页给浏览器。不过关于这个`handleRoot`函数的具体内容，我会在接下来的教程中给您做详细讲解。现在我们需要把关注点集中在`on`函数上。

最后我们再来完整的看一下这条语句`esp8266_server.on("/", handleRoot)`。它的作用就是告诉NodeMCU，当有浏览器请求网站首页时，请执行handlRoot函数来生成网站首页内容然后发送给浏览器。





这里我们所看到的这行文字“404: Not found”正是因为NodeMCU没有名叫“LED”的页面，因此它会使用handleNotFound函数生成并发送给浏览器这个“错误提示”页面。既然讲到这里了，那么我们就来仔细看一看handleNotFound函数的具体内容。

```c
void handleNotFound(){                                
  esp8266_server.send(404, "text/plain", "404: Not found");  
}
```



handleNotFound函数只有一条语句： `esp8266_server.send(404, "text/plain", "404: Not found")`。这条语句调用了ESP8266WebServer库中的`send`函数。该函数的作用是生成并且发送http响应信息。也就是说，电脑浏览器所收到的网页信息都是通过`send`函数生成并且发送的。那么具体这个网页信息是如何生成的呢？这就要仔细看看`send`函数的几个参数内容了。

的http响应部分对它做过介绍。404是一个服务器状态码。它的含义是“客户端的请求有错误”。也就是说，浏览器在收到了状态码404后就知道，它所请求的页面在服务器上是不存在的。请留意，这个服务器状态码是专门给浏览器用的。我们是看不到它的。为了让我们也看到页面不存在的出错信息，`send`函数的最后一个参数使用了一个字符串”404: Not found”。这个字符串的内容才是真正显示在浏览器中供我们阅读的内容。你可以任意的改变这个字符串的内容。

到这里我们来小结一下。浏览器能够看懂的信息是send函数的第一个参数,它的类型是整数型，它的内容是数字404。而显示在浏览器中的出错信息是一个字符串型的参数。它是send函数的最后一个参数。在我们的示例程序里，它的内容是“404: Not found”。

`send`函数还有一个字符串参数“text/plain”。它的作用是**说明http响应体的信息类型**。在这段示例中，我们用“text/plain”的原因是要告诉浏览器后面的”404: Not found”为一段纯文本信息。这里当然也可以使用其它类型的信息。不过这一知识我们后续教程中会给您介绍。

为了让您更好的理解刚刚给您解释的内容，我来对这句`esp8266_server.send(404, "text/plain", "404: Not found")`做一下总结。

send函数一共有3个参数。第一个参数404是服务器状态码。第二个参数“text/plain”是说明http响应体信息类型。第三个参数“404: Not found”则是响应体的具体信息了。

细心的读者可能已经发现了。我在上面这段总结文字中指明了响应体这一概念。http响应是分为两部分的。第一部分是响应头，在我们这个示例中，响应头的内容就是404 text/plain。而响应体的内容则是404: Not found。

结束了handleNotFound的讲解我们最后再来看看示例程序中另一个用于生成和发送首页信息的函数：`handleRoot`。



这段示例程序与刚刚我们见到的handleNotFound函数非常相似。都是使用`send`函数生成并且发送http响应信息。

`send`函数的第一个参数200，它同样是一个服务器状态码，含义是“成功接收请求，并已完成整个处理过程”。 第二个参数text/plain的作用我刚刚给您讲过，不再赘述了。最后一个参数”Hello from ESP8266″正是我们在浏览器中看到的首页文字内容。

最后我们来看一下这段示例程序的第3个重点内容，也就是loop函数中唯一的一条语句`esp8266_server.handleClient()`。这句程序调用了`handleClient`函数。它的主要作用之一是检查有没有设备通过网络向NodeMCU发送请求。`函数handleClient`每次被调用时，NodeMCU都会检查一下是否有人发送http请求。因此我们需要把它放在loop函数中，从而确保它能经常被调用。假如我们的loop函数里有类似delay一类的函数延迟程序运行，那么这时候就一定要注意了。如果`handleClient`函数长时间得不到调用，NodeMCU的网络服务会变得很不稳定。因此在使用NodeMCU执行网络服务功能的时候，一定要确保`handleClient`函数经常得以调用。我在这里反复强调这一点是因为这一点非常关键，请务必注意！

## 2. 网页led

```c
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
#include "ESP8266WebServer.h"
 
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是 'wifiMulti'
 
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
 
void setup(void){
  Serial.begin(9600);   // 启动串口通讯
 
  pinMode(LED_BUILTIN, OUTPUT); //设置内置LED引脚为输出模式以便控制LED
  
  wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1"); // 将需要连接的一系列WiFi ID和密码输入这里
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2"); // ESP8266-NodeMCU再启动后会扫描当前网络
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3"); // 环境查找是否有这里列出的WiFi ID。如果有
  Serial.println("Connecting ...");                            // 则尝试使用此处存储的密码进行连接。
  
  int i = 0;                                 
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print(i++); Serial.print(' ');    // 将会连接信号最强的那一个WiFi信号。
  }                                          // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                                             // 此处while循环判断是否跳出循环的条件。
  
  // WiFi连接成功后将通过串口监视器输出连接成功信息 
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // 通过串口监视器输出连接的WiFi名称
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // 通过串口监视器输出ESP8266-NodeMCU的IP
 
  esp8266_server.begin();                           // 启动网站服务
  esp8266_server.on("/", HTTP_GET, handleRoot);     // 设置服务器根目录即'/'的函数'handleRoot'
  esp8266_server.on("/LED", HTTP_POST, handleLED);  // 设置处理LED控制请求的函数'handleLED'
  esp8266_server.onNotFound(handleNotFound);        // 设置处理404情况的函数'handleNotFound'
 
  Serial.println("HTTP esp8266_server started");//  告知用户ESP8266网络服务功能已经启动
}
 
void loop(void){
  esp8266_server.handleClient();                     // 检查http服务器访问
}
 
/*设置服务器根目录即'/'的函数'handleRoot'
  该函数的作用是每当有客户端访问NodeMCU服务器根目录时，
  NodeMCU都会向访问设备发送 HTTP 状态 200 (Ok) 这是send函数的第一个参数。
  同时NodeMCU还会向浏览器发送HTML代码，以下示例中send函数中第三个参数，
  也就是双引号中的内容就是NodeMCU发送的HTML代码。该代码可在网页中产生LED控制按钮。 
  当用户按下按钮时，浏览器将会向NodeMCU的/LED页面发送HTTP请求，请求方式为POST。
  NodeMCU接收到此请求后将会执行handleLED函数内容*/
void handleRoot() {       
  esp8266_server.send(200, "text/html", "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
}
 
//处理LED控制请求的函数'handleLED'
void handleLED() {                          
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));// 改变LED的点亮或者熄灭状态
  esp8266_server.sendHeader("Location","/");          // 跳转回页面根目录
  esp8266_server.send(303);                           // 发送Http相应代码303 跳转  
}
 
// 设置处理404情况的函数'handleNotFound'
void handleNotFound(){
  esp8266_server.send(404, "text/plain", "404: Not found"); // 发送 HTTP 状态 404 (未找到页面) 并向浏览器发送文字 "404: Not found"
}
```

## 3.获取引脚状态

为了便于学习，本节课中我们将使用D3引脚作为演示。选择D3引脚是因为它已经与开发板上的FLASH按键开关连接好了。

我们可以通过NodeMCU开发板上的FLASH按键控制D3引脚的电平。当我们没有按下该按键时，D3引脚将会保持高电平状态。当按下该按键后，D3引脚会变为低电平。

```c
#include <ESP8266WiFi.h>        // 本程序使用 ESP8266WiFi库
#include <ESP8266WiFiMulti.h>   //  ESP8266WiFiMulti库
#include <ESP8266WebServer.h>   //  ESP8266WebServer库
 
#define buttonPin D3            // 按钮引脚D3
 
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
 
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
 
bool pinState;  // 存储引脚状态用变量
 
void setup(){
  Serial.begin(9600);   // 启动串口通讯
 
  pinMode(buttonPin, INPUT_PULLUP); // 将按键引脚设置为输入上拉模式
 
  wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1"); // 将需要连接的一系列WiFi ID和密码输入这里
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2"); // ESP8266-NodeMCU再启动后会扫描当前网络
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3"); // 环境查找是否有这里列出的WiFi ID。如果有
  Serial.println("Connecting ...");                            // 则尝试使用此处存储的密码进行连接。
  
  int i = 0;                                 
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print(i++); Serial.print(' ');    // 将会连接信号最强的那一个WiFi信号。
  }                                          // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                                             // 此处while循环判断是否跳出循环的条件。
  // WiFi连接成功后将通过串口监视器输出连接成功信息 
  Serial.println('\n');                     // WiFi连接成功后
  Serial.print("Connected to ");            // NodeMCU将通过串口监视器输出。
  Serial.println(WiFi.SSID());              // 连接的WiFI名称
  Serial.print("IP address:\t");            // 以及
  Serial.println(WiFi.localIP());           // NodeMCU的IP地址
  
  esp8266_server.begin();                   // 启动网站服务                
  esp8266_server.on("/", handleRoot);       // 设置服务器根目录即'/'的函数'handleRoot'
  esp8266_server.onNotFound(handleNotFound);// 设置处理404情况的函数'handleNotFound'        
 
  Serial.println("HTTP esp8266_server started");//  告知用户ESP8266网络服务功能已经启动
}
 
void loop(){
  esp8266_server.handleClient();     // 处理http服务器访问
  pinState = digitalRead(buttonPin); // 获取引脚状态
}
 
/* 以下函数处理网站首页的访问请求。此函数为本示例程序重点1
详细讲解请参见太极创客网站《零基础入门学用物联网》
第3章-第2节“通过网络服务将开发板引脚状态显示在网页中”的说明讲解。*/                                                                       
void handleRoot() {   
  String displayPinState;                   // 存储按键状态的字符串变量
  
  if(pinState == HIGH){                     // 当按键引脚D3为高电平
    displayPinState = "Button State: HIGH"; // 字符串赋值高电平信息
  } else {                                  // 当按键引脚D3为低电平
    displayPinState = "Button State: LOW";  // 字符串赋值低电平信息
  }
  
  esp8266_server.send(200, "text/plain", displayPinState); 
                                            // 向浏览器发送按键状态信息  
}
 
// 设置处理404情况的函数'handleNotFound'
void handleNotFound(){                                        // 当浏览器请求的网络资源无法在服务器找到时，
  esp8266_server.send(404, "text/plain", "404: Not found");   // NodeMCU将调用此函数。
}
```

在以上程序的loop函数中，`pinState = digitalRead(buttonPin);` 语句将不断检查NodeMCU开发板D3引脚状态，也就是检查该引脚所连接的按键是否被按下。该状态将会存储与布尔变量pinState中。

变量pinState将会用于本程序的重点1，也就是handleRoot() 函数里。在handleRoot函数里，我们利用逻辑判断语句来对displayPinState 进行赋值。**如果按键没有被按下**，pinState为HIGH，这时候程序将会执行`displayPinState = "Button State: HIGH";`也就是为displayPinState的赋值为“Button State: HIGH”。这句话的意思是“按键引脚状态为高电平”。反之，当我们按下按键后，程序将会执行`displayPinState = "Button State: LOW";`也就是为displayPinState的赋值为“Button State: LOW”。

而当我们按下NodeMCU的Flash按键后，`并且刷新页面后`，会得到以下信息

以上示例中，我们需要刷新网页页面才能将按键的最新状态显示在网页中。为了实现页面的自动刷新，请您参考以下示例程序。

```c
#include <ESP8266WiFi.h>        // 本程序使用 ESP8266WiFi库
#include <ESP8266WiFiMulti.h>   //  ESP8266WiFiMulti库
#include <ESP8266WebServer.h>   //  ESP8266WebServer库
 
#define buttonPin D3            // 按钮引脚D3
 
ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象,对象名称是'wifiMulti'
 
ESP8266WebServer esp8266_server(80);// 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
 
bool pinState;                      // 存储引脚状态用变量
 
void setup(){
  Serial.begin(9600);          // 启动串口通讯
  delay(10);
  Serial.println("");
 
  pinMode(buttonPin, INPUT_PULLUP); // 将按键引脚设置为输入上拉模式
 
  wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1"); // 将需要连接的一系列WiFi ID和密码输入这里
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2"); // ESP8266-NodeMCU在启动后会扫描当前网络
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3"); // 环境查找是否有这里列出的WiFi ID。如果有
  Serial.println("Connecting ...");                            // 则尝试使用此处存储的密码进行连接。
                                                               // 另外这里只存储了3个WiFi信息，您可以存储更多
                                                               // 的WiFi信息在此处。
  int i = 0;                                 
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print(i++); Serial.print(' ');    // 将会连接信号最强的那一个WiFi信号。
  }                                          // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                                             // 此处while循环判断是否跳出循环的条件。
  // WiFi连接成功后将通过串口监视器输出连接成功信息 
  Serial.println('\n');                     // WiFi连接成功后
  Serial.print("Connected to ");            // NodeMCU将通过串口监视器输出。
  Serial.println(WiFi.SSID());              // 连接的WiFI名称
  Serial.print("IP address:\t");            // 以及
  Serial.println(WiFi.localIP());           // NodeMCU的IP地址
  
  esp8266_server.begin();                  
  esp8266_server.on("/", handleRoot);      
  esp8266_server.onNotFound(handleNotFound);        
 
  Serial.println("HTTP esp8266_server started");//  告知用户ESP8266网络服务功能已经启动
}
 
void loop(){
  esp8266_server.handleClient();     // 处理http服务器访问
  pinState = digitalRead(buttonPin); // 获取引脚状态
}                                                                   
 
/* 以下函数处理网站首页的访问请求。此函数为本示例程序重点1
详细讲解请参见太极创客网站《零基础入门学用物联网》
第3章-第2节“通过网络服务将开发板引脚状态显示在网页中”的说明讲解。*/    
void handleRoot() {   //处理网站目录“/”的访问请求 
  esp8266_server.send(200, "text/html", sendHTML(pinState));  
}
 
/*
建立用于发送给客户端浏览器的HTML代码。此代码将会每隔5秒刷新页面。
通过页面刷新，引脚的最新状态也会显示于页面中
*/
String sendHTML(bool buttonState){
  
  String htmlCode = "<!DOCTYPE html> <html>\n";
  htmlCode +="<head><meta http-equiv='refresh' content='5'/>\n";
  htmlCode +="<title>ESP8266 Butoon State</title>\n";
  htmlCode +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  htmlCode +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  htmlCode +="</style>\n";
  htmlCode +="</head>\n";
  htmlCode +="<body>\n";
  htmlCode +="<h1>ESP8266 BUTTON STATE</h1>\n";
  
  if(buttonState)
    {htmlCode +="<p>Button Status: HIGH</p>\n";}
  else
    {htmlCode +="<p>Button Status: LOW</p>\n";}
    
  htmlCode +="</body>\n";
  htmlCode +="</html>\n";
  
  return htmlCode;
}
 
// 设置处理404情况的函数'handleNotFound'
void handleNotFound(){                                        // 当浏览器请求的网络资源无法在服务器找到时，
  esp8266_server.send(404, "text/plain", "404: Not found");   // NodeMCU将调用此函数。
}
```

在以上示例程序中的`handleRoot`函数中，`esp8266_server.send(200, "text/html", sendHTML(pinState))`语句的的3个参数 `sendHTML(pinState)`调用了`sendHTML`函数。该函数的作用是建立一个可以定时刷新的HTML网页代码。通过定时刷新网页，开发板的引脚状态将会不断地在页面中进行更新。

此HTML网页代码是由`sendHTML`函数产生的。该函数建立了一个字符串变量，该字符串变量所存储的信息正是网页HTML代码。值得注意的是，该HTML代码会不断地检查变量pinState状态，并且根据pinState的状态改变HTML代码的信息，从而实现在网页上显示引脚状态。

此HTML代码中真正实现定时刷新网页功能的语句是`htmlCode +="\n";`在这条语句中，`http-equiv='refresh'`是告诉网页需要定时刷新，刷新频率是通过`content='5'`来控制的。这里的5即每5秒钟刷新一次页面。您可以通过改变此数值调整页面刷新频率。

每一次页面刷新，浏览器都会向NodeMCU发送HTTP请求。NodeMCU在收到浏览器请求后，将会把最新的HTML代码信息返回给浏览器。浏览器收到最新的HTML代码后将会在页面中显示引脚的状态。
以下是没有按下按键时的页面显示信息。

# 6.闪存系统基础操作

每一个ESP8266都配有一个闪存，这个闪存很像是一个小硬盘，我们上传的文件就被存放在这个闪存里。这个闪存的全称是Serial Peripheral Interface Flash File System（SPIFFS）。

除了可以存放上传的程序以外，我们还可以将网页文件或者系统配置文件存放在ESP8266的闪存中。在这节课里，我们将学习如何利用程序对闪存文件系统（SPIFFS）进行文件读取和修改。

## 1. 写文件

```c
//函数说明：
//SPIFFS.open(file_name, "w"); 
//以上函数有两个参数：
//第一个参数是被操作的文件名称，本示例中该文件为/notes.txt
//第二个参数"w" 代表写入文件信息。（如需了解如何读取信息，请参阅示例程序esp8266-flash-read）
#include <FS.h>  
 
String file_name = "/taichi-maker/notes.txt"; //被读取的文件位置和名称
 
void setup() {
  Serial.begin(9600);
  Serial.println("");
  
  Serial.println("SPIFFS format start");
  SPIFFS.format();    // 格式化SPIFFS
  Serial.println("SPIFFS format finish");
  
  if(SPIFFS.begin()){ // 启动SPIFFS
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
  
  File dataFile = SPIFFS.open(file_name, "w");// 建立File对象用于向SPIFFS中的file对象（即/notes.txt）写入信息
  dataFile.println("Hello IOT World.");       // 向dataFile写入字符串信息
  dataFile.close();                           // 完成文件写入后关闭文件
  Serial.println("Finished Writing data to SPIFFS");
}
 
void loop() {
}
```

在使用SPIFFS存储文件以前，我们必须使用`#include "FS.h"`,如以上程序第18行所示。

程序第20行，我们建立了一个字符串变量。该变量用于存储文件位置和文件名。其中`/`代表根目录。`/taichi-maker/`代表根目录下的`taichi-maker`目录。`notes.txt`代表着文件名称。

程序第27行`SPIFFS.format();`是对闪存文件系统进行格式化。这很想是我们对u盘进行格式化的操作。您无需每次使用闪存文件系统都对它进行格式化操作。这里仅仅是为了演示如何使用`SPIFFS.format();`。

程序第30行，`SPIFFS.begin()`用于启动闪存文件系统。在每次使用闪存文件系统以前都需要执行这一操作。如果闪存文件系统成功启动，该函数的返回值为布尔型，如果成功启动闪存文件形同，则返回真。否则将返回假。

程序第36行，`File dataFile = SPIFFS.open(file_name, "w");`这条语句中，open函数可用于对SPIFFS进行操作。该函数共有两个参数。第一个参数`file_name`是被操作的文件名称，本示例中该文件为/taichi-maker/notes.txt
第二个参数`"w"`代表此操作为向SPIFFS写入文件信息。请注意：如果文件系统没有/taichi-maker/notes.txt文件，此操作将会在文件系统中建立该文件。如果文件系统有该文件，则程序将会重新建立该文件，即原有文件信息将会被覆盖。

程序第37行`dataFile.println("Hello IOT World.");`用于向dataFile文件写入信息。信息内容为“Hello IOT World.”。

程序第38行`dataFile.close();`用于关闭dataFile文件。结束文件操作后，应执行此操作。

## 2.读文件

```c
#include <FS.h>
 
String file_name = "/taichi-maker/notes.txt";              //被读取的文件位置和名称
 
void setup() {
  Serial.begin(9600);
  Serial.println("");
  
  if(SPIFFS.begin()){ // 启动闪存文件系统
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
 
  //确认闪存中是否有file_name文件
  if (SPIFFS.exists(file_name)){
    Serial.print(file_name);
    Serial.println(" FOUND.");
  } else {
    Serial.print(file_name);
    Serial.print(" NOT FOUND.");
  }
 
  //建立File对象用于从SPIFFS中读取文件
  File dataFile = SPIFFS.open(file_name, "r"); 
 
  //读取文件内容并且通过串口监视器输出文件信息
  for(int i=0; i<dataFile.size(); i++){
    Serial.print((char)dataFile.read());       
  }
 
  //完成文件读取后关闭文件
  dataFile.close();                           
}
 
void loop() {
}
```

以上程序第36行，`SPIFFS.exists(file_name)`用于检查闪存文件系统中有file_name文件（注：file_name变量具体信息在本程序第23行）。该函数返回值为布尔型。如果文件存在则返回真，否则将返回假。

以上程序第45行，`File dataFile = SPIFFS.open(file_name, "r");`这条语句中，open函数可用于对SPIFFS进行操作。该函数共有两个参数。第一个参数`file_name`是被操作的文件名称，本示例中该文件为/taichi-maker/notes.txt
第二个参数`"r"`代表此操作为读取文件信息。

以上程序第48行的for循环语句中，循环条件使用了函数`dataFile.size()`。该函数将会返回dataFile的大小。循环语句体中，`dataFile.read()`将会读取dataFile文件内容。每调用一次该含税都会返回dataFile文件中一个字符。再次调用，将会返回下一个字符。以此类推，直到dataFile结尾。通过for循环语句，程序将会依次读取dataFile文件内容，并且将文件内容逐字符输出于串口监视器中。

## 3.添加程序

```c
#include <FS.h>
 
String file_name = "/taichi-maker/notes.txt";              //被读取的文件位置和名称
 
void setup() {
  Serial.begin(9600);
  Serial.println("");
  
  if(SPIFFS.begin()){ // 启动闪存文件系统
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
 
  //确认闪存中是否有file_name文件
  if (SPIFFS.exists(file_name)){
    
    Serial.print(file_name);
    Serial.println(" FOUND.");
 
    File dataFile = SPIFFS.open(file_name, "a");// 建立File对象用于向SPIFFS中的file对象（即/notes.txt）写入信息
    dataFile.println("This is Appended Info."); // 向dataFile添加字符串信息
    dataFile.close();                           // 完成文件操作后关闭文件   
    Serial.println("Finished Appending data to SPIFFS");
    
  } else {
    Serial.print(file_name);
    Serial.print(" NOT FOUND.");
  }
                        
}
 
void loop() {}
```

在以上程序的第40行里，`File dataFile = SPIFFS.open(file_name, "a");`这条语句中，open函数可用于对SPIFFS进行操作。该函数共有两个参数。第一个参数`file_name`是被操作的文件名称,第二个参数`"a"`代表向该文件添加信息。请留意，此处的添加信息是不会删除文件内原有信息，而是在原有信息后面添加新的信息。这与但写入操作是有所区别的。写入操作是将文件内容完全清除，重新写入新信息。
,
程序的第41行，`dataFile.println("This is Appended Info.")`，此语句作用将会向dataFile文件尾部添加双引号中的信息内容，也就是在文件尾部添加“This is Appended Info.”。

## 4. 通过程序读取目录内容

```c
#include <FS.h>
 
String file_name = "/taichi-maker/myFile.txt"; //被读取的文件位置和名称
String folder_name = "/taichi-maker";         //被读取的文件夹
 
void setup() {
  Serial.begin(9600);
  Serial.println("");
  
  if(SPIFFS.begin()){ // 启动闪存文件系统
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
 
  File dataFile = SPIFFS.open(file_name, "w");// 建立File对象用于向SPIFFS中的file对象（即/notes.txt）写入信息
  dataFile.println("Hello Taichi-Maker.");    // 向dataFile写入字符串信息
  dataFile.close();                           // 完成文件写入后关闭文件
  Serial.println(F("Finished Writing data to SPIFFS"));
 
  // 显示目录中文件内容以及文件大小
  Dir dir = SPIFFS.openDir(folder_name);  // 建立“目录”对象
  
  while (dir.next()) {  // dir.next()用于检查目录中是否还有“下一个文件”
    Serial.println(dir.fileName()); // 输出文件名
  }
}
 
void loop() {
}
```

本程序第23行建立了一个字符串变量。该变量用于存储文件夹名。其中`/`代表根目录。`/taichi-maker/`代表根目录下的`taichi-maker`目录。

本程序第41行`SPIFFS.openDir(folder_name)`中的openDir函数函将返回一个“目录”对象并且赋值给dir。此”目录”对象正是folder_name所存储的`/taichi-maker/`目录。后续程序对dir的所有操作都是针对`/taichi-maker/`所执行的。

本程序第43行while循环语句的循环条件是`dir.next()`的返回值。`dir.next()`函数用于检查dir文件夹内的文件。我们可以想象dir文件夹里有一个指针，每一次调用next函数都会让指针向下挪动一格。每一次挪动一格，如果下一个位置有文件，则返回真。否则将会返回假。因此，`while (dir.next())`循环语句中的内容会依次显示dir文件夹中的每一个文件的文件名。

## 5.删除文件

```c
#include <FS.h>
 
String file_name = "/taichi-maker/notes.txt";              //被读取的文件位置和名称
 
void setup() {
  Serial.begin(9600);
  Serial.println("");
  
  if(SPIFFS.begin()){ // 启动闪存文件系统
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
  
  //从闪存中删除file_name文件
  if (SPIFFS.remove(file_name)){
    
    Serial.print(file_name);
    Serial.println(" remove sucess");
    
  } else {
    Serial.print(file_name);
    Serial.println(" remove fail");
  }                       
}
 
void loop() {
}
```

以上程序中第25行，通过使用`SPIFFS.remove(file_name)`将`file_name`所指代的文件进行了删除操作。另外，`SPIFFS.remove(file_name)`的返回值为布尔型。如果文件删除执行成功则返回真，否则返回假。

## 6. 系统信息

```c
#include <FS.h>
 
FSInfo fs_info;
 
void setup() {
  Serial.begin(9600);
 
  SPIFFS.begin();       //启动SPIFFS
  Serial.println("");
  Serial.println("SPIFFS Started.");
 
  // 闪存文件系统信息
  SPIFFS.info(fs_info);
 
  // 可用空间总和（单位：字节）
  Serial.print("totalBytes: ");     
  Serial.print(fs_info.totalBytes); 
  Serial.println(" Bytes"); 
 
  // 已用空间（单位：字节）
  Serial.print("usedBytes: "); 
  Serial.print(fs_info.usedBytes);
  Serial.println(" Bytes"); 
 
  // 最大文件名字符限制（含路径和'\0'）
  Serial.print("maxPathLength: "); 
  Serial.println(fs_info.maxPathLength);
 
  // 最多允许打开文件数量
  Serial.print("maxOpenFiles: "); 
  Serial.println(fs_info.maxOpenFiles);
 
  // 存储块大小
  Serial.print("blockSize: "); 
  Serial.println(fs_info.blockSize);
 
  // 存储页大小
  Serial.print("pageSize: ");
  Serial.println(fs_info.pageSize);
}
 
void loop() {
}
```

以上程序第16行语句`FSInfo fs_info;`建立了FSInfo 对象，用于存储闪存状态信息。

以上程序第26行语句`SPIFFS.info(fs_info);`。通过info函数将闪存状态信息赋给fs_info。后续的程序中，通过一系列语句将闪存状态信息通过串口监视器输出。具体信息内容可参考程序注释部分。

# 7.上传闪存插件

##### 1. 下载 Arduino-ESP8266闪存文件插件程序

您有两种方法可以下载该插件程序。

**第一种**方法是通过[点击此链接进入 Arduino-ESP8266官方GitHub页面下载](https://github.com/esp8266/arduino-esp8266fs-plugin/releases)。详情请见以下截图：

![esp8266fs下载页面](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266fs-download.jpg)esp8266fs下载页面

由于GitHub网站服务器在国外，有些朋友登录该网站会有些困难。如果是这样的话，那么您也可以[点击此链接进入太极创客网站下载页面去下载该插件](http://www.taichi-maker.com/homepage/download/#esp8266fs)。

##### 2. 确定Arduino IDE项目文件夹位置

![Arduino-ide-首选项菜单项](http://www.taichi-maker.com/wp-content/uploads/2020/02/Arduino-ide-preferences.jpg)Arduino-ide-首选项菜单项

![Arduino-IDE-项目文件夹位置](http://www.taichi-maker.com/wp-content/uploads/2020/02/Arduino-Project-Folder.jpg)Arduino-IDE-项目文件夹位置

##### 3. 通过资源管理器打开Arduino IDE项目文件夹并建立tools文件夹

![在项目文件夹中建立名称为tools的文件夹](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266fs-tools-folder.jpg)在项目文件夹中建立名称为tools的文件夹

##### 4. 解压缩esp8266fs插件压缩包，并将解压缩后的文件内容粘贴到项目文件夹中

![esp8266fs解压缩](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266fs-unzip.jpg)esp8266fs解压缩

![解压缩后可找到esp8266fs文件夹](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266fs-unzipped.jpg)解压缩后可找到esp8266fs文件夹

![将esp8266fs文件夹粘贴到tools文件夹里](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266fs-paste.jpg)将esp8266fs文件夹粘贴到tools文件夹里

##### 5. 重新启动Arduino IDE

为了让ESP8266FS闪存文件上传插件生效，我们需要重新启动Arduino IDE

![Arduino IDE 启动](http://www.taichi-maker.com/wp-content/uploads/2020/02/Arduino-ide-logo.jpg)Arduino IDE 启动



##### 5. 检查“工具”菜单确认插件安装

![ESP8266 data upload 菜单项](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266-data-upload-menu.jpg)ESP8266 data upload 菜单项

##### 6. 根据上传的文件总大小来设置闪存大小

![设置esp8266闪存大小](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266-flash-size-settings.jpg)设置esp8266闪存大小

##### 7. 将需要上传的文件保存在程序路径下的data文件夹中

![将需要上传到esp8266闪存文件系统的文件保存在data目录中](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266-flash-data-storage.jpg)将需要上传到esp8266闪存文件系统的文件保存在data目录中

##### 8. 将需要上传的文件保存在程序路径下的data文件夹中

![通过ESP8266 Sketch Data Upload可以将data文件夹里的文件上传](http://www.taichi-maker.com/wp-content/uploads/2020/02/esp8266-flash-data-upload.jpg)通过ESP8266 Sketch Data Upload可以将data文件夹里的文件上传

假如您不确定具体文件如何存储，请点击以下链接下载示例程序压缩包。

**这个是上传所用的html,image文件**程序还要单独再传一遍

# 8. 闪存系统的网络服务器

## 1.html+css+JavaScript网页

```c
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <FS.h>  

ESP8266WiFiMulti wifiMulti;     // 建立ESP8266WiFiMulti对象

ESP8266WebServer esp8266_server(80);    // 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）

void setup() {
  Serial.begin(9600);          // 启动串口通讯
  Serial.println("");
  
  wifiMulti.addAP("ChinaNet-ChNS", "s18953201606");  // 将需要连接的一系列WiFi ID和密码输入这里
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2"); // ESP8266-NodeMCU再启动后会扫描当前网络
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3"); // 环境查找是否有这里列出的WiFi ID。如果有
  Serial.println("Connecting ...");                            // 则尝试使用此处存储的密码进行连接。
  
  int i = 0;  
  while (wifiMulti.run() != WL_CONNECTED) { // 尝试进行wifi连接。
    delay(1000);
    Serial.print(i++); Serial.print(' ');
  }
  
  // WiFi连接成功后将通过串口监视器输出连接成功信息 
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // 通过串口监视器输出连接的WiFi名称
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // 通过串口监视器输出ESP8266-NodeMCU的IP

  if(SPIFFS.begin()){                       // 启动闪存文件系统
    Serial.println("SPIFFS Started.");
  } else {
    Serial.println("SPIFFS Failed to Start.");
  }
  
  esp8266_server.onNotFound(handleUserRequet);      // 告知系统如何处理用户请求

  esp8266_server.begin();                           // 启动网站服务
  Serial.println("HTTP server started");
}

void loop(void) {
  esp8266_server.handleClient();                    // 处理用户请求
}

// 处理用户浏览器的HTTP访问
void handleUserRequet() {         
     
  // 获取用户请求网址信息
  String webAddress = esp8266_server.uri();
  
  // 通过handleFileRead函数处处理用户访问
  bool fileReadOK = handleFileRead(webAddress);

  // 如果在SPIFFS无法找到用户访问的资源，则回复404 (Not Found)
  if (!fileReadOK){                                                 
    esp8266_server.send(404, "text/plain", "404 Not Found"); 
  }
}

bool handleFileRead(String path) {            //处理浏览器HTTP访问

  if (path.endsWith("/")) {                   // 如果访问地址以"/"为结尾
    path = "/index.html";                     // 则将访问地址修改为/index.html便于SPIFFS访问
  } 
  
  String contentType = getContentType(path);  // 获取文件类型
  
  if (SPIFFS.exists(path)) {                     // 如果访问的文件可以在SPIFFS中找到
    File file = SPIFFS.open(path, "r");          // 则尝试打开该文件
    esp8266_server.streamFile(file, contentType);// 并且将该文件返回给浏览器
    file.close();                                // 并且关闭文件
    return true;                                 // 返回true
  }
  return false;                                  // 如果文件未找到，则返回false
}

// 获取文件类型
String getContentType(String filename){
  if(filename.endsWith(".htm")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".css")) return "text/css";
  else if(filename.endsWith(".js")) return "application/javascript";
  else if(filename.endsWith(".png")) return "image/png";
  else if(filename.endsWith(".gif")) return "image/gif";
  else if(filename.endsWith(".jpg")) return "image/jpeg";
  else if(filename.endsWith(".ico")) return "image/x-icon";
  else if(filename.endsWith(".xml")) return "text/xml";
  else if(filename.endsWith(".pdf")) return "application/x-pdf";
  else if(filename.endsWith(".zip")) return "application/x-zip";
  else if(filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

```

# 9.网络客户端

在本节课程中，我们一起学习如何让ESP8266-NodeMCU开发板扮演网络客户端的角色，从而向网络服务器发送HTTP请求以获取服务器响应信息。

[ESP8266-Arduino库](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/)中有两个库用于控制ESP8266与网络服务器进行通讯。他们是[WiFiClient库](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/wificlient/)和[ESP8266HTTPClient库](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/esp8266httpclient/)。

这两个库虽然功能相似，但是他们却是截然不同的两个库。[ESP8266HTTPClient库](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/esp8266httpclient/)相对简单易用。该库的库函数可以自动生成客户端请求信息并解析服务器响应信息。但正是由于该库的库函数为我们做了所有底层工作，这就导致该库不如[WiFiclient库](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/wificlient/)灵活。假如我们需要用ESP8266建立自定义客户端请求信息时，就要用WiFiClient库来实现了。另外WiFiClient库在解析服务器响应信息时可以使用丰富的STREAM类函数，这也为我们提供了很多便利。

### 示例1. 使用HTTPClient库

```c
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
// 测试HTTP请求用的URL。注意网址前面必须添加"http://"
#define URL "http://www.example.com"
 
// 设置wifi接入信息(请根据您的WiFi信息进行修改)
const char* ssid = "taichimaker";
const char* password = "12345678";
 
void setup() {
  //初始化串口设置
  Serial.begin(9600);
 
  //设置ESP8266工作模式为无线终端模式
  WiFi.mode(WIFI_STA);
 
  //开始连接wifi
  WiFi.begin(ssid, password);
 
  //等待WiFi连接,连接成功打印IP
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi Connected!");
  
  httpClientRequest();  
}
 
void loop() {}
 
// 发送HTTP请求并且将服务器响应通过串口输出
void httpClientRequest(){
 
  //重点1 创建 HTTPClient 对象
  HTTPClient httpClient;
 
  //重点2 通过begin函数配置请求地址。此处也可以不使用端口号和PATH而单纯的
  httpClient.begin(URL); 
  Serial.print("URL: "); Serial.println(URL);
 
  //重点3 通过GET函数启动连接并发送HTTP请求
  int httpCode = httpClient.GET();
  Serial.print("Send GET request to URL: ");
  Serial.println(URL);
  
  //重点4. 如果服务器响应HTTP_CODE_OK(200)则从服务器获取响应体信息并通过串口输出
  //如果服务器不响应HTTP_CODE_OK(200)则将服务器响应状态码通过串口输出
  if (httpCode == HTTP_CODE_OK) {
    // 使用getString函数获取服务器响应体内容
    String responsePayload = httpClient.getString();
    Serial.println("Server Response Payload: ");
    Serial.println(responsePayload);
  } else {
    Serial.println("Server Respose Code：");
    Serial.println(httpCode);
  }
 
  //重点5. 关闭ESP8266与服务器连接
  httpClient.end();
}
```

程序重点讲解
重点1. 声明HTTPClient对象，对象名称httpClient。后续程序中，我们将使用对象httpClient控制ESP8266的网络通讯。

重点2. 通过[ESP8266HTTPClient库的begin函数](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/esp8266httpclient/begin/)来设置ESP8266发送HTTP请求的目标URL。

重点3. 通过[ESP8266HTTPClient库的GET函数](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/esp8266httpclient/get/)向服务器发送HTTP请求。

重点4. 以上重点3中GET函数的返回值是网络服务器响应状态码。根据该状态码，我们可以判断服务器是否成功接收到了ESP8266客户端的请求。如果服务器成功接收到请求，我们就可以在接下来使用[getString](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/)函数来获取服务器响应报文（服务器响应体）信息，并且将该信息传递给responsePayload变量以便我们在后面通过串口监视器显示服务器响应报文。（这一报文信息正是www.example.com网站的首页HTML源代码）。

重点5.执行完以上操作后，我们将关闭ESP8266与服务器连接。这里是通过ESP8266HTTPClient库的[end](http://www.taichi-maker.com/homepage/iot-development/iot-dev-reference/esp8266-c-plus-plus-reference/esp8266httpclient/end/)函数来实现这一操作的。

### 示例2. 使用WiFiClient库

```c
#include <ESP8266WiFi.h>
 
const char* host = "www.example.com"; // 网络服务器地址
const int httpPort = 80;              // http端口80
 
// 设置wifi接入信息(请根据您的WiFi信息进行修改)
const char* ssid = "taichimaker";
const char* password = "12345678";
 
void setup() {
  //初始化串口设置
  Serial.begin(9600);
  Serial.println("");
 
  //设置ESP8266工作模式为无线终端模式
  WiFi.mode(WIFI_STA);
 
  //开始连接wifi
  WiFi.begin(ssid, password);
 
  //等待WiFi连接,连接成功打印IP
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected!");
  
  wifiClientRequest();  
}
 
void loop(){}
 
// 向服务器发送HTTP请求
void wifiClientRequest(){
  // 建立WiFi客户端对象，对象名称client
  WiFiClient client;    
 
  // 建立字符串，用于HTTP请求
  String httpRequest =  String("GET /") + " HTTP/1.1\r\n" +
                        "Host: " + host + "\r\n" +
                        "Connection: close\r\n" +
                        "\r\n";
  
  // 通过串口输出连接服务器名称以便查阅连接服务器的网址                      
  Serial.print("Connecting to "); 
  Serial.print(host); 
 
  // 连接网络服务器，以下段落中的示例程序为本程序重点1
  // 请参考太极创客网站中关于本程序的讲解页面获取详细说明信息。网址：
  // http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/esp8266-nodemcu-web-client/http-request/
  if (client.connect(host, httpPort)){ 
    Serial.println(" Success!");        // 连接成功后串口输出“Success”信息
    
    client.print(httpRequest);          // 向服务器发送HTTP请求
    Serial.println("Sending request: ");// 通过串口输出HTTP请求信息内容以便查阅
    Serial.println(httpRequest);     
    
    // 通过串口输出网络服务器响应信息， 以下段落中的示例程序为本程序重点2
    // 请参考太极创客网站中关于本程序的讲解页面获取详细说明信息。网址：
    // http://www.taichi-maker.com/homepage/esp8266-nodemcu-iot/iot-c/esp8266-nodemcu-web-client/http-request/
    Serial.println("Web Server Response:");        
    while (client.connected() || client.available()){ 
      if (client.available()){
        String line = client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    
    client.stop();                      // 断开与服务器的连接
    Serial.print("Disconnected from "); // 并且通过串口输出断开连接信息
    Serial.print(host);
    
  } else{    // 如果连接不成功则通过串口输出“连接失败”信息
    Serial.println(" connection failed!");
    client.stop();
  }  
}
```

程序重点讲解

重点1：实现网络服务器连接

这部分逻辑判断语句中的判断条件是`client.connect(host, httpPort)`的返回值。ESP8266所实现的网络客户端是通过`connect`函数来实现与网络服务器的连接的。被连接的网络服务器网址为connect函数的第一个参数，即host。这里的第二个参数`httpPort`则是连接网络服务器的端口编号。关于host 和 httpPort的具体定义都在程序刚一开始的部分。

如果ESP8266所建立的网络客户端成功与网络服务器建立了连接，`connect`函数将会返回“真”，否则将会返回“假”。利用`connect`函数返回值，程序可以根据网络服务器的连接状况来决定具体执行哪一个操作。即：

– 连接成功则通过后续的`while`循环语句来获取网络服务器的HTTP响应信息,并且将信息通过串口输出。

– 连接不成功则通过串口输出“连接失败”信息。

重点2：获取网络服务器响应信息并且通过串口输出

这里的 `while (client.connected() || client.available())`循环语句判断条件由两个函数的返回值来决定。

第一个条件是 `client.connected()` 的返回值。`connected()`这个函数用于检查当前ESP8266与网络服务器的连接情况。如果连接状态为“真”，则返回真。否则返回“假”。

第二个条件是 `client.available()`的返回值。`available()`函数用于检查网络客户端是否有接收到服务器发来的信息。如果有信息则返回真，否则返回“假”。

利用以上两个条件进行“或”运算所得到的结果即是这里`while`循环语句的判断条件。换句话说，就是当ESP8266与服务器保持连接以及服务器有信息发送给ESP8266这两个条件满足一个，while循环语句体就会执行循环。当这两个条件**都不满足了**，则跳出循环。

接下来我们看一下`while`循环的具体内容。这里我们使用了一个逻辑判断语句。判断条件再次出现了`client.available()`。在ESP8266与网络服务器通过`connect`函数建立连接并且ESP8266发送了HTTP请求以后，ESP8266并不会马上就收到服务器的响应信息。造成这个情况的原因有很多个，其中主要原意是服务器接到HTTP响应后，也许需要处理其它客户端的响应或者进行其它工作。这就导致服务器在响应ESP8266时会产生延迟。另外我们的网络环境也会产生延迟。也就是说服务器从发出响应到我们的ESP8266接收到响应这个过程是受到到网络环境等等因素影响的。

基于以上原因，我们需要让ESP8266客户端在与网络服务器取得连接以后在原地待命。一旦ESP8266客户端接收到服务器的响应信息，available函数将会返回“真”值，这时才让ESP8266客户端开始检查收到的响应信息具体是什么。这个检查工作是通过逻辑判断语句中的，`client.readStringUntil('\n')`来实现的。

关于`readStringUntil`函数的具体用法，由于涉及到stream的概念，我们在下一节给各位详细讲解。这里请各位了解一点就是`client.readStringUntil('\n')`函数会将服务器响应信息中逐行分解为字符串。这些字符串会赋值给调用该函数的位置，也就是赋值给`line`这个字符串变量中。

# Json

JSON文件乍一看很复杂，但只要注意以下几点就可以分析出JSON数据内容。

**首先注意以下符号的含义：**
：用于分隔数据的“名”和“值”
{} 标注对象内容
[]标注数组内容
，分隔数据、对象和数组

**另外注意：**
对象用于存放数据（名值对）。
对象**不能**直接存放对象或数组。
数组存放元素有序号（序号起始值0）。
数组**不能**直接存放数据（名值对）。

