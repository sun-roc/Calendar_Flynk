#ifndef _LUNAR_H
#define _LUNAR_H
#include "Arduino.h"
//非必要库
#include "Character.h"
#include <time.h>

unsigned int LunarCalendarDay;
int MonthAdd[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
//入参为年月日,出参为对应节气的序号
unsigned char Get_SolarTerm(int Year, int Month, int Day)
{
    unsigned char temp, no_year;
    unsigned int addr;
    no_year = Year - 2000;
    addr = no_year * 12 + Month - 1;
    if (Day < 15)
    {
        temp = 15 - Day;
        if ((SolarTerms_Table[addr] >> 4) == temp)
            return (Month * 2 - 1);
        else
            return (0);
    }
    if (Day == 15)
        return (0);
    if (Day > 15)
    {
        temp = Day - 15;
        if ((SolarTerms_Table[addr] & 0x0f) == temp)
            return (Month * 2);
        else
            return (0);
    }
}
int Loop_Lunar(int year, int month, int day)
{
    unsigned char solar = Get_SolarTerm(year,month,day);//获得节气序号
    
    int Spring_NY, Sun_NY, StaticDayCount;
    int index, flag;
    //Spring_NY 记录春节离当年元旦的天数。
    //Sun_NY 记录阳历日离当年元旦的天数。
    if (((LunarCalendarTable[year - 1901] & 0x0060) >> 5) == 1)
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1;
    else
        Spring_NY = (LunarCalendarTable[year - 1901] & 0x001F) - 1 + 31;
    Sun_NY = MonthAdd[month - 1] + day - 1;
    if ((!(year % 4)) && (month > 2))

        Sun_NY++;
    //StaticDayCount记录大小月的天数 29 或30
    //index 记录从哪个月开始来计算。
    //flag 是用来对闰月的特殊处理。
    //判断阳历日在春节前还是春节后
    if (Sun_NY >= Spring_NY) //阳历日在春节后（含春节那天）

    {
        Sun_NY -= Spring_NY;
        month = 1;
        index = 1;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Sun_NY >= StaticDayCount)
        {
            Sun_NY -= StaticDayCount;
            index++;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
            {
                flag = ~flag;
                if (flag == 0)
                    month++;
            }
            else
                month++;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = Sun_NY + 1;
    }
    else //阳历日在春节前
    {
        Spring_NY -= Sun_NY;
        year--;
        month = 12;
        if (((LunarCalendarTable[year - 1901] & 0xF00000) >> 20) == 0)
            index = 12;
        else
            index = 13;
        flag = 0;
        if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
            StaticDayCount = 29;
        else
            StaticDayCount = 30;
        while (Spring_NY > StaticDayCount)
        {
            Spring_NY -= StaticDayCount;
            index--;
            if (flag == 0)
                month--;
            if (month == ((LunarCalendarTable[year - 1901] & 0xF00000) >> 20))
                flag = ~flag;
            if ((LunarCalendarTable[year - 1901] & (0x80000 >> (index - 1))) == 0)
                StaticDayCount = 29;
            else
                StaticDayCount = 30;
        }
        day = StaticDayCount - Spring_NY + 1;
    }
    Serial.print("solar:");
    Serial.println(solar);
    Draw_Lunar(year,month,day,solar,set_week);//去显示年月日 星期
}


#endif