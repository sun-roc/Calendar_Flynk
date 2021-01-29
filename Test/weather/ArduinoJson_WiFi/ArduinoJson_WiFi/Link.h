#ifndef _BLINK_H
#define _BLINK_H
#include "Arduino.h"

char auth[] = "96737690c27d";  //私钥
char ssid[] = "ChinaNet-ChNS"; //WIFI名
char pswd[] = "s18953201606";  //密码

BlinkerButton UpButton1("upbutton"); //前面的代表程序里/后面的代表手机里 TMD只能用带数字的???

// void UpButton_callback(const String &state)
// {
//     BLINKER_LOG("get upbutton state: ", state);
//     Blinker.vibrate();
//     BLINKER_LOG("振动: ");
//     Get_Weather();
// }
LED
void dataRead(const String &data)
{
    BLINKER_LOG("Blinker readString: ", data);

    uint32_t BlinkerTime = millis();

    Blinker.vibrate();

}
void Set_BLink()
{
    Blinker.attachData(dataRead);
    // UpButton1.attach(UpButton_callback);
}
void Set_MyLink()
{
    Blinker.begin(auth, ssid, pswd);
    Set_BLink();                     //测试了好几遍,attach必须放在这个后面
    while (Blinker.connected() == 0) //等待连接
    {
        Blinker.run();
        BLINKER_LOG("等待");
        Blinker.delay(500);
    } //保证连接上
}

#endif