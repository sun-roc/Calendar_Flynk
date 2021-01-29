
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "WiFiConnect.h" //依赖于以上两个库
#include "OLED.h"
#include "Timer.h"
#include "SetTime.h"
#include "Weather.h"
#include "Temperature.h"
#include "Fire.h"
#include "Lunar.h"
#include "ScanKey.h"
#include "Bell.h"
#include "BlynkPage.h"
#define HOMEPAGE 0
#define MENUPAGE 1
#define SETPAGE 2
#define CLOCKPAGE 3
#define AMPAGE 4
#define WEATHERPAGE 5
#define MUSICPAGE 6
#define BACK 7
#define BCLOCKPAGE 13
#define BSETPAGE 12
#define BAMPAGE 14
#define BMUSICPAGE 16

WidgetLCD lcd(V6);

int flag = HOMEPAGE;
int menu_flag = 1;

uint8_t clock_flag = 0; //时间数值的中间值
uint16_t set_flag = 0;   //

int clock_point = 1; //指向小时或分钟或秒
int set_point = 1;
int AM_point = 1;

int time_loop = 0;
int Weath_loop = 0;
int data_time_flag = 0;
BLYNK_WRITE(V0) //数值设置
{
    Blynk_Value = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.println("输入值");
    Serial.println(Blynk_Value);
}
// BLYNK_WRITE(V1)//下键
// {

// }
BLYNK_WRITE(V2) //确定键
{
    Serial.println("按下");
    Bell_flag = 0;
    switch (flag)
    {
    case BCLOCKPAGE:
        Blynk_clock_point++;
        if (Blynk_clock_point >= 4)
        {
            flag = HOMEPAGE;
            Blynk_Value = 1;
        }
        break;
    case BSETPAGE:
        Blynk_set_point++;
        if (Blynk_set_point >= 8)
        {
            flag = HOMEPAGE;
            Blynk_Value = 1;
        }
        break;
    case BMUSICPAGE:
        Blynk_music_num++;
        if (Blynk_music_num >= 2)
        {
            flag = HOMEPAGE;
            Blynk_Value = 1;
            Draw_Wait();
        }
    case BAMPAGE:
        Blynk_AM_num++;
        if (Blynk_AM_num >= 2)
        {
            flag = HOMEPAGE;
            Blynk_Value = 1;
            Draw_Wait();
        }
    default:
        break;
    }
}
BLYNK_READ(V3) //温度
{
    Blynk.virtualWrite(V3, get_temperature);
}
BLYNK_READ(V4) //湿度
{
    Blynk.virtualWrite(V4, get_humidity);
}

BLYNK_WRITE(V5) //菜单栏
{
    switch (param.asInt())
    {
    case 1: // 时钟
        Serial.println("时钟:");
        flag = HOMEPAGE;
        Home_Page();
        break;
    case 2: // 天气
        Serial.println("天气:");
        flag = WEATHERPAGE;
        Weath_Main(1);
        Weath_Page();
        break;
    case 3: // 闹钟设置
        Serial.println("闹钟:");
        flag = BCLOCKPAGE;
        Blynk_Clock_Page();
        break;
    case 4: // 时钟设置
        Serial.println("设置时间");
        flag = BSETPAGE;
        Blynk_Set_Page();
        break;
    case 5: // AM/PM设置
        Serial.println("设置AM");
        flag = BAMPAGE;
        AM_Page();
        break;
    case 6: // 音乐设置
        Serial.println("音乐");
        flag = BMUSICPAGE;
        Blynk_Music_Page();
        break;
    default:
        Serial.println("Unknown item selected");
    }
}

void setup()
{
    u8g2.begin();
    u8g2.enableUTF8Print();
    Draw_Open();
    WiFiconnect(); //串口初始化,链接WiFi
    Set_Time();
    Set_Temp();
}

void loop()
{
    Blynk.run();
    delay(50);
    if (flag != CLOCKPAGE && flag != SETPAGE && flag!= BCLOCKPAGE && flag != BSETPAGE)
    {
        Serial.println(flag);
        If_Bell();
    }

    switch (flag)
    {
    case HOMEPAGE:
        Home_Page();
        break;
    case WEATHERPAGE:
        Weath_Page();
        break;
    case MENUPAGE:
        Menu_Page();
        break;
    case SETPAGE:
        if(data_time_flag == 0){
            Set_Page0();
        }
        else if (data_time_flag == 1){
            Set_Page();
        }
        
        break;
    case CLOCKPAGE:
        Clock_Page();
        break;
    case AMPAGE:
        AM_Page();
        break;
    case MUSICPAGE:
        Music_Page();
        break;
    case BCLOCKPAGE:
        Blynk_Clock_Page();
        break;
    case BSETPAGE:
        Blynk_Set_Page();
        break;
    case BAMPAGE:
        Blynk_AM_Page();
        break;
    case BMUSICPAGE:
        Blynk_Music_Page();
        break;
    default:
        Home_Page();
        break;
    }
}

void Home_Page()
{
    time_loop++;
    switch (Scan())
    {
    case UP_BUTTON:
        flag = WEATHERPAGE;
        Draw_Wait();
        Weath_Main(1); //先显示出来
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
        Serial.println(Weath_loop);
        if (Weath_loop == 200)
        {
            Weath_Main(1);
        }
        if (Weath_loop == 400)
        {
            Weath_loop = 0;
            Weath_Main(2);
        }
        break;
    }
}
void Weath_Main(int Weath_Flag)
{
    u8g2.clearBuffer(); //清除开屏图片
    if (Weath_Flag == 1)
    {
        Get_Weather(); //获得天气
    }
    if (Weath_Flag == 2)
    {
        Get_Forcast();
    }
    u8g2.sendBuffer(); // 将缓冲区信息发送
}

void Menu_Page()
{
    delay(200);
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
        Serial.println("Flag 标志");
        Serial.println(SETPAGE);
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
void Set_Page0()
{
    Serial.print("年:");
    Serial.println(set_year);
    switch (set_point)
    {
    case 1:
        set_flag = set_year;
        break;
    case 2:
        set_flag = set_month;
        break;
    case 3:
        set_flag = set_day;
        break;
    default:
        set_flag = set_year;
        break;
    }
    switch (Scan())
    {
    case UP_BUTTON:
        if (set_point == 2)
        {
            if (set_flag <= 11)
            {
                set_flag++;
            }
        }
        else if(set_point == 3)
        {
            if (set_flag <= 30)
            {
                set_flag++;
            }
        }
        else if(set_point == 1)
        {
            set_flag++;
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
                set_flag = set_year;
                break;
            case 2:
                set_flag = set_month;
                break;
            case 3:
                set_flag = set_day;
                break;
            default:
                set_flag = set_year;
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
        set_year = set_flag;
        Set_Main0(1);
        break;
    case 2:
        set_month = set_flag;
        Set_Main0(2);
        break;
    case 3:
        set_day = set_flag;
        Set_Main0(3);
        break;
    case 4:
    {
        // Rtc.SetIsWriteProtected(false); //取消写保护
        // RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
        // Rtc.SetDateTime(my_time);
        // Rtc.SetIsWriteProtected(true); //写保护
        // flag = HOMEPAGE;
        data_time_flag = 1;
        set_point = 1;
        Draw_Wait();
        break;
    }
    default:
        set_year = set_flag;
        Set_Main0(1);
        break;
    }
}
void Set_Main0(int time_point)
{
    Draw_Set_Time0(time_point, set_year, set_month, set_day); //显示时间
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
        RtcDateTime my_time = RtcDateTime(set_year, set_month, set_day, set_hour, set_minute, set_second);
        Rtc.SetDateTime(my_time);
        Rtc.SetIsWriteProtected(true); //写保护
        flag = HOMEPAGE;
        set_point = 1;
        data_time_flag = 0;
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
void AM_Page()
{
    switch (Scan())
    {
    case UP_BUTTON:
        if (AM_flag == 2)
        {
            AM_flag--;
        }
        Draw_AM(AM_flag);
        break;
    case DOWN_BUTTON:
        if (AM_flag == 1)
        {
            AM_flag++;
        }
        Draw_AM(AM_flag);
        break;
    case MENUBOTTON:
        flag = HOMEPAGE;
        Draw_Wait();
        break;
    default:
        Draw_AM(AM_flag);
        break;
    }
}
void Music_Page()
{
    Serial.println(Music_flag);
    switch (Scan())
    {
    case UP_BUTTON:
        if (Music_flag >= 2)
        {
            Music_flag--;
        }
        Draw_Music(Music_flag);
        break;
    case DOWN_BUTTON:
        if (Music_flag <= 3)
        {
            Music_flag++;
        }
        Draw_Music(Music_flag);
        break;
    case MENUBOTTON:
        flag = HOMEPAGE;
        Draw_Wait();
        break;
    default:
        Draw_Music(Music_flag);
        break;
    }
}
