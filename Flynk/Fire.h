#ifndef _FIRE_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _FIRE_H
//关联必要库
#include "Arduino.h"
//关联非必要库
#include "OLED.h"
//项目主要依存库
#include <ThreeWire.h>
#include "RtcDS1302.h"
#define PORT A0

int fire_value = 0; //测量的模拟数值
bool fire;
void Loop_Fire()
{
        fire_value = analogRead(PORT); //如果fire value 等于零则代表有火焰
        Serial.println("---fire---");
        Serial.print("fire_value:");
        Serial.println(fire_value); //打印出来便于调试
        if (fire_value > 500)
        {
                fire = 0;
        }
        else
        {
                fire = 1;
                Blynk.email("火焰预警", "万年历传感器周围检测到火焰,请注意检查");
                Serial.print("邮件发送");
        }
        Draw_Fire(fire);
}

#endif
