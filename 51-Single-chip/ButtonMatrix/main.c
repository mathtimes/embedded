#include "../51std.h"
__code u8 nums[17] = 
{	
	0x3f,0x06,0x5b,0x4f,
	0x66,0x6d,0x7d,0x07,
	0x7f,0x6f,0x77,0x7c,
	0x39,0x5e,0x79,0x71,
	0xff
};
u8 i;

u8 scan()
{//必须使用0扫描，而不是1
	u8 i = 0;
	for(P1 = 0x7f;i<4;P1=~(1<<(7-i)))
	{
		switch(P1&0b1111)
		{
			case 0b0111:
				return i*4 + 0;
			case 0b1011:
				return i*4 + 1;
			case 0b1101:
				return i*4 + 2;
			case 0b1110:
				return i*4 + 3;
		}
		i++;	
	}
	return 16;//默认显示 8.
}

void main()
{
	while(1)
	{
		P0 = nums[scan()];
	}
}