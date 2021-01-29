#ifndef _LED_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _LED_H
#include "Arduino.h"

void led_print(void){
    Serial.begin(9600); 
    Serial.print("led");
}

#endif