#ifndef _CC_H //.h文件中写,如果其他.c文件调用.h文件会先判断防止重复调用
#define _CC_H
#include "Arduino.h"

void cc_print(void){

    Serial.print("cc");
}

#endif