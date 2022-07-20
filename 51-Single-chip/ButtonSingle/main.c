#include "../51std.h"
//#define k1 P3_1
void main()
{
	while(1)
	{
		//LED = k1;
		LED = ((P3&2)>>1)+((P3&1)<<1) + ((P3|0b11110000)&0b11111100);
	}			//交换低两位					取高两位
}