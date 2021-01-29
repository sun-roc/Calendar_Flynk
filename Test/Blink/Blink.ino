#include "WiFiConnect.h"
#include "SetTime.h"
#include "GetWeather.h"
#include "OLED.h"
#include "Temperature.h"
#include "Fire.h"
#include "Timer.h"
#include "Lunar.h"
#include "ScanKey.h"
#include "SetLink.h"
#define HOMEPAGE 0
#define MENUPAGE 1
#define SETPAGE 2
#define CLOCKPAGE 3
#define AMPAGE 4
#define WEATHERPAGE 5
#define MUSICPAGE 6
#define BACK 7

#ifndef BLINKER_WIFI
#define BLINKER_WIFI
#endif
int flag = HOMEPAGE;
int menu_flag = 1;

uint8_t clock_flag = 0; //时间数值的中间值
uint8_t set_flag = 0;   //

int clock_point = 1; //指向小时或分钟或秒
int set_point = 1;
int AM_point = 1;

int time_loop = 0;
int Weath_loop = 0;
void setup()
{
    u8g2.begin();
    u8g2.enableUTF8Print();
    Draw_Open();
    WiFiconnect(); //串口初始化,链接WiFi
    Get_Time();
    Set_Temp();
    
}

void loop()
{
    Blinker.run();
    // Blinker.delay(50);
    // switch (flag)
    // {
    // case HOMEPAGE:
    //     Home_Page();
    //     break;
    // case WEATHERPAGE:
    //     Weath_Page();
    //     break;
    // case MENUPAGE:
    //     Menu_Page();
    //     break;
    // case SETPAGE:
    //     Set_Page();
    //     break;
    // case CLOCKPAGE:
    //     Clock_Page();
    //     break;
    // case AMPAGE:
    //     AM_Page();
    //     break;
    // default:
    //     Home_Page();
    //     break;
    // }
}

void Home_Page()
{
    time_loop++;
    switch (Scan())
    {
    case UP_BUTTON:
        flag = WEATHERPAGE;
        Draw_Wait();
        break;
    case MENUBOTTON:
        flag = MENUPAGE;
        Draw_Wait();
        break;
    default:
        if (time_loop = 5)
        {
            time_loop = 0;
            Home_Main();
        }

        break;
    }
}
void Home_Main()
{
    flag = HOMEPAGE;
    u8g2.clearBuffer(); //清除开屏图片
    //固定不变的
    Loop_Lunar(set_year, set_month, set_day);
    Loop_Time(); //循环输出时间和星期
    Loop_Temp(); //循环输出温度
    Loop_Fire(); //输出火焰检测
    Serial.println(" ");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}

void Weath_Page()
{
    switch (Scan())
    {
    case DOWN_BUTTON:
        flag = HOMEPAGE;
        break;
    default:
        Weath_loop++;
        if (Weath_loop > 40)
        {
            Weath_loop = 0;
            Weath_Main();
        }
        break;
    }
}
void Weath_Main()
{
    u8g2.clearBuffer(); //清除开屏图片
    Get_Wheather();     //获得天气
    u8g2.sendBuffer();  // 将缓冲区信息发送
}

void Menu_Page()
{
    Blinker.delay(200);
    switch (Scan())
    {
    case UP_BUTTON:
        if (menu_flag >= 2)
        {
            menu_flag--;
        }
        Menu_Main();
        break;
    case DOWN_BUTTON:
        if (menu_flag < 5)
        {
            menu_flag++;
        }
        Menu_Main();
        break;
    case MENUBOTTON:
        Menu_Change();
        break;
    default:
        Menu_Main();
        break;
    }
}
void Menu_Main()
{
    int point = menu_flag * 12;
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("闹钟设置");
    u8g2.setCursor(24, 24);
    u8g2.print("时间设置");
    u8g2.setCursor(24, 36);
    u8g2.print("格式设置");
    u8g2.setCursor(24, 48);
    u8g2.print("音乐设置");
    u8g2.setCursor(24, 60);
    u8g2.print("返回主页");
    u8g2.setCursor(72, point);
    u8g2.print("<");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Menu_Change()
{
    switch (menu_flag)
    {
    case 1:
        flag = CLOCKPAGE;
        menu_flag = 1;
        Draw_Wait();
        break;
    case 2:
        flag = SETPAGE;
        menu_flag = 1;
        Draw_Wait();
        break;
    case 3:
        flag = AMPAGE;
        menu_flag = 1;
        Draw_Wait();
        break;
    case 4:
        flag = MUSICPAGE;
        menu_flag = 1;
        Draw_Wait();
        break;
    case 5:
        flag = HOMEPAGE;
        menu_flag = 1;
        Draw_Wait();
        break;
    default:
        flag = MENUPAGE;
        Draw_Wait();
        break;
    }
}

void Clock_Page()
{
    switch (clock_point)
    {
    case 1:
        clock_flag = clock_hour;
        break;
    case 2:
        clock_flag = clock_minute;
        break;
    case 3:
        clock_flag = clock_second;
        break;
    default:
        clock_flag = clock_minute;
        break;
    }
    switch (Scan())
    {
    case UP_BUTTON:
        if (clock_point == 1)
        {
            if (clock_flag <= 23)
            {
                clock_flag++;
            }
        }
        else
        {
            if (clock_flag <= 59)
            {
                clock_flag++;
            }
        }
        break;
    case DOWN_BUTTON:
        if (clock_flag >= 1)
        {
            clock_flag--;
        }
        break;
    case MENUBOTTON:
        if (clock_point <= 3)
        {
            clock_point++;
            switch (clock_point)
            {
            case 1:
                clock_flag = clock_hour;
                break;
            case 2:
                clock_flag = clock_minute;
                break;
            case 3:
                clock_flag = clock_second;
                break;
            default:
                clock_flag = clock_hour;
                break;
            }
        }

        break;
    default:
        break;
    }

    switch (clock_point)
    {
    case 1:
        clock_hour = clock_flag;
        Clock_Main(1);
        break;
    case 2:
        clock_minute = clock_flag;
        Clock_Main(2);
        break;
    case 3:
        clock_second = clock_flag;
        Clock_Main(3);
        break;
    case 4:
        Serial.println("返回桌面");
        flag = HOMEPAGE;
        clock_point = 1; //返回初始状态
        Draw_Wait();
        break;
    default:
        clock_hour = clock_flag;
        Clock_Main(1);
        break;
    }
}
void Clock_Main(int time_point)
{
    Draw_Clock_Time(time_point, clock_hour, clock_minute, clock_second);
}
//设置显示屏时间
void Set_Page()
{
    switch (set_point)
    {
    case 1:
        set_flag = set_hour;
        break;
    case 2:
        set_flag = set_minute;
        break;
    case 3:
        set_flag = set_second;
        break;
    default:
        set_flag = set_hour;
        break;
    }
    switch (Scan())
    {
    case UP_BUTTON:
        if (set_point == 1)
        {
            if (set_flag <= 23)
            {
                set_flag++;
            }
        }
        else
        {
            if (set_flag <= 59)
            {
                set_flag++;
            }
        }
        break;
    case DOWN_BUTTON:
        if (set_flag >= 1)
        {
            set_flag--;
        }
        break;
    case MENUBOTTON:
        if (set_point <= 3)
        {
            set_point++;
            switch (set_point)
            {
            case 1:
                set_flag = set_hour;
                break;
            case 2:
                set_flag = set_minute;
                break;
            case 3:
                set_flag = set_second;
                break;
            default:
                set_flag = set_hour;
                break;
            }
        }
        break;
    default:
        break;
    }
    switch (set_point)
    {
    case 1:
        set_hour = set_flag;
        Set_Main(1);
        break;
    case 2:
        set_minute = set_flag;
        Set_Main(2);
        break;
    case 3:
        set_second = set_flag;
        Set_Main(3);
        break;
    case 4:
    {
        Rtc.SetIsWriteProtected(false); //取消写保护
        u8g2.print("主函数");
        u8g2.println(set_hour);
        RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
        Rtc.SetDateTime(my_time);
        Rtc.SetIsWriteProtected(true); //写保护
        Serial.println("返回桌面");
        flag = HOMEPAGE;
        set_point = 1;
        Draw_Wait();
        break;
    }
    default:
        set_hour = set_flag;
        Set_Main(1);
        break;
    }
}
void Set_Main(int time_point)
{
    Draw_Set_Time(time_point, set_hour, set_minute, set_second); //显示时间
}
void Music_Page()
{
}
void AM_Page()
{
    switch (Scan())
    {
    case UP_BUTTON:
        if (AM_point == 2)
        {
            AM_point--;
        }
        Draw_AM(AM_point);
        break;
    case DOWN_BUTTON:
        if (AM_point == 1)
        {
            AM_point++;
        }
        Draw_AM(AM_point);
        break;
    case MENUBOTTON:
        if (AM_point == 2)
        {
            AM_flag = 1;
        }
        else
        {
            AM_flag = 0;
        }
        flag = HOMEPAGE;
        Draw_Wait();
        break;
    default:
        Draw_AM(AM_point);
        break;
    }
}
