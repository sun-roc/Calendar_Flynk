#ifndef _GETWHEATHER_H //功能:向心知天气请求天气和温度
#define _GETWHEATHER_H
#include "Arduino.h"
#include "ArduinoJson.h"
#include "Blinker.h"
#include "U8g2lib.h" //中文字库加oled显示
// #include"HTTPRequest.h"
#include "ESP8266_Seniverse.h"//新知天气的库
// 心知天气HTTP请求所需信息
String reqUserKey = "SpT8j7s6cl3_vRNyP";   // 私钥
String reqLocation = "Qingdao";            // 城市
String reqUnit = "c";                      // 摄氏/华氏
#define SUN 0
#define CLOUD 1
#define RAIN 2
WeatherNow weatherNow;  // 建立WeatherNow对象用于获取心知天气信息
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

    u8g2.clearBuffer(); // 清除缓冲区记忆
    //绘制天气符号
    Draw_Weather_Symbol(0, 48, symbol);
    //绘制温度
    u8g2.setFont(u8g2_font_logisoso32_tf);
    u8g2.setCursor(48 + 3, 42);
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
        u8g2.print("真是一个大晴天");
        break;
    case CLOUD:
        u8g2.print("天气阴沉沉");
        break;
    case RAIN:
        u8g2.print("快快收衣服");
        break;
    }
    u8g2.sendBuffer(); // 将缓冲区信息发送
}

// 利用ArduinoJson库解析心知天气响应信息
//暂时用不到
//void parseInfo(WiFiClient client){
//  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2*JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(6) + 230;
//  DynamicJsonDocument doc(capacity);
//  
//  deserializeJson(doc, client);
//  
//  JsonObject results_0 = doc["results"][0];
//  
//  JsonObject results_0_now = results_0["now"];
//  const char* results_0_now_text = results_0_now["text"]; // "Sunny"
//  const char* results_0_now_code = results_0_now["code"]; // "0"
//  const char* results_0_now_temperature = results_0_now["temperature"]; // "32"
//  
//  const char* results_0_last_update = results_0["last_update"]; // "2020-06-02T14:40:00+08:00" 
//
//  // 通过串口监视器显示以上信息
//  String results_0_now_text_str = results_0_now["text"].as<String>(); 
//  int results_0_now_code_int = results_0_now["code"].as<int>(); 
//  int results_0_now_temperature_int = results_0_now["temperature"].as<int>(); 
//  
//  String results_0_last_update_str = results_0["last_update"].as<String>();   
//
//  Serial.println(F("======Weahter Now======="));
//  Serial.print(F("Weather Now: "));
//  Serial.print(results_0_now_text_str);
//  Serial.print(F(" "));
//  Serial.println(results_0_now_code_int);
//  Serial.print(F("Temperature lll: "));
//  Serial.println(results_0_now_temperature_int);
//  Serial.print(F("Last Update: "));
//  Serial.println(results_0_last_update_str);
//  Serial.println(F("========================"));
//}
// – 获取当前天气信息 (返回值类型：String): weatherNow.getWeatherText()
// – 获取当前天气信息 (返回值类型：int): weatherNow.getWeatherCode()
// – 获取当前温度信息 (返回值类型：int): weatherNow.getDegree()

// 程序第62行使用getLastUpdate()函数来获取心知天气公司的天气服务信息更新时间。
void Get_Wheather(){
  // // 建立心知天气API当前天气请求资源地址
  // String reqRes = "/v3/weather/now.json?key=" + reqUserKey +
  //                 + "&location=" + reqLocation + 
  //                 "&language=en&unit=" +reqUnit;
  //   // 向心知天气服务器服务器请求信息并对信息进行解析
  //   HttpRequest(reqRes,parseInfo);
  //   delay(3000);
  weatherNow.config(reqUserKey, reqLocation, reqUnit);
   if(weatherNow.update()){  // 更新天气信息
    
    Serial.println(F("======Weahter Info======"));
    Serial.print("Server Response: ");
    Serial.println(weatherNow.getServerCode()); // 获取服务器响应码
    Serial.print(F("Weather Now: "));
    Serial.print(weatherNow.getWeatherText());  // 获取当前天气（字符串格式）
    Serial.print(F(" "));
    Serial.println(weatherNow.getWeatherCode());// 获取当前天气（整数格式）
    Serial.print(F("Temperature: "));
    Serial.println(weatherNow.getDegree());     // 获取当前温度数值
    Serial.print(F("Last Update: "));
    Serial.println(weatherNow.getLastUpdate()); // 获取服务器更新天气信息时间
    Serial.println(F("========================"));
    Draw_Wheather( weatherNow.getWeatherCode(), weatherNow.getDegree());


  } else {    // 更新失败
    Serial.println("Update Fail...");   
    Serial.print("Server Response: ");          // 输出服务器响应状态码供用户查找问题
    Serial.println(weatherNow.getServerCode()); // 心知天气服务器错误代码说明可通过以下网址获取
    Draw_Wheather( 0,0);// https://docs.seniverse.com/api/start/error.html
  }                                            
  
  Blinker.delay(3000);
}





#endif
