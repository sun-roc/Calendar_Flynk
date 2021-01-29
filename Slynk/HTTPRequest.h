#ifndef _HTTPREQUEST_H //功能:HTTP请求函数
#define _HTTPREQUEST_H
//关联必要库
#include "Arduino.h"
//关联非必要库
#include "Time.h"
//项目主要依存库
#include "ArduinoJson.h"
#include "ESP8266HTTPClient.h"

//,void(*parseInfo)(Stirng)
// void HttpRequest(String URL,void (*ParseTime)( String ))
String HttpRequest(String URL)
{
    //创建 HTTPClient 对象
    HTTPClient httpClient;

    //配置请求地址。此处也可以不使用端口号和PATH而单纯的
    httpClient.begin(URL);
    Serial.print("URL: ");
    Serial.println(URL);

    //启动连接并发送HTTP请求
    int httpCode = httpClient.GET();
    //如果服务器响应OK则从服务器获取响应体信息并通过串口输出
    //如果服务器不响应OK则将服务器响应状态码通过串口输出
    if (httpCode == HTTP_CODE_OK)
    {
        String responsePayload = httpClient.getString();
        Serial.println("Server Response Payload: ");
        // Serial.println(responsePayload);
        //关闭ESP8266与服务器连接
        httpClient.end();
        return responsePayload;
    }
    else
    {
        Serial.println("Server Respose Code：");
        Serial.println(httpCode);
        //关闭ESP8266与服务器连接
        httpClient.end();
    }
}
#endif
