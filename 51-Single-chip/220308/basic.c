#include "../51std.h"
int main()
{
	TMOD = 1;	//选择为定时器1模式，工作方式1，仅用TR0打开启动。
	
	//给定时器赋初值，定时1ms
	TH0 = 0xfc;
	TL0 = 0x66;
	
	ET0 = 1;	//打开定时器0中断允许
	EA = 1;		//打开总中断
	
	TR0 = 1;	//打开定时器	
	while(1);
}
void TimerCallback() __interrupt(1)
{
	//static u16 i = 0;
	TH0 = 0xfc;
	TL0 = 0x66;
	if(!P3_1)
		beeper = !beeper;
	//i++;
	/*if(i == 1000)
	{
		i = 0;
		P1_0 = !P1_0;
		P0_0 = !P0_0;
	}*/
}