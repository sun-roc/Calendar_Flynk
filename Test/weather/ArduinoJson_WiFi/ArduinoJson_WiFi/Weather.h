#ifndef _WHEATHER_H //功能:向心知天气请求天气和温度
#define _WHEATHER_H
#include "Arduino.h"
// #include "Init.h"
//关联库
// #include "OLED.h"

const char *host = "api.seniverse.com";  // 将要连接的服务器地址
const int httpPort = 80;                 // 将要连接的服务器端口
String reqUserKey = "SpT8j7s6cl3_vRNyP"; // 私钥
String reqLocation = "Qingdao";          // 城市
String reqUnit = "c";                    // 摄氏/华氏
// 利用ArduinoJson库解析心知天气响应信息
void parseInfo(WiFiClient client)
{
    const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(6) + 230;
    DynamicJsonDocument doc(capacity);

    deserializeJson(doc, client);

    JsonObject results_0 = doc["results"][0];

    JsonObject results_0_now = results_0["now"];
    const char *results_0_now_text = results_0_now["text"];               // "Sunny"
    const char *results_0_now_code = results_0_now["code"];               // "0"
    const char *results_0_now_temperature = results_0_now["temperature"]; // "32"

    const char *results_0_last_update = results_0["last_update"]; // "2020-06-02T14:40:00+08:00"

    // 通过串口监视器显示以上信息
    String results_0_now_text_str = results_0_now["text"].as<String>();
    int results_0_now_code_int = results_0_now["code"].as<int>();
    int results_0_now_temperature_int = results_0_now["temperature"].as<int>();

    String results_0_last_update_str = results_0["last_update"].as<String>();

    Serial.println(F("======Weahter Now======="));
    Serial.print(F("Weather Now: "));
    Serial.print(results_0_now_text_str);
    Serial.print(F(" "));
    Serial.println(results_0_now_code_int);
    Serial.print(F("Temperature: "));
    Serial.println(results_0_now_temperature_int);
    Serial.print(F("Last Update: "));
    Serial.println(results_0_last_update_str);
    Serial.println(F("========================"));
}
// 向心知天气服务器服务器请求信息并对信息进行解析
void httpRequest(String reqRes)
{
    //blinker库中已经有client库,不需要在声明,直接调用他的就好,不然会冲突
    String httpRequest = String("GET ") + reqRes + " HTTP/1.1\r\n" +
                         "Host: " + host + "\r\n" +
                         "Connection: close\r\n\r\n";
    Serial.println("");
    Serial.print("Connecting to ");
    Serial.print(host);
    // 尝试连接服务器
    if (client.connect(host, httpPort))
    {
        Serial.println(" Success!");
        // 向服务器发送http请求信息
        client.print(httpRequest);
        Serial.println("Sending request: ");
        Serial.println(httpRequest);

        // 获取并显示服务器响应状态行
        String status_response = client.readStringUntil('\n');
        Serial.print("status_response: ");
        Serial.println(status_response);

        // 使用find跳过HTTP响应头
        if (client.find("\r\n\r\n"))
        {
            Serial.println("Found Header End. Start Parsing.");
        }
        // 利用ArduinoJson库解析心知天气响应信息
        parseInfo(client);
    }
    else
    {
        Serial.println(" connection failed!");
    }
    //断开客户端与服务器连接工作
    client.stop();
}
void Get_Weather()
{
    String reqRes = "/v3/weather/now.json?key=" + reqUserKey +
                    +"&location=" + reqLocation +
                    "&language=en&unit=" + reqUnit;
    httpRequest(reqRes);
}
#endif
