#ifndef _LUNAR_H
#define _LUNAR_H
#include "Arduino.h"
//非必要库
// #include "Character.h"
// #include "Timer.h"

// unsigned int LunarCalendarDay;
unsigned char Get_SolarTerm(uint16_t Year, uint8_t Month, uint8_t Day)
{
   
    // unsigned char temp, no_year;
    // int addr;
    // uint8_t solar_value = 0;
    // no_year = Year - 2010;
    // addr = no_year * 12 + Month - 1;

    // if (Day < 15)
    // {
    //     temp = 15 - Day;
    //     if ((SolarTerms_Table[addr] >> 4) == temp)
    //         return (Month * 2 - 1);
    //     else
    //         return (0);
    // }
    // if (Day == 15)
    //     return (0);
    // if (Day > 15)
    // {
    //     temp = Day - 15;
    //     if ((SolarTerms_Table[addr] & 0x0f) == temp)
    //         return (Month * 2);
    //     else
    //         return (0);
    // }
}



void Loop_Lunar()
{
    uint16_t year = set_year;
    uint8_t month = set_month;
    uint8_t day = set_day;
    uint8_t week = set_week;

    // unsigned char solar = Get_SolarTerm(year, month, day); //获得节气序号

    uint16_t Spring_NY;
    uint16_t Sun_NY;
    uint16_t StaticDayCount;
    uint16_t index;
    uint16_t flag;

    
    Serial.println("solar:");

}

#endif