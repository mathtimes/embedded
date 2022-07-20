#include <lint.h>
#include <8052.h>

typedef unsigned char u8;
typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned long u32;
typedef unsigned long long u64;

#define swap(x, y) ((x)^=(y)^=(x)^=(y))
#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

#define beeper P2_5
#define LED P2

#define sleep(x) delay_ms(x)

void delay_ms(u16 n)
{
	for(n; n>0; n--)
		for(u16 y=114; y>0; y--);
}
