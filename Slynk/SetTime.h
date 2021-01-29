#ifndef _SETTIME_H //功能:向心知天气请求天气和温度
#define _SETTIME_H
#include "Arduino.h"
#include "ArduinoJson.h"
#include "HTTPRequest.h"
#include "OLED.h"
#include "ESP8266HTTPClient.h"
#include "Timer.h"
// uint16_t set_year = 2020; // "2020"
// uint8_t set_month = 1; // "06"月
// uint8_t set_day = 1;     // "22" 日，月份中的第几天，没有前导零，1 到 31

// uint8_t set_hour = 0;     // "10"小时，24 小时格式，没有前导零，0 到 23
// uint8_t set_minute = 0; // "23"分钟，有前导零的分钟数，00 到 59
// uint8_t set_second = 0; // "14"秒数，有前导零，00 到 59
// const char *set_week = "星期一";             // "星期一"

// HTTP请求用的URL
String URL = "http://hn216.api.yesapi.cn/?s=App.Common_Date.Curtime&uuid=68A3877B4F5A159FA0BFB6E1ABF7CEB0&app_key=0198B873405BCF8777003B5553080CB4&sign=744CBF2EBC927A8B4A9F2E5B17141118";
String today_date = "20200621";
String app_id = "gpgmvui7snbkrfvx";
String app_secret = "M0RmS0cveWxJb3AxbjlYWkxQNTFHZz09";
void ParseTime(String responsePayload)
{
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(25) + 420;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, responsePayload);
    JsonObject data = doc["data"];

    String date_time = data["datetime"].as<String>(); // "2020-06-22 10:23:14"
    const char *data_date = data["date"];             // "2020-06-22"

    set_year = data["year_Y"].as<uint16_t>();  // "2020"
    set_month = data["month_m"].as<uint8_t>(); // "06"月
    set_day = data["day_j"].as<uint8_t>();     // "22" 日，月份中的第几天，没有前导零，1 到 31

    set_hour = data["hour_G"].as<uint8_t>();     // "10"小时，24 小时格式，没有前导零，0 到 23
    set_minute = data["minute_i"].as<uint8_t>(); // "23"分钟，有前导零的分钟数，00 到 59
    set_second = data["second_s"].as<uint8_t>(); // "14"秒数，有前导零，00 到 59
    set_week = data["day_N_zh"].as<String>();                 // "星期一"

    //进行屏幕设置
    //公历时间设置
    Set_Timer();
    Serial.println(F("======lunnar Now======="));
    Serial.println(date_time);
    Serial.println(data_date);

    Serial.println(F("========================"));
}
void Set_Time()
{
    String responsePayload = HttpRequest(URL);
    ParseTime(responsePayload);
    delay(3000);
}

#endif
