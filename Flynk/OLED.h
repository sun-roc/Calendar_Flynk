#ifndef _OLED_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _OLED_H
//关联必要库
#include "Arduino.h"
//关联非必要库
#include "Character.h"
//项目主要依存库
#include "U8g2lib.h" //中文字库加oled显示

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
//配置OLED屏幕信息
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/D2, /* data=*/D1, /* reset=*/U8X8_PIN_NONE);

#define SUN 0
#define CLOUD 1
#define RAIN 2

int AM_flag = 1;
/**
 * 绘制字体字集里面定义的符号
 * @param x 左下角的x坐标
 * @param y 左下角的y坐标
 * @param encoding 字符的unicode值 encoding values, see: https://github.com/olikraus/u8g2/wiki/fntgrpiconic
 * @Note 关联方法 setFont 
 */
void Draw_Weather_Symbol(u8g2_uint_t x, u8g2_uint_t y, int symbol)
{

    switch (symbol)
    {
    case SUN:
        u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
        u8g2.drawGlyph(x, y, 69);
        break;
    case CLOUD:
        u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
        u8g2.drawGlyph(x, y, 64);
        break;
    case RAIN:
        u8g2.setFont(u8g2_font_open_iconic_weather_4x_t);
        u8g2.drawGlyph(x, y, 67);
        break;
    }
}
void Today_Weather(int Hight, int low, int humidityw, int rainw)
{
    u8g2.setCursor(0, 48);
    u8g2.print("最高:");
    u8g2.print(Hight);
    u8g2.print("°最低:");
    u8g2.print(low);
    u8g2.print("°湿度:");
    u8g2.print(humidityw);
    u8g2.setCursor(60, 62);
    u8g2.print(" 降雨概率:");
    u8g2.print(rainw);
    u8g2.print("%");
}
void Draw_Wheather(int symbol, int degree)
{
    //根据天气代码确定要显示的图标
    if (symbol <= 3)
    {
        symbol = SUN;
    }
    else if (symbol <= 9)
    {
        symbol = CLOUD;
    }
    else if (symbol <= 25)
    {
        symbol = RAIN;
    }
    else
    {
        symbol = SUN;
    }

    //绘制天气符号
    Draw_Weather_Symbol(0, 36, symbol);
    //绘制温度
    u8g2.setFont(u8g2_font_logisoso20_tf);
    u8g2.setCursor(32 + 8, 30);
    u8g2.print(degree);
    if (degree < 0)
    {
        u8g2.print("°"); // 需要 enableUTF8Print()
    }
    else
    {
        u8g2.print("°C"); // 需要 enableUTF8Print()
    }
    //绘制天气描述
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 62);
    switch (symbol)
    {
    case SUN:
        u8g2.print("一个大晴天");
        break;
    case CLOUD:
        u8g2.print("天气阴沉沉");
        break;
    case RAIN:
        u8g2.print("快快收衣服");
        break;
    }
}

void Draw_Tomorrow_Weather(int hi, int low, int rainw, int humi, int scale)
{

    u8g2.clearBuffer(); // 清除缓冲区记忆
    u8g2.setCursor(24, 12);
    u8g2.print("明天天气");
    u8g2.setCursor(0, 24);
    u8g2.print("最高: ");
    u8g2.print(hi);
    u8g2.print("°C");
    u8g2.print(" 最低: ");
    u8g2.print(low);
    u8g2.print("°C");
    u8g2.setCursor(0, 36);
    u8g2.print("降雨概率: ");
    u8g2.print(rainw);
    u8g2.print("% ");
    u8g2.print("湿度: ");
    u8g2.print(humi);
    u8g2.print("%");
    u8g2.setCursor(0, 48);
    u8g2.print("风力等级: ");
    u8g2.print(scale);
    u8g2.print(" 级");

    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_DateTime(uint16_t Year, uint8_t Month, uint8_t Day, uint8_t Hour, uint8_t Minute, uint8_t Second)
{
    String out_Year = String(Year);
    String out_Month = String(Month);
    String out_Day = String(Day);
    String out_Hour = String(Hour);
    String out_Minute = String(Minute);
    String out_Second = String(Second);
    bool AMPM = 0;
    if (AM_flag == 2)
    {
        if (Hour >= 13)
        {
            out_Hour = String(Hour - 12);
            AMPM = 1;
            Hour = Hour - 12;
        }
    }
    //补零用
    if (Month < 10)
    {
        out_Month = "0" + out_Month;
    }
    if (Day < 10)
    {
        out_Day = "0" + out_Day;
    }
    if (Hour < 10)
    {
        out_Hour = "0" + out_Hour;
    }
    if (Minute < 10)
    {
        out_Minute = "0" + out_Minute;
    }
    if (Second < 10)
    {
        out_Second = "0" + out_Second;
    }

    String date = out_Year + "-" + out_Month + "-" + out_Day + " ";
    if (AM_flag == 2)
    {
        if (AMPM)
        {
            date = date + "P: ";
        }
        else
        {
            date = date + "A: ";
        }
    }
    String time = out_Hour + ":" + out_Minute + ":" + out_Second;
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 24);
    u8g2.print(date + time);
}

void Draw_Temperature(float temperature, float humidity)
{
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 36);
    u8g2.print("温度:");
    u8g2.print(temperature, 1);
    u8g2.print("°C 湿度:");
    u8g2.print(humidity, 1);
    u8g2.print("%");
}
/**
 * 绘制图像
 * @param x 左上角坐标x
 * @param y 左上角坐标y
 * @param w 图形宽度
 * @param h 图形高度
 * @param bitmap 图形内容
 * @Note 关联方法 setBitmapMode
 */
void Draw_Open()
{
    u8g2.clearBuffer();    // 清除缓冲区记忆
    u8g2.setBitmapMode(1); //0 绘制背景颜色，不透明，默认是该值, 1 不绘制背景颜色，透明
    u8g2.drawXBMP(0, 0, 129, 45, SDU_129X45);
    u8g2.sendBuffer();
}
void Draw_Lunar(int year, int month, int day, unsigned char solar, String set_week)
{
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 12);
    int tian_gan = year % 10;
    u8g2.print(TianGan[tian_gan]);
    int di_zhi = year % 12;
    u8g2.print(DiZhi[di_zhi]);
    u8g2.print("年");
    u8g2.print(ChMonth[month]);
    u8g2.print("月");
    u8g2.print(ChDay[day]);
    u8g2.print(" ");
    if (solar != 0)
    {
        u8g2.print(SolarTerm[solar]);
    }
    else
    {
        u8g2.print("--");
    }
    u8g2.setCursor(92, 48);
    u8g2.print(set_week);
}
void Draw_Fire(bool fire)
{
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 48);
    u8g2.print("火警风险: ");
    if (fire)
    {
        u8g2.print("高!!");
    }
    else
    {
        u8g2.print("无");
    }
}

void Draw_Clock_Time(int time_point, uint8_t clock_hour, uint8_t clock_minute, uint8_t clock_second)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("设置闹钟时间");
    u8g2.setCursor(24, 24);
    if (clock_hour < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_hour);
    u8g2.print("点");
    if (clock_minute < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_minute);
    u8g2.print("分");
    if (clock_second < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_second);
    u8g2.print("秒");
    u8g2.setCursor(time_point * 24, 36);
    u8g2.print("^^");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Blynk_Draw_Clock_Time(int time_point, uint8_t clock_hour, uint8_t clock_minute)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("设置闹钟时间");
    u8g2.setCursor(24, 24);
    if (clock_hour < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_hour);
    u8g2.print("点");
    if (clock_minute < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_minute);
    u8g2.print("分");
    if (time_point != 3)
    {
        u8g2.setCursor(time_point * 24, 36);
        u8g2.print("^^");
    }
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_Set_Time0(int time_point, uint16_t set_year, uint8_t set_month, uint8_t set_day)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("设置年月日");
    u8g2.setCursor(24, 24);
    // if (set_year < 10)
    // {
    //     u8g2.print("0");
    // }
    u8g2.print(String(set_year));
    u8g2.print("年");
    if (set_month < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_month);
    u8g2.print("月");
    if (set_day < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_day);
    u8g2.print("日");
    u8g2.setCursor(24 + time_point * 24, 36);
    u8g2.print("^^");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_Set_Time(int time_point, uint8_t set_hour, uint8_t set_minute, uint8_t set_second)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("设置时钟时间");
    u8g2.setCursor(24, 24);
    if (set_hour < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_hour);
    u8g2.print("点");
    if (set_minute < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_minute);
    u8g2.print("分");
    if (set_second < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_second);
    u8g2.print("秒");
    u8g2.setCursor(time_point * 24, 36);
    u8g2.print("^^");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Blynk_Draw_Set_Time(int time_point, uint8_t set_hour, uint8_t set_minute, uint8_t set_second, uint16_t set_year, uint8_t set_month, uint8_t set_day)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("设置时钟时间");
    u8g2.setCursor(24, 24);
    if (set_hour < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_hour);
    u8g2.print("点");
    if (set_minute < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_minute);
    u8g2.print("分");
    if (set_second < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_second);
    u8g2.print("秒");
    if (time_point < 4)
    {
        Serial.println(time_point);
        u8g2.setCursor(time_point * 24, 36);
        u8g2.print("^^");
    }
    else if (time_point < 7)
    {
        Serial.println(time_point);
        u8g2.setCursor(24 + (time_point - 3) * 24, 60);
        u8g2.print("^^");
    }
    else
    {
    }
    //

    u8g2.setCursor(24, 48);
    u8g2.print(String(set_year));
    u8g2.print("年");
    if (set_month < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_month);
    u8g2.print("月");
    if (set_day < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(set_day);
    u8g2.print("日");
    // u8g2.setCursor(24 + time_point * 24, 60);
    // u8g2.print("^^");

    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_AM(int AM_point)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 12);
    u8g2.print("24小时");
    u8g2.setCursor(0, 24);
    u8g2.print("12小时");
    u8g2.setCursor(36, 12 * AM_point);
    u8g2.print("<");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_Wait()
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("........");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_Bell(uint8_t clock_hour, uint8_t clock_minute)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(24, 12);
    u8g2.print("闹钟!!!!");
    u8g2.setCursor(24, 24);
    if (clock_hour < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_hour);
    u8g2.print("点");
    if (clock_minute < 10)
    {
        u8g2.print("0");
    }
    u8g2.print(clock_minute);
    u8g2.print("分");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
void Draw_Music(int Music_flag)
{
    u8g2.clearBuffer(); //清除开屏图片
    u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
    u8g2.setCursor(0, 12);
    u8g2.print("1-天空之城");
    u8g2.setCursor(0, 24);
    u8g2.print("2-欢乐颂");
    u8g2.setCursor(0, 36);
    u8g2.print("3-葫芦娃");
    u8g2.setCursor(0, 48);
    u8g2.print("4-琵琶语");
    u8g2.setCursor(64, 12 * Music_flag);
    u8g2.print("<");
    u8g2.sendBuffer(); // 将缓冲区信息发送
}
#endif