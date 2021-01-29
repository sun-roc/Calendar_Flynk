

#define BLINKER_WIFI
#include <Blinker.h>
#include "OLED.h"
#include "Weather.h"
#include "Link.h"
#include "Timer.h"
#include "Temperature.h"
#include "Fire.h"
// #include"Lunar.h"

void setup()
{
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    Draw_Open();
    Set_MyLink();
    Set_Timer();
    Set_Temp();

}

void loop()
{
    Blinker.run();
    u8g2.clearBuffer();                                    // 清除缓冲区记忆
    Loop_Time();
    Loop_Temp();
    Loop_Fire();
    u8g2.sendBuffer();
}
