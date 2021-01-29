#ifndef _LINK_H
#define _LINK_H





#include "Arduino.h"
#include <Blinker.h>
char auth[] = "96737690c27d";
char ssid[] = "ChinaNet-ChNS";
char pswd[] = "s18953201606";
// 新建组件对象
BlinkerButton Button1("btn-abc");
BlinkerNumber Number1("num-abc");

int counter = 0;

// 按下按键即会执行该函数
void button1_callback(const String &state)
{
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String &data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
    Number1.print(counter);
}

void Set_Link()
{
    // 初始化串口
    Serial.begin(9600);

    BLINKER_DEBUG.stream(Serial);

    // 初始化有LED的IO
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    Button1.attach(button1_callback);
}
void Loop_Link()
{
    Blinker.run();
}
#endif