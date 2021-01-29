#ifndef _TIMER_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _TIMER_H
//关联必要库
#include "Arduino.h"
//关联非必要库
#include "OLED.h"
// #include"SetTime.h"
//项目主要依存库
#include <ThreeWire.h>
#include "RtcDS1302.h"

//链接方式
// CONNECTIONS:
// DS1302 CLK/SCLK --> D4
// DS1302 DAT/IO --> D3
// DS1302 RST/CE --> D5
// DS1302 VCC --> 3.3v - 5v
// DS1302 GND --> GND
ThreeWire myWire(/*IO*/ D3, /*SCLK*/ D4, /*RST*/ D0); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
uint16_t set_year = 2020; // "2020"
uint8_t set_month = 1;    // "06"月
uint8_t set_day = 1;      // "22" 日，月份中的第几天，没有前导零，1 到 31

uint8_t set_hour = 0;   // "10"小时，24 小时格式，没有前导零，0 到 23
uint8_t set_minute = 0; // "23"分钟，有前导零的分钟数，00 到 59
uint8_t set_second = 1; // "14"秒数，有前导零，00 到 59

uint8_t clock_hour = 0;
uint8_t clock_minute = 0;
uint8_t clock_second = 0;
String set_week = "星期一"; // "星期一"
void Set_Timer()
{
    Rtc.Begin(); //启动RTC模块
    //将全局变量写入RTC芯片
    Rtc.SetIsWriteProtected(true);
    Rtc.SetIsWriteProtected(false);
    RtcDateTime now_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
    Rtc.SetDateTime(now_time);
    RtcDateTime clock_time = Rtc.GetDateTime();
    clock_hour = clock_time.Hour();
    clock_minute = clock_time.Minute()-1;
    clock_second = clock_time.Second();
    //异常判断
    if (Rtc.GetIsWriteProtected()) //判断是否有写入保护
    {
        Serial.println("RTC was write protected, enabling writing now");
        Rtc.SetIsWriteProtected(false); //取消保护
    }

    if (!Rtc.GetIsRunning()) //判断是否运行
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true); //运行
    }
    Rtc.SetIsWriteProtected(true);//设置完之后写保护
}
void Loop_Time()
{
    RtcDateTime now_time = Rtc.GetDateTime();
    String Year = String(now_time.Year());
    String Month = String(now_time.Month());
    String Day = String(now_time.Day());
    String Hour = String(now_time.Hour());
    String Minute = String(now_time.Minute());
    String Second = String(now_time.Second());
    String DayOfWeek = String(now_time.DayOfWeek());

    String date = String(Year) + "-" + String(Month) + "-" + String(Day);
    String time = "  " + String(Hour) + ":" + String(Minute) + ":" + String(Second);
    Serial.println("---Date and Time---");
    Serial.println(date + time);
    Draw_DateTime(now_time.Year(), now_time.Month(), now_time.Day(), now_time.Hour(), now_time.Minute(), now_time.Second()); //OLED显示
                                                                                                          //一秒更新一次
}

#endif

// Serial.print("compiled time: "); //获取文件编译时间
// Serial.print(__DATE__);
// Serial.println(__TIME__);
// RtcDateTime compiled_time = RtcDateTime(__DATE__, __TIME__); //获取编译时间类
// RtcDateTime now_time = Rtc.GetDateTime();                    //获取运行时间类
// compiled_time += 30; //考虑上传时间
// Rtc.SetDateTime(compiled_time);
//决定写入哪个时间
// if (now_time < compiled_time)
// {
//     Serial.println("RTC is older than compile time!  (Updating DateTime)");
//     compiled_time += 30;            //考虑编译上传的时间
//     Rtc.SetDateTime(compiled_time); //将编译时间写入,进行初始化
// }
// else if (now_time > compiled_time)
// {
//     Serial.println("RTC is newer than compile time. (this is expected)");
// }
// else if (now_time == compiled_time)
// {
//     Serial.println("RTC is the same as compile time! (not expected but all is fine)");
// }