#ifndef _KEY_H
#define _KEY_H
//关联必要库
#include "Arduino.h"
#include "OLED.h"
#define NULL_BUTTON 0
#define UP_BUTTON 1
#define DOWN_BUTTON 2
#define MENUBOTTON 3

bool DO = 0; //表示被按下
bool NO = 1;
int return_value = 0;
int Scan()
{
    pinMode(D6, INPUT_PULLUP);//上键
    pinMode(D7, INPUT_PULLUP);//下键
    pinMode(D5, INPUT_PULLUP);//菜单键
    bool UP = digitalRead(D6);
    bool DOWN = digitalRead(D7);
    bool MENU = digitalRead(D5);
    // Serial.print("UP and DOWN:");
    // Serial.print(UP);
    // Serial.println(DOWN);
    bool do_flag = 0;
    if (UP == DO || DOWN == DO || MENU == DO)
    {
        delay(50);
        if (UP == DO || DOWN == DO|| MENU == DO)
        {
            do_flag = 1;
        }
    }
    if (do_flag)
    {
        Serial.println("按下");
        if (MENU== DO)
        {
            Serial.println("菜单键");
            return_value = MENUBOTTON;
        }
        else if (UP == DO)
        {
            Serial.println("上键");
            return_value = UP_BUTTON;
        }
        else if (DOWN == DO)
        {

            Serial.println("下键");
            return_value = DOWN_BUTTON;
        }
        else
        {
            return_value = NULL_BUTTON;
        }
    }
    else
    {
        return_value = NULL_BUTTON;
    }

    return return_value;
}

#endif
