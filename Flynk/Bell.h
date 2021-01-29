#ifndef _BELL_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _BELL_H
#include"Arduino.h"
#include"Timer.h"
#include"OLED.h"
#include"ScanKey.h"
#define NOTE_D0 0
#define NOTE_D1 523
#define NOTE_D2 587
#define NOTE_D3 659
#define NOTE_D4 698
#define NOTE_D5 784
#define NOTE_D6 880
#define NOTE_D7 988

#define NOTE_DL1 261
#define NOTE_DL2 294
#define NOTE_DL3 329
#define NOTE_DL4 349
#define NOTE_DL5 392
#define NOTE_DL6 440
#define NOTE_DL7 493

#define NOTE_DH1 1046
#define NOTE_DH2 1175
#define NOTE_DH3 1318
#define NOTE_DH4 1397
#define NOTE_DH5 1568
#define NOTE_DH6 1760
#define NOTE_DH7 1976
//以上部分是定义是把每个音符和频率值对应起来，其实不用打这么多，但是都打上了，后面可以随意编写D调的各种歌，我这里用NOTE_D+数字表示音符，NOTE_DH+数字表示上面有点的那种音符，NOTE_DL+数字表示下面有点的那种音符。这样后面写起来比较好识别。
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//这部分是用英文对应了拍子，这样后面也比较好看
int HULUWA[] = 
{
  NOTE_DH1,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,
  NOTE_DH1,NOTE_D6,NOTE_D5,NOTE_DH1,NOTE_D6,NOTE_D0,NOTE_D6,
  NOTE_D6,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D6,
  NOTE_DH1,NOTE_D6,NOTE_D5,NOTE_DH1,NOTE_D6,NOTE_D0,
  
  NOTE_D1,NOTE_D1,NOTE_D3,
  NOTE_D1,NOTE_D1,NOTE_D3,NOTE_D0,
  NOTE_D6,NOTE_D6,NOTE_D6,NOTE_D5,NOTE_D6,
  NOTE_D5,NOTE_D1,NOTE_D3,NOTE_D0,
  NOTE_DH1,NOTE_D6,NOTE_D6,NOTE_D5,NOTE_D6,
  NOTE_D5,NOTE_D1,NOTE_D2,NOTE_D0,
  NOTE_D7,NOTE_D7,NOTE_D5,NOTE_D3,
  NOTE_D5,
  NOTE_DH1,NOTE_D0,NOTE_D6,NOTE_D6,NOTE_D5,NOTE_D5,NOTE_D6,NOTE_D6,
  NOTE_D0,NOTE_D5,NOTE_D1,NOTE_D3,NOTE_D0,
  NOTE_DH1,NOTE_D0,NOTE_D6,NOTE_D6,NOTE_D5,NOTE_D5,NOTE_D6,NOTE_D6,
  NOTE_D0,NOTE_D5,NOTE_D1,NOTE_D2,NOTE_D0,
  NOTE_D3,NOTE_D3,NOTE_D1,NOTE_DL6,
  NOTE_D1,
  NOTE_D3,NOTE_D5,NOTE_D6,NOTE_D6,
  NOTE_D3,NOTE_D5,NOTE_D6,NOTE_D6,
  NOTE_DH1,NOTE_D0,NOTE_D7,NOTE_D5,
  NOTE_D6,
};//这部分就是整首曲子的音符部分，用了一个序列定义为HULUWA，整数
float HULUWA_duration[]=
{
  1,1,0.5,0.5,1,
  0.5,0.5,0.5,0.5,1,0.5,0.5,
  0.5,1,0.5,1,0.5,0.5,
  0.5,0.5,0.5,0.5,1,1,
  
  1,1,1+1,
  0.5,1,1+0.5,1,
  1,1,0.5,0.5,1,
  0.5,1,1+0.5,1,
  0.5,0.5,0.5,0.5,1+1,
  0.5,1,1+0.5,1,
  1+1,0.5,0.5,1,
  1+1+1+1,
  0.5,0.5,0.5+0.25,0.25,0.5+0.25,0.25,0.5+0.25,0.25,
  0.5,1,0.5,1,1,
  0.5,0.5,0.5+0.25,0.25,0.5+0.25,0.25,0.5+0.25,0.25,
  0.5,1,0.5,1,1,
  1+1,0.5,0.5,1,
  1+1+1+1,
  0.5,1,0.5,1+1,
  0.5,1,0.5,1+1,
  1+1,0.5,0.5,1,
  1+1+1+1
};//这部分是整首曲子的接拍部分，也定义个序列HULUWA_duration，浮点（数组的个数和前面音符的个数是一样的，一一对应么）
int HUANLESONG[] = 
{
  NOTE_D3,NOTE_D3,NOTE_D4,NOTE_D5,NOTE_D5,NOTE_D4,NOTE_D3,NOTE_D2,
  NOTE_D1,NOTE_D1,NOTE_D2,NOTE_D3,NOTE_D3,NOTE_D2,NOTE_D2,
  NOTE_D0,
  NOTE_D3,NOTE_D3,NOTE_D4,NOTE_D5,NOTE_D5,NOTE_D4,NOTE_D3,NOTE_D2,
  NOTE_D1,NOTE_D1,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D1,NOTE_D1,
  NOTE_D0,
  NOTE_D2,NOTE_D2,NOTE_D3,NOTE_D1,NOTE_D2,NOTE_D3,NOTE_D4,NOTE_D3,NOTE_D1,
  NOTE_D2,NOTE_D3,NOTE_D4,NOTE_D3,NOTE_D2,NOTE_D1,NOTE_D2,NOTE_DL5,
  NOTE_D0,
  NOTE_D3,NOTE_D3,NOTE_D4,NOTE_D5,NOTE_D5,NOTE_D4,NOTE_D3,NOTE_D2,
  NOTE_D1,NOTE_D1,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D1,NOTE_D1,

};//这部分就是整首曲子的音符部分，用了一个序列定义为tune，整数

float HUANLESONG_duration[]=
{
  1,1,1,1,1,1,1,1,1,1,1,1,2,0.5,1,
  1,
  1,1,1,1,1,1,1,1,1,1,1,1,2,0.5,1.5,
  1,
  1,1,1,1,1,0.5,0.5,1,1,1,0.5,0.5,1,1,1,1,1.5,
  1,
  1,1,1,1,1,1,1,1,1,1,1,1,2,0.5,1.5,

};
int PIPAYU[] =
{
  NOTE_DL6,NOTE_D3,NOTE_DH1,NOTE_DL6,NOTE_D2,NOTE_D7,
  NOTE_DL6,NOTE_D3,NOTE_DH1,NOTE_DL6,NOTE_D2,NOTE_D7,
  NOTE_D1,NOTE_DL7,
  NOTE_D1,NOTE_DL7,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,//1
  
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D5,NOTE_D3,
  NOTE_D2,NOTE_D3,NOTE_D1,NOTE_DL7,NOTE_D1,NOTE_DL7,NOTE_DL5,
  NOTE_DL6,NOTE_D3,NOTE_D5,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,//2
  
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D5,NOTE_D3,
  NOTE_D2,NOTE_D3,NOTE_D1,NOTE_DL7,NOTE_D1,NOTE_DL7,NOTE_DL5,
  NOTE_DL6,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D3,NOTE_D5,//3
  
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_DH2,NOTE_D5,
  NOTE_DH2,NOTE_DH3,NOTE_DH3,NOTE_D0,NOTE_D5,NOTE_DH1,NOTE_DH3,
  NOTE_DH2,NOTE_DH3,NOTE_D6,NOTE_DH2,NOTE_DH3,NOTE_D6,
  NOTE_D4,NOTE_D5,NOTE_D6,NOTE_DH1,NOTE_D7,NOTE_D6,NOTE_D3,NOTE_DH3,
  NOTE_DH2,NOTE_DH3,NOTE_D6,NOTE_DH2,NOTE_DH3,NOTE_D6,//4
  
  NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_DH2,NOTE_D7,NOTE_D5,NOTE_D6,
  NOTE_DL7,
  NOTE_D1,NOTE_DL7,
  NOTE_DH3,NOTE_DH3,NOTE_DH2,
  NOTE_DH3,NOTE_DH3,NOTE_DH6,
  NOTE_DH2,NOTE_DH1,NOTE_D7,NOTE_D5,
  NOTE_D6,NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_DH2,//5
  
  NOTE_DH3,NOTE_DH3,NOTE_DH2,
  NOTE_DH3,NOTE_DH3,NOTE_DH6,
  NOTE_DH2,NOTE_DH1,NOTE_D7,NOTE_D5,
  NOTE_D6,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D3,NOTE_D5,//6
  
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_DH2,NOTE_D5,
  NOTE_DH2,NOTE_DH3,NOTE_DH3,NOTE_D0,NOTE_D5,NOTE_DH1,NOTE_DH3,
  NOTE_DH2,NOTE_DH3,NOTE_D6,NOTE_DH2,NOTE_DH3,NOTE_D6,
  NOTE_D4,NOTE_D5,NOTE_D6,NOTE_DH1,NOTE_D7,NOTE_D6,NOTE_D3,NOTE_DH3,
  NOTE_DH2,NOTE_DH3,NOTE_D6,NOTE_DH2,NOTE_DH3,NOTE_D6,//7
  
  NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_DH2,NOTE_D7,NOTE_D5,NOTE_D6,
  NOTE_DH3,NOTE_DH2,
  NOTE_DH3,NOTE_D3,NOTE_D5,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D5,NOTE_D3,//8
  
  NOTE_D2,NOTE_D3,NOTE_D1,NOTE_DL7,NOTE_D1,NOTE_DL7,NOTE_DL5,
  NOTE_DL6,NOTE_D3,NOTE_D5,
  NOTE_D6,NOTE_D5,NOTE_D6,NOTE_D0,NOTE_D5,NOTE_D6,NOTE_D7,NOTE_D6,NOTE_D5,
  NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D2,NOTE_D3,NOTE_D5,NOTE_D3,//9
  
  NOTE_D2,NOTE_D3,NOTE_D1,NOTE_DL7,NOTE_D1,NOTE_DL7,NOTE_DL5,
  NOTE_DL6,
  NOTE_DL6,NOTE_D3,NOTE_DH1,NOTE_DL6,NOTE_D2,NOTE_D7,NOTE_D2,NOTE_D3,NOTE_D5,NOTE_D3,
  NOTE_D2,NOTE_D3,NOTE_D1,NOTE_DL7,NOTE_D1,NOTE_DL7,NOTE_DL5,
  NOTE_DL6,//10
};//这部分就是整首曲子的音符部分，用了一个序列定义为tune，整数

float PIPAYU_duration[]=
{
  0.125,0.125,0.75,0.125,0.125,0.75,
  0.125,0.125,0.75,0.125,0.125,0.75,
  1,1,
  1,1,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,//1
  
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  1.5,0.25,0.25,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,//2
  
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  2,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.25,0.25,//3
  
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,0.5,0.25,0.25,0.25,0.25,
  0.375,0.125,0.5,0.375,0.125,0.5,
  0.125,0.125,0.125,0.125,0.25,0.25,0.75,0.25,
  0.375,0.125,0.5,0.375,0.125,0.5,//4
  
  0.125,0.125,0.125,0.125,0.25,0.25,1,
  2,
  1,1,
  1,0.5,0.5,
  1,0.5,0.5,
  0.5,0.5,0.5,0.5,
  1,0.25,0.25,0.25,0.25,//5
  
  1,0.5,0.5,
  1,0.5,0.5,
  0.5,0.5,0.5,0.5,
  2,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.25,0.25,//6
  
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,0.5,0.25,0.25,0.25,0.25,
  0.375,0.125,0.5,0.375,0.125,0.5,
  0.125,0.125,0.125,0.125,0.25,0.25,0.75,0.25,
  0.375,0.125,0.5,0.375,0.125,0.5,//7
  
  0.125,0.125,0.125,0.125,0.25,0.25,1,
  1,1,
  1.5,0.25,0.25,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.125,0.125,0.125,0.125,//8
  
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  1.5,0.25,0.25,
  0.375,0.125,0.75,0.125,0.125,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.125,0.125,0.125,0.125,//9
  
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  2,
  0.125,0.125,0.75,0.125,0.125,0.25,0.125,0.125,0.125,0.125,
  0.375,0.125,1,0.125,0.125,0.125,0.125,
  2,//10
};
int TIANKONG[] =  
{  
 NOTE_D0,NOTE_D0,NOTE_D0,NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D3,NOTE_D3,
 NOTE_D6,NOTE_D5,NOTE_D6,NOTE_DH1,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D3,NOTE_D4,NOTE_D3,NOTE_D4,NOTE_DH1,
 NOTE_D3,NOTE_D3,NOTE_D0,NOTE_DH1,NOTE_DH1,NOTE_DH1,NOTE_D7,NOTE_D4,NOTE_D4,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D0,NOTE_D6,NOTE_D7,
 NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D3,NOTE_D3,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_DH1,
 NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D2,NOTE_D3,NOTE_D4,NOTE_DH1,NOTE_D7,NOTE_D7,NOTE_DH1,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_DH3,NOTE_DH1,NOTE_DH1,NOTE_DH1,
 NOTE_DH1,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D7,NOTE_D5,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_DH1,NOTE_DH2,NOTE_DH3,NOTE_DH2,NOTE_DH3,NOTE_DH5,
 NOTE_DH2,NOTE_DH2,NOTE_DH2,NOTE_D5,NOTE_D5,NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,
 NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_D7,NOTE_DH2,NOTE_DH2,NOTE_DH1,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_DH4,NOTE_DH3,NOTE_DH2,NOTE_DH1,
 NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH6,NOTE_DH6,NOTE_DH5,NOTE_DH5,NOTE_DH3,NOTE_DH2,NOTE_DH1,NOTE_DH1,NOTE_D0,NOTE_DH1,
 NOTE_DH2,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_DH5,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH6,NOTE_DH6,NOTE_DH5,NOTE_DH5,
 NOTE_DH3,NOTE_DH2,NOTE_DH1,NOTE_DH1,NOTE_D0,NOTE_DH1,NOTE_DH2,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_D7
};//这部分就是整首曲子的音符部分，用了一个序列定义为tune，整数

float TIANKONG_duration[]= 
{  
  1,1,1,0.5,0.5,     1+0.5,0.5,1,1,     1,1,1,0.5,0.5,
  1+0.5,0.5,1,1,     1,1,1,1,          1+0.5,0.5,1,1, 
  1,1,0.5,0.5,0.5,0.5,    1+0.5,0.5,1,1,     1,1,1,0.5,0.5,
  1+0.5,0.5,1,1,    1,1,1,0.5,0.5,     1+0.5,0.5,1,1,
  1,1,1,0.5,0.5,    1,0.5,0.25,0.25,0.25,0.5,    0.5,0.5,0.5,0.25,0.5,1,
  0.5,0.5,0.5,0.5,1,1,    1,1,1,0.5,0.5,    1+0.5,0.5,1,1,
  1,1,1,0.5,0.5,    1.5,0.5,1,1,    1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,    1.5,0.25,0.5,1,    1,1,1,1,
  1,1,1,1,    1,1,1,1,    0.5,0.5,1,1,0.5,0.5,
  1,0.5,0.5,1,1,    1,1,1,1,    1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,    1,0.5,0.25,0.5,1,    1,1,1,0.5,0.5
};
int length;//这里定义一个变量，后面用来表示共有多少个音符
int tonePin=3;//蜂鸣器的pin
int Music_flag = 1;
int Bell_flag = 1;//0时闹钟不响,1时闹钟响
int Stop_Bell = 0;
int LED_loop = 0;
void Set_Bell(){
  pinMode(tonePin,OUTPUT);//设置蜂鸣器的pin为输出模式
}
void Run_Music( int tones[],float duration[])
{
    length = sizeof(tones);//这里用了一个sizeof函数，可以查出tone序列里有多少个音符
    Serial.println(length);
   
}
void Run_Bell(){
  switch (Music_flag)
  {
  case 3:
          length = sizeof(HULUWA)/sizeof(HULUWA[0]);//这里用了一个sizeof函数，可以查出tone序列里有多少个音符
          for(int x=0;x<length;x++)//循环音符的次数
          {
            Blynk.run();
            if(Scan()!= NULL_BUTTON){
              Bell_flag = 0;
            }
            tone(tonePin,HULUWA[x]);//此函数依次播放HULUWA序列里的数组，即每个音符
            delay(400*HULUWA_duration[x]);//每个音符持续的时间，即节拍duration，400是调整时间的越大，曲子速度越慢
                        if(Bell_flag == 0){
              break;
            }
          }
    
    break;
  case 2:
            length = sizeof(HUANLESONG)/sizeof(HUANLESONG[0]);
            for(int x=0;x<length;x++)
            {
              Blynk.run();
            if(Scan()!= NULL_BUTTON){
              Bell_flag = 0;
            }
              tone(tonePin,HUANLESONG[x]);
              delay(400*HUANLESONG_duration[x]);
                          if(Bell_flag == 0){
              break;
            }
            }
      
    break;
  case 4:
          length = sizeof(PIPAYU)/sizeof(PIPAYU[0]);
          for(int x=0;x<length;x++)
          {
            Blynk.run();
            if(Scan()!= NULL_BUTTON){
              Bell_flag = 0;
            }
            tone(tonePin,PIPAYU[x]);
            delay(1150*PIPAYU_duration[x]);
            if(Bell_flag == 0){
              break;
            }
          }
    
    break;
  case 1:
          length = sizeof(TIANKONG)/sizeof(TIANKONG[0]);
          for(int x=0;x<length;x++)
          {
            Blynk.run();
            if(Scan()!= NULL_BUTTON){
              Bell_flag = 0;
            }
            LED_loop++;
            if(LED_loop == 2){
              pinMode(10,OUTPUT);
              digitalWrite(10,HIGH);
              LED_loop = 0;
            }else{
                            pinMode(10,OUTPUT);
              digitalWrite(10,LOW);
            }
            tone(tonePin,TIANKONG[x]);
            delay(600*TIANKONG_duration[x]);
            if(Bell_flag == 0){
              break;
              noTone(tonePin);//停止当前音符
            }
          }
    break;
  default:
    break;
  }
   noTone(tonePin);//停止当前音符
}
void If_Bell(){
    RtcDateTime now_time = Rtc.GetDateTime();
    if(now_time.Hour()==clock_hour && now_time.Minute()==clock_minute){
        if(Stop_Bell == 0){
          
              Draw_Bell(clock_hour,clock_minute);
            Run_Bell();
            Stop_Bell = 1;
            }
    }else{
      Bell_flag = 1;
      Stop_Bell =0;
    }
}
#endif