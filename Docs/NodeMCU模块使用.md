

# NodeMCU模块使用



# SSD IIC 12864显示屏

>https://blog.bbskali.cn/index.php/archives/1276/
>
>https://github.com/larryli/u8g2_wqy/wiki
>
>https://blog.csdn.net/dpjcn1990/article/details/92831760
>
>https://blog.csdn.net/dpjcn1990/article/details/92831840
>
>https://www.arduino.cn/thread-42174-1-1.html

```c
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif



U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ D2, /* data=*/ D1, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display
//用于定义OLED屏幕信息

void setup(void) {
  u8g2.begin();  //初始化屏幕
  u8g2.enableUTF8Print();        // enable UTF8 support for the Arduino print() function
}

void loop(void) {
  u8g2.setFont(u8g2_font_wqy15_t_chinese3);  // 设置字体
  u8g2.setFontDirection(0);
  u8g2.clearBuffer(); //清除缓存
  u8g2.setCursor(0, 15);
  u8g2.print("ENGLISH");
  u8g2.setCursor(0, 30);
  u8g2.print("中文");        // Chinese "Hello World" 
  u8g2.setCursor(0, 45);
  u8g2.print("kali黑客教学");  
  
  u8g2.sendBuffer();//显示
  
  delay(1000);
}
```

```c
u8g2_font_wqy16_t_gb2312a//大部分中文字库
u8g2_font_wqy15_t_gb2312a//高度不同,具体见github,可以直接调用,就是站的内存比较多
```

# 万年历API

这个要用https请求,安装`WiFiClientSecure`库

https://www.mxnzp.com/api/holiday/single/20181121?app_id=gpgmvui7snbkrfvx&app_secret=M0RmS0cveWxJb3AxbjlYWkxQNTFHZz09

- **date：** 当前日期
- **weekDay：** 当前周第几天 1-周一 2-周二 ... 7-周日
- **yearTips：** 天干地支纪年法描述 例如：戊戌
- **type：** 类型 0 工作日 1 假日 2 节假日
- **typeDes：** 类型描述 比如 国庆,休息日,工作日
- **chineseZodiac：** 属相 例如：狗
- **solarTerms：** 节气描述 例如：小雪
- **lunarCalendar：** 农历日期
- **suit：** 宜事项
- **dayOfYear：** 这一年的第几天
- **weekOfYear：** 这一年的第几周
- **constellation：** 星座
- **indexWorkDayOfMonth：** 如果当前是工作日 则返回是当前月的第几个工作日，否则返回0

```c
{
    "code": 1,
    "msg": "数据返回成功",
    "data": {
        "date": "2018-11-21",
        "weekDay": 3,
        "yearTips": "戊戌",
        "type": 0,
        "typeDes": "工作日",
        "chineseZodiac": "狗",
        "solarTerms": "立冬后",
        "avoid": "嫁娶.安葬",
        "lunarCalendar": "十月十四",
        "suit": "破屋.坏垣.祭祀.余事勿取",
        "dayOfYear": 325,
        "weekOfYear": 47,
        "constellation": "天蝎座",
        "indexWorkDayOfMonth": 1
    }
}
```

##	另一个API

http://api.djapi.cn/wannianli/get?date=&cn_to_unicode=0&token=5906fddcc7591fe7d3ce5d5403def99a

# DS1302

>时钟库:https://github.com/Makuna/Rtc/wiki/RtcDateTime-object
>
>安装库自己找IDE历程demo即可

# C语言函数作为参数

```c
#include <stdio.h>

#define YES 1
#define NO 0

///*判断函数，进行元素大小判断，increase判断大小比较*/
int compare(int a, int b, int increase)
{
	if (increase > 0) {
		if (a > b) return YES;
		else return NO;
	}
	else
	{
		if (a < b)  return YES;
		else return NO;
	}
}
/*冒泡排序进行数组排序*/
void OrderArr(int arry[], int(*compare)(int, int, int), int length, int increase = 1)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (compare(*(arry + j), *(arry + j + 1), increase))
			{
				int temp = *(arry + j + 1);
				*(arry + j + 1) = *(arry + j);
				*(arry + j) = temp;
			}
		}
	}
}

/*输出函数*/
void Print(int a[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", *(a + i));
	}
	printf("\n");
}

int main()
{
	int a[5] = { 1, 4, 2, 6, 3 };
	//增序排列数组
	OrderArr(a, compare, 5);
	Print(a, 5);
	//降序排列数组
	OrderArr(a, compare, 5, -1);
	Print(a, 5);
}
```

