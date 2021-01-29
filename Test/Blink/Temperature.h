#ifndef _TEMP_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _TEMP_H
//关联必要库
#include "Arduino.h"
//关联非必要库
#include "OLED.h"
//项目主要依存库
#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY !)
#error Select ESP8266 board.
#endif
int Temp_loop = 0;
float get_humidity;
float get_temperature;
DHTesp dht; //定义温度传感器类

void Set_Temp() //初始化温度传感器函数
{
    dht.setup(10, DHTesp::DHT11); // 链接数据引脚到10/SD3
}

void Loop_Temp()
{
    //   Blinker.delay(dht.getMinimumSamplingPeriod());
    Temp_loop++;
    if (Temp_loop > 10)
    {
        Temp_loop = 0;
        get_humidity = dht.getHumidity();
        get_temperature = dht.getTemperature();
    }

    //串口输出状态
    Serial.println("---sensor---");
    Serial.print("DHT11: ");
    Serial.print(dht.getStatusString());
    Serial.print(" humi: ");
    Serial.print(get_humidity, 1);
    Serial.print(" temp: ");
    Serial.println(get_temperature, 1);
    //屏幕显示
    Draw_Temperature(get_temperature, get_humidity);
}

//其他函数方法
//   Serial.print(dht.toFahrenheit(temperature), 1);
//   Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
//   Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
#endif
