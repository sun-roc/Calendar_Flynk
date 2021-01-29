#ifndef _BLYNKPAGE_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _BLYNKPAGE_H
#include "Arduino.h"
#include "Timer.h"
int Blynk_Value = 1;
int Last_Value = 1;
int Blynk_clock_point = 1;
int Blynk_set_point = 1;
int Blynk_music_num = 0;
int Blynk_AM_num = 0;
void Blynk_Clock_Main(int clock_point)
{
    Blynk_Draw_Clock_Time(clock_point, clock_hour, clock_minute);
}
void Blynk_Clock_Page()
{

    if (Blynk_clock_point != Last_Value)
    {
        switch (Last_Value)
        {
        case 1:
            clock_hour = Blynk_Value;
            break;
        case 2:
            clock_minute = Blynk_Value;
            break;
        case 3:
            Blynk_clock_point = 1;
        default:
            break;
        }
    }
    Blynk_Clock_Main(Last_Value);
    Last_Value = Blynk_clock_point;
}
void Blynk_Set_Main(int time_point)
{
    Blynk_Draw_Set_Time(time_point, set_hour, set_minute, set_second,set_year,set_month,set_day); //显示时间
}
void Blynk_Set_Page()
{
    if (Blynk_set_point != Last_Value)
    {
        switch (Last_Value)
        {
        case 1:
        {
            set_hour = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        case 2:
        {
            set_minute = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }

        break;
        case 3:
        {
            set_second = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        case 4:
        {
            set_year = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        case 5:
        {
            set_month = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }

        break;
        case 6:
        {
            set_day = Blynk_Value;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        case 7:
        {
            Blynk_set_point = 1;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        default:
        {
            Blynk_set_point = 1;
            Rtc.SetIsWriteProtected(false); //取消写保护
            RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
            Rtc.SetDateTime(my_time);
            Rtc.SetIsWriteProtected(true); //写保护
        }
        break;
        }
    }
    Serial.println(Blynk_Value);
    Blynk_Set_Main(Last_Value);
    Last_Value = Blynk_set_point;
}
void Blynk_Music_Page()
{
    Music_flag = Blynk_Value;
    Draw_Music(Music_flag);
}
void Blynk_AM_Page()
{
    AM_flag = Blynk_Value;
    Draw_AM(AM_flag);
}
#endif