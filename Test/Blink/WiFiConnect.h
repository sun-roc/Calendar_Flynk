#ifndef _WiFiCONNECT_H //功能:初始化串口&链接WiFi
#define _WiFiCONNECT_H

#include "Arduino.h"
#include "ESP8266WiFiMulti.h"

ESP8266WiFiMulti wifiMulti;
void WiFiconnect()
{
    Serial.begin(9600); // 启动串口通讯
    //通过addAp函数存储  WiFi名称       WiFi密码
    wifiMulti.addAP("ChinaNet-ChNS", "s18953201606"); // 这三条语句通过调用函数addAP来记录3个不同的WiFi网络信息。
    wifiMulti.addAP("taichi-maker2", "87654321");     
    wifiMulti.addAP("taichi-maker3", "13572468");     // 另外这里只存储了3个WiFi信息，您可以存储更多的WiFi信息在此处。
    //开始连接
    Serial.println("Connecting ..."); // 通过串口监视器输出信息告知用户NodeMCU正在尝试连接WiFi
    while (wifiMulti.run() != WL_CONNECTED)
    {                      // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
        Blinker.delay(1000);       // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
        Serial.print('.'); // 将会连接信号最强的那一个WiFi信号。
    }                      // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                           // 此处while循环判断是否跳出循环的条件。
    Serial.println('\n');           // WiFi连接成功后
    Serial.print("Connected to :");  // NodeMCU将通过串口监视器输出。
    Serial.println(WiFi.SSID());    // 连接的WiFI名称
    Serial.print("IP 地址:\t");  // 以及
    Serial.println(WiFi.localIP()); // NodeMCU的IP地址
}

#endif