#include "51std.h"
#include "51io.h"
#include "51cal.h"
u32 seconds = 0;
void main()
{
	beep(500);  //2s
	u8 source[8] = {0b01110110, 0b01111001, 0b00111000, 0b00111000, 0b00111111, 0b10000010, 0, 0};
	for(u16 i=0;i<58*4;i++)  //2s
		Print(source);

	TMOD = 1;	//选择为定时器1模式，工作方式1，仅用TR0打开启动。
	//给定时器赋初值，定时1ms
	TH0 = 0xfc;
	TL0 = 0x66;
	ET0 = 1;	//打开定时器0中断允许
	EA = 1;		//打开总中断
	TR0 = 1;	//打开定时器	
	while(1)
		PrintDec(seconds);
}
void TimerCallback() __interrupt(1)
{
	static u16 i = 0;
	TH0 = 0xfc;
	TL0 = 0x66;
	i++;
	seconds ++;
	if(i == 1000)
	{
		i = 0;
		seconds ++;
	}
}
