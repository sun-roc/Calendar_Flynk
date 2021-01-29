#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

const char *ssid = "ChinaNet-ChNS";    // 连接WiFi名（此处使用taichi-maker为示例）
                                       // 请将您需要连接的WiFi名填入引号中
const char *password = "s18953201606"; // 连接WiFi密码（此处使用12345678为示例）
                                       // 请将您需要连接的WiFi密码填入引号中

const char *host = "api.djapi.cn"; // 将要连接的服务器地址
const int httpPort = 80;           // 将要连接的服务器端口
// 心知天气HTTP请求所需信息
String reqToken = "5906fddcc7591fe7d3ce5d5403def99a";
String reqData = "20200626";

void setup()
{
  Serial.begin(9600);
  Serial.println("");

  // 连接WiFi
  connectWiFi();
  // 建立心知天气API当前天气请求资源地址
  String reqRes = "/wannianli/get?date=" + reqData +
                  +"&token=" + reqToken +
                  "&cn_to_unicode=0";

  // 向心知天气服务器服务器请求信息并对信息进行解析
  httpRequest(reqRes);
}

void loop()
{

  delay(3000);
}

// 向心知天气服务器服务器请求信息并对信息进行解析
void httpRequest(String reqRes)
{
  WiFiClient client;

  // 建立http请求信息
  String httpRequest = String("GET ") + reqRes + " HTTP/1.1\r\n" +
                       "Host: " + host + "\r\n" +
                       "Connection: close\r\n\r\n";
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.print(host);

  // 尝试连接服务器
  if (client.connect(host, 80))
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

// 连接WiFi
void connectWiFi()
{
  WiFi.begin(ssid, password);     // 启动网络连接
  Serial.print("Connecting to "); // 串口监视器输出网络连接信息
  Serial.print(ssid);
  Serial.println(" ..."); // 告知用户NodeMCU正在尝试WiFi连接

  int i = 0; // 这一段程序语句用于检查WiFi是否连接成功
  while (WiFi.status() != WL_CONNECTED)
  {              // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。
    delay(1000); // 如果WiFi连接成功则返回值为WL_CONNECTED
    Serial.print(i++);
    Serial.print(' ');                       // 此处通过While循环让NodeMCU每隔一秒钟检查一次WiFi.status()函数返回值
  }                                          // 同时NodeMCU将通过串口监视器输出连接时长读秒。
                                             // 这个读秒是通过变量i每隔一秒自加1来实现的。
  Serial.println("");                        // WiFi连接成功后
  Serial.println("Connection established!"); // NodeMCU将通过串口监视器输出"连接成功"信息。
  Serial.print("IP address:    ");           // 同时还将输出NodeMCU的IP地址。这一功能是通过调用
  Serial.println(WiFi.localIP());            // WiFi.localIP()函数来实现的。该函数的返回值即NodeMCU的IP地址。
}

// 利用ArduinoJson库解析心知天气响应信息
void parseInfo(WiFiClient client)
{
  const size_t capacity = JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(13) + 240;
  DynamicJsonDocument doc(capacity);

  const char *json = "{\"ApiName\":\"wannianli\",\"ErrorCode\":0,\"ErrorReason\":\"no\",\"Result\":{\"gongli\":20200626,\"week\":\"星期五\",\"nongli\":\"庚子年五月初六(2020)\",\"xingzuo\":\"巨蟹座\",\"nianci\":\"庚子年壬午月庚子日\",\"do\":\"诸事不宜\",\"nodo\":\"诸事不宜\",\"shengxiao\":\"鼠\",\"jieqi\":\"夏至后\",\"runnian\":\"是（润4月）\",\"festivals_nl\":\"\",\"festivals_gl\":\"\",\"to_today\":\"今天\"}}";

  deserializeJson(doc, json);

  const char *ApiName = doc["ApiName"];         // "wannianli"
  int ErrorCode = doc["ErrorCode"];             // 0
  const char *ErrorReason = doc["ErrorReason"]; // "no"

  JsonObject Result = doc["Result"];
  long Result_gongli = Result["gongli"];                    // 20200626
  const char *Result_week = Result["week"];                 // "星期五"
  const char *Result_nongli = Result["nongli"];             // "庚子年五月初六(2020)"
  const char *Result_xingzuo = Result["xingzuo"];           // "巨蟹座"
  const char *Result_nianci = Result["nianci"];             // "庚子年壬午月庚子日"
  const char *Result_do = Result["do"];                     // "诸事不宜"
  const char *Result_nodo = Result["nodo"];                 // "诸事不宜"
  const char *Result_shengxiao = Result["shengxiao"];       // "鼠"
  const char *Result_jieqi = Result["jieqi"];               // "夏至后"
  const char *Result_runnian = Result["runnian"];           // "是（润4月）"
  const char *Result_festivals_nl = Result["festivals_nl"]; // ""
  const char *Result_festivals_gl = Result["festivals_gl"]; // ""
  const char *Result_to_today = Result["to_today"];         // "今天"
  String a = doc.as<String>();
  Serial.println(a);
}
